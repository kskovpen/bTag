#!/bin/env zsh

tagger="CSV"
finLOOSE="results/SF_LOOSE_2011FINALCSV_beauty.tex"
finMEDIUM="results/SF_MEDIUM_2011FINALCSV_beauty.tex"
finTIGHT="results/SF_TIGHT_2011FINALCSV_beauty.tex"

root -l -b convertSF.C\(\""${tagger}"\",\""${finLOOSE}"\",\""${finMEDIUM}"\",\""${finTIGHT}"\"\)

tagger="TCHP"
finLOOSE=""
finMEDIUM=""
finTIGHT="results/SF_TIGHT_2011FINALTCHP_beauty.tex"

root -l -b convertSF.C\(\""${tagger}"\",\""${finLOOSE}"\",\""${finMEDIUM}"\",\""${finTIGHT}"\"\)
