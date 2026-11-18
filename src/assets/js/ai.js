// Built-in AI (Summarizer + Prompt API): toggles that swap content with an AI summary or explanation.
// Buttons appear only where the browser can run the model; nothing is sent off the device.
import { $, marked } from './core.js';
import { Tooltip } from './ui.js';

// Browsers do not list 'vi' as a supported language yet, so sessions declare 'en'
// and the instructions ask for Vietnamese output (verified to work in Edge).
const AI_VERSION = 3; // bump when prompts change: invalidates answers cached in localStorage
const SUMMARY_OPTIONS = {
  type: 'key-points', format: 'markdown', length: 'medium', outputLanguage: 'en',
  sharedContext: 'C++ OOP course notes for first-year students. Write summary in Vietnamese. Simple words. No emoji. No icon. No arrow symbol.',
};
const PROMPT_OPTIONS = {
  expectedInputs: [{ type: 'text', languages: ['en'] }],
  expectedOutputs: [{ type: 'text', languages: ['en'] }],
  initialPrompts: [{
    role: 'system',
    content: 'You are OOP (Object-Oriented Programming) tutor for Vietnamese first-year IT students. Must reply in simple Vietnamese, except code names and technical terms. Plain Markdown. Never use emoji or arrow characters.',
  }],
};
// Labels are given in Vietnamese: the model copies whatever labels the prompt names.
const EXPLAIN_ASK = 'Use task and code above. Explain solution in max 5 short bullets with these labels: '
  + '"Ý tưởng chính", "Lớp và hàm chính", "Khái niệm OOP". Only say what code does. Only name OOP concepts code really uses. '
  + 'Add one simple Mermaid diagram (flowchart, sequenceDiagram, classDiagram or erDiagram) in a ```mermaid block to illustrate the solution if necessary.'
  + 'No style, no classDef, no color. All words in Vietnamese except code names. No emoji. No arrow symbol.';
// Safety net: small models still slip emoji and arrow symbols into prose. Mermaid's ASCII arrows (-->) are untouched.
const NO_EMOJI = /[\p{Extended_Pictographic}\u{FE0F}\u{20E3}]/gu;
const ARROW = /\s*[←-⇿➡➔-➿⬅-⬇]\s*/gu;
const clean = (t) => t.replace(NO_EMOJI, '').replace(ARROW, ': ');

const AI = { summarize: ['Summarizer', SUMMARY_OPTIONS], explain: ['LanguageModel', PROMPT_OPTIONS] };
const availability = Object.fromEntries(Object.entries(AI).map(([kind, [api, opts]]) => [kind,
  api in self ? self[api].availability(opts).catch(() => 'unavailable') : Promise.resolve('unavailable')]));

// One session per API for the page's lifetime: created ahead of time when the model is already
// on the device (no download, no user gesture needed), destroyed when the page is left.
let sessions = {};
const getSession = (kind, monitor) => {
  sessions[kind] ??= self[AI[kind][0]].create({ ...AI[kind][1], monitor }).catch((e) => { delete sessions[kind]; throw e; });
  return sessions[kind];
};
addEventListener('pagehide', () => {
  for (const s of Object.values(sessions)) s.then((x) => x.destroy(), () => {});
  sessions = {};
});
addEventListener('pageshow', (e) => { if (e.persisted) revealAI(); }); // back/forward cache: warm up again

// Show AI buttons this browser can run, and pre-create sessions for the ones on this page.
export async function revealAI() {
  for (const kind of Object.keys(AI)) {
    const state = await availability[kind];
    const buttons = document.querySelectorAll(`[data-ai="${kind}"]`);
    if (state === 'unavailable' || !buttons.length) continue;
    buttons.forEach((b) => { b.hidden = false; });
    if (state === 'available') getSession(kind).catch(() => {});
  }
}

const getCached = (k) => { try { return localStorage.getItem(`ai:${AI_VERSION}:${k}`); } catch { return null; } };
const setCached = (k, v) => { try { localStorage.setItem(`ai:${AI_VERSION}:${k}`, v); } catch {} };

// Mermaid is large, so it is imported only when an answer contains a diagram.
async function renderDiagrams(box) {
  const nodes = [...box.querySelectorAll('pre.mermaid')];
  if (!nodes.length) return;
  for (const n of nodes) { // "no styling" is enforced here too, whatever the model wrote
    n.textContent = n.textContent.split('\n').filter((l) => !/^\s*(style|classDef|linkStyle|%%)/.test(l)).join('\n').replace(/:::\w+/g, '');
  }
  try {
    const { default: mermaid } = await import('https://cdn.jsdelivr.net/npm/mermaid@11.12.1/dist/mermaid.esm.min.mjs');
    mermaid.initialize({ startOnLoad: false, securityLevel: 'strict', theme: document.documentElement.dataset.bsTheme === 'dark' ? 'dark' : 'neutral' });
    await mermaid.run({ nodes, suppressErrors: true });
  } catch {}
  nodes.filter((n) => !n.querySelector('svg')).forEach((n) => n.remove()); // drop diagrams the model got wrong
}

const show = async (box, markdown) => {
  box.innerHTML = marked.parse(markdown);
  box.dataset.state = 'done';
  await renderDiagrams(box);
};

// Streams an AI answer into `box`, then caches it. `start(monitor)` resolves to a text stream.
async function runAI(box, cacheKey, start) {
  box.dataset.state = 'running';
  box.setAttribute('aria-busy', 'true');
  box.textContent = 'Đang chuẩn bị…';
  const monitor = (m) => m.addEventListener('downloadprogress', (e) => { box.textContent = `Đang tải mô hình AI… ${Math.round(e.loaded * 100)}%`; });
  try {
    let text = '';
    for await (const chunk of await start(monitor)) {
      text = clean(text + chunk);
      box.innerHTML = marked.parse(text);
    }
    await show(box, text);
    setCached(cacheKey, text);
  } catch (e) {
    // A failed create() does not cancel a model download; the browser keeps managing it.
    box.dataset.state = 'error';
    box.textContent = `Không chạy được AI (${e.name}). Bấm lại để thử lại.`;
  } finally {
    box.removeAttribute('aria-busy');
  }
}

// AI buttons are toggles: they swap the original content (statement, guide or code) with the AI view
// in the same place. Answers are generated once, cached, and shown instantly afterwards.
document.addEventListener('click', (e) => {
  const btn = e.target.closest('[data-ai]');
  if (!btn) return;
  Tooltip?.getInstance(btn)?.hide();
  const summarize = btn.dataset.ai === 'summarize';
  const figure = btn.closest('figure');
  const target = summarize ? $(btn.dataset.target) : figure.querySelector('pre');
  const on = btn.getAttribute('aria-pressed') !== 'true';
  btn.setAttribute('aria-pressed', on);
  btn.classList.toggle('active', on);
  target.hidden = on;

  let box = target.nextElementSibling?.classList.contains('ai-output') ? target.nextElementSibling : null;
  if (box) box.hidden = !on;
  if (!on || ['running', 'done'].includes(box?.dataset.state)) return;
  if (!box) {
    box = document.createElement('div');
    box.className = `ai-output prose${summarize ? '' : ' p-3 pt-5 border rounded-3 bg-body-tertiary'}`;
    target.after(box);
  }
  const cacheKey = `${btn.dataset.ai}:${location.search || 'home'}:${summarize ? btn.dataset.target : btn.closest('.tab-pane').id}`;
  const cached = getCached(cacheKey);
  if (cached) { show(box, cached); return; }

  if (summarize) {
    runAI(box, cacheKey, async (monitor) => (await getSession('summarize', monitor)).summarizeStreaming(target.innerText));
  } else {
    const statement = (btn.closest('.tab-pane').querySelector(':scope > .prose') ?? $('#de-bai > .prose')).innerText;
    const code = figure.querySelector('code').textContent;
    runAI(box, cacheKey, async (monitor) => {
      const session = await (await getSession('explain', monitor)).clone(); // fresh context, same system prompt
      const stream = session.promptStreaming(`Task:\n${statement}\n\nC++ solution:\n\`\`\`cpp\n${code}\n\`\`\`\n\n${EXPLAIN_ASK}`);
      return (async function* () { try { yield* stream; } finally { session.destroy(); } })();
    });
  }
});
