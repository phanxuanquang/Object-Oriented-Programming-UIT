// Shared constants, small DOM helpers and the configured Markdown renderer.
import { marked } from 'https://cdn.jsdelivr.net/npm/marked@15.0.12/lib/marked.esm.min.js';
import hljs from 'https://cdn.jsdelivr.net/npm/@highlightjs/cdn-assets@11.11.1/es/core.min.js';
import cpp from 'https://cdn.jsdelivr.net/npm/@highlightjs/cdn-assets@11.11.1/es/languages/cpp.min.js';

hljs.registerLanguage('cpp', cpp);

export const SITE = 'https://phanxuanquang.github.io/Object-Oriented-Programming-UIT/';
export const REPO = 'https://github.com/phanxuanquang/Object-Oriented-Programming-UIT';
export const SITE_NAME = 'Lập trình hướng đối tượng UIT';
// Deployed: materials/ is copied next to index.html. Local (server at repo root, page at /src/): sibling folder.
export const MAT = location.pathname.includes('/src/') ? '../materials/' : 'materials/';

export const $ = (s, el = document) => el.querySelector(s);
export const esc = (s) => String(s).replace(/[&<>"']/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' })[c]);
export const icon = (name) => `<span class="material-symbols-rounded" aria-hidden="true">${name}</span>`;
export const fetchText = (path) => fetch(MAT + path).then((r) => (r.ok ? r.text() : Promise.reject(r.status)));

// C++ blocks are highlighted. Mermaid blocks stay as text until ai.js renders them into SVG.
marked.use({
  renderer: {
    code({ text, lang }) {
      if (lang === 'mermaid') return `<pre class="mermaid" tabindex="0">${esc(text)}</pre>\n`;
      const html = lang === 'cpp' ? hljs.highlight(text, { language: 'cpp' }).value : esc(text);
      return `<pre tabindex="0"><code class="hljs">${html}</code></pre>\n`;
    },
  },
});

export { marked, hljs };
