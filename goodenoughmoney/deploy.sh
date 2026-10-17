#!/usr/bin/env bash

set -e

nix run nixpkgs#hugo -- --source src
nix run nixpkgs#rsync -- -rvz src/public/ ansible@192.168.2.10:/opt/goodenoughmoney.com
