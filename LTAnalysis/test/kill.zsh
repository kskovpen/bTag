#!/bin/env zsh

plist=($(pgrep Analyzer))
for i in $plist
do
  kill ${i}
done
