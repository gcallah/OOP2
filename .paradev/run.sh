#!/usr/bin/env bash
# Paradev run: serve the static course site on a free port so parallel
# workspaces don't collide. Override with PORT=xxxx.
set -euo pipefail
cd "$(dirname "$0")/.."

pick_port() {
  local p
  for p in $(seq "${1:-8000}" 8999); do
    if ! lsof -nP -iTCP:"$p" -sTCP:LISTEN >/dev/null 2>&1; then
      echo "$p"; return 0
    fi
  done
  echo "No free port found in ${1:-8000}-8999" >&2; return 1
}

PORT="${PORT:-$(pick_port 8000)}"
echo "==> Serving ${SUPERSET_WORKSPACE_NAME:-OOP2} at http://127.0.0.1:${PORT}/"
echo $$ > .paradev/.run.pid
exec python3 -m http.server "$PORT" --bind 127.0.0.1
