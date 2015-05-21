#!/bin/env zsh

wp="MEDIUM"
btag="CSV" # CSV or TCHP
#app="2011TCHPv2"
#app="2011CSVTEST1"
#app="2011CSV_FINAL"
#app="2011FINALCSV_SYS1NEW"
app="2011FINALCSV_7"
#app="2011FINALTCHP_7"
#app="2011FINALCSV_CENTRAL"
#app="ATT_NOCOR" # MAX or TTBAR
#app="RWMAX2"
#app="BARLOW"
flav="charm"
j1="" # empty or J1

#root -l -b produceSFOFF.C\(\"${wp}\"\)
root -l -b produceSFOFF2011.C\(\"${wp}\",\"${btag}\"\)
root -l -b produceSF.C\(\"${wp}\",\"${app}\",\"${j1}\",\"${flav}\"\)
