#!/usr/bin/env bash
# Checks that the website lists every lab file:
#   - each materials/<lab>/ folder has a <li data-dir="<lab>"> in src/index.html
#   - its data-files matches the files in that folder (except the lab's own README.md)
#   - its ?lab=<lab> URL is in src/sitemap.xml
# Run locally: bash .github/check-labs.sh
set -u
cd "$(dirname "$0")/.."
fail=0
err() { echo "::error::$1"; fail=1; }

for path in materials/*/; do
  dir=$(basename "$path")
  grep -q "data-dir=\"$dir\"" src/index.html || err "materials/$dir/ is not listed in src/index.html (#labs)"
done

while IFS='|' read -r dir files; do
  [ -d "materials/$dir" ] || { err "src/index.html lists data-dir=\"$dir\" but materials/$dir/ does not exist"; continue; }
  expected=$(cd "materials/$dir" && find . -type f ! -path ./README.md | sed 's|^\./||' | sort)
  listed=$(printf '%s\n' $files | sort)
  if [ "$expected" != "$listed" ]; then
    err "data-files of $dir does not match materials/$dir/"
    diff <(echo "$listed") <(echo "$expected") | sed -n 's/^< /  listed but missing on disk: /p; s/^> /  on disk but not listed:    /p'
  fi
  slug=$(echo "$dir" | tr '[:upper:]' '[:lower:]')
  grep -q "?lab=$slug<" src/sitemap.xml || err "src/sitemap.xml is missing ?lab=$slug"
done < <(grep -o 'data-dir="[^"]*" data-files="[^"]*"' src/index.html | sed -E 's/data-dir="([^"]*)" data-files="([^"]*)"/\1|\2/')

[ $fail -eq 0 ] && echo "All labs are listed correctly."
exit $fail
