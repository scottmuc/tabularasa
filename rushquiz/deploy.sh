#!/usr/bin/env bash

set -e

rsync -rvz . ansible@192.168.2.10:/opt/home.scottmuc.com/rushquiz
