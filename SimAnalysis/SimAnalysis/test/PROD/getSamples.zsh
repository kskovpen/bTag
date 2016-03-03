#!/bin/env zsh

name="QCD*Pt_*"
tag="RunIISummer15GS-MCRUN2_71_V1-v1"

wget --no-check-certificate \
--output-document=samples.txt \
"https://cmsweb.cern.ch/das/request?view=plain&instance=prod%2Fglobal&input=dataset%3D%2F*${name}*%2F*${tag}*%2FGEN-SIM+|+sort+dataset.name"
