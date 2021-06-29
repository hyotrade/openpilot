#!/usr/bin/bash

export LD_LIBRARY_PATH=/data/data/com.termux/files/usr/lib
export HOME=/data/data/com.termux/files/home
export PATH=/usr/local/bin:/data/data/com.termux/files/usr/bin:/data/data/com.termux/files/usr/sbin:/data/data/com.termux/files/usr/bin/applets:/bin:/sbin:/vendor/bin:/system/sbin:/system/bin:/system/xbin:/data/data/com.termux/files/usr/bin/python
export PYTHONPATH=/data/openpilot

cd /data/openpilot
BRANCH=$(git rev-parse --abbrev-ref HEAD)
LOCAL_HASH=$(git rev-parse --short HEAD)
/data/data/com.termux/files/usr/bin/git fetch --all
/data/data/com.termux/files/usr/bin/git reset --hard HEAD
/data/data/com.termux/files/usr/bin/git pull
REMOTE_HASH=$(git rev-parse --short --verify origin/$BRANCH)
/data/data/com.termux/files/usr/bin/git reset --hard $REMOTE_HASH

if [ "$LOCAL_HASH" == "$REMOTE_HASH" ]; then
  reboot
fi
