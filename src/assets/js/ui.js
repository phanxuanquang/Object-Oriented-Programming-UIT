// Page-wide UI behaviour: tooltips, theme switch, copy buttons, local material links.
import { $, MAT } from './core.js';

// One delegated instance covers static and rendered [data-bs-title] elements.
export const Tooltip = window.bootstrap?.Tooltip;
Tooltip && new Tooltip(document.body, { selector: '[data-bs-title]', trigger: 'hover focus' });
export const setTip = (el, text) => {
  el.dataset.bsTitle = text;
  el.setAttribute('aria-label', text);
  Tooltip?.getInstance(el)?.setContent({ '.tooltip-inner': text });
};

// ---------- theme (initial theme is set inline in <head> to avoid flashing) ----------
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

// Static links to materials/ work on the deployed site; rewrite them for local preview.
document.querySelectorAll('[data-mat]').forEach((a) => { a.href = MAT + a.dataset.mat; });
