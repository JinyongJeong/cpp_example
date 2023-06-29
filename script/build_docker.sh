#!/bin/bash
set -euo pipefail
cd "$(dirname "$0")/.."
set -x

docker build -t development_ubuntu:latest -f docker/development.Dockerfile .
docker images development_ubuntu:latest
