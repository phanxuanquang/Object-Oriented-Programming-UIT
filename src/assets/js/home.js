// Home view: lab carousel controls and the study guide with its section index.
import { $, esc, fetchText, marked, REPO } from './core.js';
import { revealAI } from './ai.js';

export async function renderHome() {
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
  revealAI();
  // Section index for the guide, built from its h3 headings.
  $('#guide-toc').innerHTML = [...guide.querySelectorAll('h3')].map((h, k) => {
    h.id = `huong-dan-${k + 1}`;
    return `<li class="nav-item"><a class="nav-link py-1 small" href="#${h.id}">${esc(h.textContent)}</a></li>`;
  }).join('');
}
