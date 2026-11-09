#!/usr/bin/env bash
# Paradev workspace setup: fetch the utils submodule, install Python deps,
# and copy untracked local config files from the root checkout.
set -euo pipefail
cd "$(dirname "$0")/.."

echo "==> Initializing git submodules (utils/)"
git submodule update --init --recursive

echo "==> Ensuring Python dependencies (pygments, used by utils/cpp2html.py)"
if ! python3 -c 'import pygments' 2>/dev/null; then
  python3 -m pip install --user pygments \
    || python3 -m pip install --user --break-system-packages pygments \
    || echo "WARNING: could not install pygments; 'make local' code pages will fail" >&2
fi

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

echo "==> Setup complete"
