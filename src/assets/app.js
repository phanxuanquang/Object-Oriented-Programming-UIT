import { marked } from 'https://cdn.jsdelivr.net/npm/marked@15.0.12/lib/marked.esm.min.js';
import hljs from 'https://cdn.jsdelivr.net/npm/@highlightjs/cdn-assets@11.11.1/es/core.min.js';
import cpp from 'https://cdn.jsdelivr.net/npm/@highlightjs/cdn-assets@11.11.1/es/languages/cpp.min.js';

hljs.registerLanguage('cpp', cpp);

const SITE = 'https://phanxuanquang.github.io/Object-Oriented-Programming-UIT/';
const REPO = 'https://github.com/phanxuanquang/Object-Oriented-Programming-UIT';
const SITE_NAME = 'Lập trình hướng đối tượng UIT';
// Deployed: materials/ is copied next to index.html. Local (server at repo root, page at /src/): sibling folder.
const MAT = location.pathname.includes('/src/') ? '../materials/' : 'materials/';

const $ = (s, el = document) => el.querySelector(s);
const esc = (s) => String(s).replace(/[&<>"']/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' })[c]);
const icon = (name) => `<span class="material-symbols-rounded" aria-hidden="true">${name}</span>`;
const fetchText = (path) => fetch(MAT + path).then((r) => (r.ok ? r.text() : Promise.reject(r.status)));

marked.use({
  renderer: {
    code({ text, lang }) {
      const html = lang === 'cpp' ? hljs.highlight(text, { language: 'cpp' }).value : esc(text);
      return `<pre tabindex="0"><code class="hljs">${html}</code></pre>\n`;
    },
  },
});

// ---------- tooltips: one delegated instance covers static and rendered [data-bs-title] ----------
const Tooltip = window.bootstrap?.Tooltip;
Tooltip && new Tooltip(document.body, { selector: '[data-bs-title]', trigger: 'hover focus' });
const setTip = (el, text) => {
  el.dataset.bsTitle = text;
  el.setAttribute('aria-label', text);
  Tooltip?.getInstance(el)?.setContent({ '.tooltip-inner': text });
};

// ---------- theme ----------
const root = document.documentElement;
const themeBtn = $('[data-theme-toggle]');
const syncTheme = () => {
  const dark = root.dataset.bsTheme === 'dark';
  themeBtn.firstElementChild.textContent = dark ? 'light_mode' : 'dark_mode';
  setTip(themeBtn, dark ? 'Chuyển sang giao diện sáng' : 'Chuyển sang giao diện tối');
};
syncTheme();
themeBtn.addEventListener('click', () => {
  const toggle = () => {
    root.dataset.bsTheme = root.dataset.bsTheme === 'dark' ? 'light' : 'dark';
    try { localStorage.setItem('theme', root.dataset.bsTheme); } catch {}
    syncTheme();
  };
  // Animated reveal where supported; instant swap otherwise or when the user prefers less motion.
  const animate = document.startViewTransition && !matchMedia('(prefers-reduced-motion: reduce)').matches;
  Tooltip?.getInstance(themeBtn)?.hide();
  animate ? document.startViewTransition(toggle) : toggle();
});

// Follow OS light/dark changes until the user picks a theme (Bootstrap color-mode toggler pattern).
matchMedia('(prefers-color-scheme: dark)').addEventListener('change', (e) => {
  let stored = null;
  try { stored = localStorage.getItem('theme'); } catch {}
  if (!stored) { root.dataset.bsTheme = e.matches ? 'dark' : 'light'; syncTheme(); }
});

// ---------- copy buttons ----------
document.addEventListener('click', async (e) => {
  const btn = e.target.closest('[data-copy]');
  if (!btn) return;
  try {
    await navigator.clipboard.writeText(btn.closest('figure').querySelector('code').textContent);
    btn.firstElementChild.textContent = 'check';
    setTip(btn, 'Đã sao chép');
    $('#status').textContent = 'Đã sao chép mã nguồn';
    setTimeout(() => { btn.firstElementChild.textContent = 'content_copy'; setTip(btn, 'Sao chép'); }, 1500);
  } catch {}
});

document.querySelectorAll('[data-mat]').forEach((a) => { a.href = MAT + a.dataset.mat; });

// ---------- data: read from the static lab list in index.html ----------
const LABS = [...document.querySelectorAll('#labs > li')].map((li) => ({
  dir: li.dataset.dir,
  slug: li.dataset.dir.toLowerCase(),
  files: li.dataset.files.split(' '),
  title: $('h3', li).textContent,
  topic: $('a > span', li).textContent,
  desc: $('p', li).textContent,
}));

// ---------- views ----------
const slug = new URLSearchParams(location.search).get('lab');
if (slug === null) renderHome();
else renderLab(LABS.find((l) => l.slug === slug.toLowerCase()));

async function renderHome() {
  // Lab carousel: buttons scroll by one card and disable at either end.
  const track = $('#labs');
  const [prevBtn, nextBtn] = document.querySelectorAll('[data-scroll]');
  const syncButtons = () => {
    prevBtn.disabled = track.scrollLeft <= 4;
    nextBtn.disabled = track.scrollLeft + track.clientWidth >= track.scrollWidth - 4;
  };
  // Smooth scrolling comes from CSS and is only enabled when the user has no reduced-motion preference.
  for (const btn of [prevBtn, nextBtn]) {
    btn.addEventListener('click', () => track.scrollBy({ left: btn.dataset.scroll * track.firstElementChild.offsetWidth }));
  }
  track.addEventListener('scroll', syncButtons, { passive: true });
  addEventListener('resize', syncButtons);
  syncButtons();

  const guide = $('#guide');
  try {
    guide.innerHTML = marked.parse(await fetchText('GUIDE.md')).replace(/<(\/?)h2>/g, '<$1h3>');
  } catch {
    guide.innerHTML = `<p>Không tải được hướng dẫn. Xem <a href="${REPO}/blob/main/materials/GUIDE.md">GUIDE.md trên GitHub</a>.</p>`;
  }
  guide.removeAttribute('aria-busy');
  // Section index for the guide, built from its h3 headings.
  $('#guide-toc').innerHTML = [...guide.querySelectorAll('h3')].map((h, k) => {
    h.id = `huong-dan-${k + 1}`;
    return `<li class="nav-item"><a class="nav-link py-1 small" href="#${h.id}">${esc(h.textContent)}</a></li>`;
  }).join('');
}

function setMeta({ title, desc, url, noindex }) {
  document.title = title;
  const set = (sel, attr, val) => $(sel)?.setAttribute(attr, val);
  set('meta[name="description"]', 'content', desc);
  set('meta[property="og:title"]', 'content', title);
  set('meta[property="og:description"]', 'content', desc);
  set('meta[property="og:url"]', 'content', url);
  set('meta[property="og:type"]', 'content', 'article');
  set('link[rel="canonical"]', 'href', url);
  if (noindex) set('meta[name="robots"]', 'content', 'noindex');
}

async function renderLab(lab) {
  $('main.home').remove();
  $('.lab-view').hidden = false;
  $('[data-lab-only]').hidden = false;
  const main = $('#lab-main');
  main.id = 'main';

  if (!lab) {
    setMeta({ title: `Không tìm thấy bài thực hành | ${SITE_NAME}`, desc: 'Bài thực hành không tồn tại.', url: SITE, noindex: true });
    renderNav(null);
    main.innerHTML = `<div class="pb-4"><p class="small fw-semibold text-uppercase text-primary mb-2">Lỗi</p><h1 class="display-6 fw-bold">Không tìm thấy bài thực hành</h1><p class="lead text-body-secondary">Đường dẫn không đúng. Chọn một bài thực hành trong danh sách.</p><a class="btn btn-primary" href="./">Về trang chủ</a></div>`;
    return;
  }

  const url = `${SITE}?lab=${lab.slug}`;
  const desc = `Đề bài và lời giải C++ ${lab.title.toLowerCase()} môn Lập trình hướng đối tượng UIT. ${lab.desc}`;
  setMeta({ title: `${lab.title}: ${lab.topic} | Lời giải C++ | ${SITE_NAME}`, desc, url });
  addJsonLd(lab, url, desc);

  main.innerHTML = `<nav aria-label="breadcrumb"><ol class="breadcrumb small align-items-center">
      <li class="breadcrumb-item"><a class="d-inline-flex p-1 text-decoration-none" href="./" aria-label="Trang chủ" data-bs-title="Trang chủ">${icon('home')}</a></li>
      <li class="breadcrumb-item active" aria-current="page">${esc(lab.title)}</li>
    </ol></nav>
    <article>
      <header class="pb-4 mb-3 border-bottom">
        <p class="small fw-semibold text-uppercase text-primary mb-2">${esc(lab.topic)}</p>
        <h1 class="display-6 fw-bold">${esc(lab.title)}</h1>
        <p class="lead text-body-secondary mb-0">${esc(lab.desc)}</p>
      </header>
      <div id="sections" aria-busy="true"><p class="text-body-secondary py-4">Đang tải…</p></div>
    </article>`;
  renderNav(lab);

  const sources = lab.files.filter((f) => f.endsWith('.cpp'));
  let readme, codes;
  try {
    [readme, ...codes] = await Promise.all([fetchText(`${lab.dir}/README.md`), ...sources.map((f) => fetchText(`${lab.dir}/${f}`))]);
  } catch {
    $('#sections').innerHTML = `<p class="py-4">Không tải được nội dung. Xem <a href="${REPO}/tree/main/materials/${lab.dir}">thư mục trên GitHub</a>.</p>`;
    return;
  }
  const notes = await Promise.all(lab.files.filter((f) => f.endsWith('/README.md')).map(async (f) => [f, await fetchText(`${lab.dir}/${f}`).catch(() => '')]));
  const code = Object.fromEntries(sources.map((f, k) => [f, codes[k]]));
  const note = Object.fromEntries(notes);
  const numOf = (f) => Number((f.split('/').pop().match(/^(\d+)\.cpp$/) || [])[1]) || null;

  // A README that is exactly one ordered list pairs item N with solution 0N.cpp.
  const tokens = marked.lexer(readme).filter((t) => t.type !== 'space');
  const paired = tokens.length === 1 && tokens[0].type === 'list' && tokens[0].ordered;
  const sections = [];
  if (paired) {
    tokens[0].items.forEach((item, k) => {
      const src = sources.find((f) => numOf(f) === k + 1);
      sections.push({
        id: `bai-${k + 1}`, label: `Bài ${k + 1}`,
        html: `<div class="prose">${marked.parse(item.text)}</div>${src ? solution(lab, src, code[src], note) : '<p class="text-body-secondary fst-italic">Chưa có lời giải.</p>'}`,
      });
    });
  } else {
    sections.push({ id: 'de-bai', label: 'Đề bài', html: `<div class="prose">${marked.parse(readme)}</div>` });
    for (const src of sources) {
      const n = numOf(src);
      sections.push({ id: n ? `loi-giai-${n}` : 'loi-giai', label: n ? `Lời giải bài ${n}` : 'Lời giải', html: solution(lab, src, code[src], note) });
    }
  }

  // One tab per section. Panes stay in the DOM, so all content remains indexable.
  const start = Math.max(0, sections.findIndex((s) => `#${s.id}` === location.hash));
  // Numbered problems get compact number tabs behind a single 'Bài' label; other sections get icon + text.
  const tabLabel = (s) => (paired ? s.label.replace('Bài ', '') : icon(s.id === 'de-bai' ? 'description' : 'code') + s.label);
  const box = $('#sections');
  box.innerHTML = `<div class="nav nav-underline problem-tabs flex-nowrap overflow-x-auto bg-body border-bottom" role="tablist" aria-label="Các bài trong ${esc(lab.title)}">
      ${paired ? '<span class="align-self-center pe-2 small text-body-secondary" aria-hidden="true">Bài</span>' : ''}
      ${sections.map((s, k) => `<button class="nav-link d-inline-flex align-items-center gap-1${k === start ? ' active' : ''}" id="${s.id}-tab" type="button" role="tab" data-bs-toggle="tab" data-bs-target="#${s.id}" aria-controls="${s.id}" aria-selected="${k === start}"${k === start ? '' : ' tabindex="-1"'} aria-label="${s.label}">${tabLabel(s)}</button>`).join('')}
    </div>
    <div class="tab-content">
      ${sections.map((s, k) => `<section id="${s.id}" class="tab-pane pt-4 pb-3${k === start ? ' active' : ''}" role="tabpanel" aria-labelledby="${s.id}-tab" tabindex="0">
        <h2 class="visually-hidden">${s.label}</h2>${s.html}</section>`).join('')}
    </div>`;
  box.removeAttribute('aria-busy');
  // Bootstrap binds arrow-key navigation per Tab instance, so create them all up front.
  box.querySelectorAll('[role=tab]').forEach((t) => window.bootstrap?.Tab.getOrCreateInstance(t));
  box.addEventListener('shown.bs.tab', (e) => {
    history.replaceState(null, '', `#${e.target.getAttribute('aria-controls')}`);
    e.target.scrollIntoView({ block: 'nearest', inline: 'nearest' });
    // Tab bar is sticky: when the reader is deep in a long pane, jump back to the top of the new pane.
    if (box.getBoundingClientRect().top < 0) box.scrollIntoView();
  });
  $(`#${sections[start].id}-tab`).scrollIntoView({ block: 'nearest', inline: 'nearest' });
}

function solution(lab, file, src, notes) {
  const name = file.split('/').pop();
  const dir = file.replace(/[^/]*$/, '');
  const path = `${lab.dir}/${file}`;
  const audio = dir ? lab.files.filter((f) => f.startsWith(dir) && f.endsWith('.wav')) : [];
  const note = dir && notes[`${dir}README.md`];
  return `<figure class="position-relative mt-4 mb-0" aria-label="Lời giải ${esc(name)}">
      <span class="position-absolute top-0 end-0 m-2 p-1 d-flex gap-1 rounded-2 bg-body-tertiary">
        <button class="btn btn-icon btn-sm" type="button" data-copy aria-label="Sao chép mã nguồn" data-bs-title="Sao chép">${icon('content_copy')}</button>
        <a class="btn btn-icon btn-sm" href="${MAT}${path}" download aria-label="Tải ${esc(name)}" data-bs-title="Tải xuống">${icon('download')}</a>
        <a class="btn btn-icon btn-sm" href="${REPO}/blob/main/materials/${path}" rel="noopener" aria-label="Xem ${esc(name)} trên GitHub" data-bs-title="Xem trên GitHub">${icon('open_in_new')}</a>
      </span>
    <pre class="mb-0" tabindex="0"><code class="hljs language-cpp">${hljs.highlight(src.replace(/\r\n?/g, '\n'), { language: 'cpp' }).value}</code></pre>
  </figure>
  ${note ? `<aside class="note mt-3 p-3 bg-body-secondary rounded-3 small" aria-label="Hướng dẫn chạy">${marked.parse(note)}</aside>` : ''}
  ${audio.length ? `<ul class="list-unstyled d-flex flex-wrap gap-3 mt-3">${audio.map((f) => `<li class="d-flex flex-column gap-1 small text-body-secondary"><span>${esc(f.split('/').pop())}</span><audio controls preload="none" src="${MAT}${lab.dir}/${f}"></audio></li>`).join('')}</ul>` : ''}`;
}

function renderNav(current) {
  $('#lab-nav').innerHTML = LABS.map((l) => `<li class="nav-item">
    <a class="nav-link small${l === current ? ' active' : ''}" href="?lab=${l.slug}"${l === current ? ' aria-current="page"' : ''} data-bs-title="${esc(l.topic)}" data-bs-placement="right">${esc(l.title)}</a>
  </li>`).join('');
}

function addJsonLd(lab, url, desc) {
  const s = document.createElement('script');
  s.type = 'application/ld+json';
  s.textContent = JSON.stringify({
    '@context': 'https://schema.org',
    '@graph': [
      {
        '@type': 'LearningResource', name: `${lab.title}: ${lab.topic}`, description: desc, url, inLanguage: 'vi',
        learningResourceType: 'Bài tập có lời giải', educationalLevel: 'Đại học', teaches: lab.topic,
        author: { '@type': 'Person', name: 'Phan Xuân Quang' },
        isPartOf: { '@type': 'Course', name: SITE_NAME, url: SITE },
      },
      {
        '@type': 'BreadcrumbList', itemListElement: [
          { '@type': 'ListItem', position: 1, name: 'Trang chủ', item: SITE },
          { '@type': 'ListItem', position: 2, name: lab.title, item: url },
        ],
      },
    ],
  });
  document.head.append(s);
}
