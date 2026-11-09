#!/usr/bin/env bash
# Paradev workspace setup: fetch the utils submodule, install Python deps,
# and copy untracked local config files from the root checkout.
set -euo pipefail
cd "$(dirname "$0")/.."

echo "==> Initializing git submodules (utils/)"
git submodule update --init --recursive

echo "==> Creating .venv with build dependencies"
# utils/cpp2html.py subclasses a pygments formatter using the pre-2.12 API,
# so pygments >= 2.12 breaks 'make local'; < 2.9 also matches the markup
# already committed (no whitespace spans). Keep a pinned copy in .venv.
if [ ! -x .venv/bin/python3 ]; then
  python3 -m venv .venv
fi
.venv/bin/python3 -m pip install --quiet --disable-pip-version-check 'pygments<2.9' \
  || echo "WARNING: could not install pygments into .venv; 'make local' will fail" >&2

echo "==> Copying untracked local files from root repo"
if [ -n "${SUPERSET_ROOT_PATH:-}" ] && [ "$SUPERSET_ROOT_PATH" != "$PWD" ]; then
  for f in .env .env.local .paradev/config.local.json; do
    if [ -f "$SUPERSET_ROOT_PATH/$f" ] && [ ! -e "$f" ]; then
      mkdir -p "$(dirname "$f")"
      cp "$SUPERSET_ROOT_PATH/$f" "$f"
      echo "    copied $f"
    fi
  done
fi

echo '==> Setup complete. Build the site with: PATH="$PWD/.venv/bin:$PATH" make local'
