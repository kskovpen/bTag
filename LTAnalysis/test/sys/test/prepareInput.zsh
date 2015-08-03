#!/bin/env zsh

rm -rf ../../histCFIT
mkdir ../../histCFIT
cp -r ../../histSYS/MC ../../histCFIT/.
cp -r ../../histSYS/DATA ../../histCFIT/.

root -l -b adjustData.C
hadd -f ../../histCFIT/data.root ../../histCFIT/MC/data.root ../../histCFIT/DATA/data.root
