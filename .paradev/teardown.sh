#!/usr/bin/env bash
# Paradev teardown: stop the dev server started by run.sh, if still running.
set -uo pipefail
cd "$(dirname "$0")/.."

PIDFILE=.paradev/.run.pid
if [ -f "$PIDFILE" ]; then
  pid="$(cat "$PIDFILE")"
  if kill -0 "$pid" 2>/dev/null; then
    echo "==> Stopping dev server (pid $pid)"
    kill "$pid" 2>/dev/null || true
  fi
  rm -f "$PIDFILE"
fi
exit 0
