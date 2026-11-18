// Entry point: reads the lab list from index.html and renders the view for the current URL.
import { $ } from './core.js';
import './ui.js';
import { renderHome } from './home.js';
import { renderLab } from './lab.js';

// Single source of truth: the static lab cards in index.html (also what crawlers see).
const labs = [...document.querySelectorAll('#labs > li')].map((li) => ({
  dir: li.dataset.dir,
  slug: li.dataset.dir.toLowerCase(),
  files: li.dataset.files.split(' '),
  title: $('h3', li).textContent,
  topic: $('a > span', li).textContent,
  desc: $('p', li).textContent,
}));

const slug = new URLSearchParams(location.search).get('lab');
if (slug === null) renderHome();
else renderLab(labs.find((l) => l.slug === slug.toLowerCase()), labs);
