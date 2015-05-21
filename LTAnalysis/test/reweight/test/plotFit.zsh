#!/bin/env zsh

tag="noseltag"

#tag1="noselsv0tag"
tag1="noseltag"
#tag1="sv0tag"
#tag2="jetfittercombnnc1p10tag"
#tag2="jetfittercombnnc0p65tag"
#tag2="jetfittercombnncm0p95tag"
#tag2="jetfittercombnncm2p60tag"
#tag2="mv1c0p985tag"
###tag2="mv1c0p0616tag"

#tag2="mv1c0p3900"
#tag2="mv1c0p8119"
tag2="combSvx0p679"

###tag2="mv1c0p9925154"
#tag2="mv1c0p795tag"
#tag2="mv1c0p596tag"
#tag2="mv1c0p148tag"
#tag2="sv0pc5p65tag"
#tag2="sv0tag"

# for fit scale factor & flavour composition
#fit="2DIMfit"
#fit="3DIMfit"
#fit="nofit2d"
fit="1dfit"
#fit="1dFITCL"
#varn="h_j1_vBTsv0p_"
#varn="h_j1_d0SignJet3_"
#varn="h_j1_d0SignJet3_"
varn="h_j1_JP_"
###varn="h_j1_d0SignJet1SV_"
###varn="h_j1_muonTightPtRel_"
###varn="h_j1_muonTightPtRelSV_"
###varn="h_j1_d0SignMuonTight_"
#varn="h_j1_d0SignJetMuonTight_"
#varn="h_j1_wJetProb_"

# for FIT1 vs FIT2
fit1="1dfit"
fit2="1dfit"
varn1=${varn}
varn2=${varn}
fit1tit="B^{T} vs #Pi^{T}"
fit2tit="#Pi^{T}"

# for FIT1 vs FIT2 vs FIT3
fit1="1dfit"
fit2="1dfit"
fit3="1dfit"
varn1=${varn}
varn2=${varn}
varn3=${varn}
fit1tit="B^{T} vs #Pi^{T}"
fit2tit="#Pi^{T}"
fit3tit="B^{T}"

#sysOpt="JESdown"
sysOpt="NONE"
#sysOpt="ALL"
fin="results/eff${sysOpt}.txt"

ptbin=("pt20t30" "pt30t40" "pt40t50" \
"pt50t60" "pt60t70" "pt70t80" "pt80t100" \
"pt100t120" "pt120t160" "pt160t210" \
"pt210t260" "pt260t320" "pt320t400" \
"pt400t500" "pt500t600" "pt600t800" \
"pt800t1000")

p0=""
p1=""
p2=""

p0err=""
p1err=""
p2err=""

i=0
for ib in $ptbin
do

lineALL=$(LC_ALL=C egrep "${tag1}.*${ib}.*${fit}.*${varn}" $fin)
lineALL2=$(LC_ALL=C egrep "${tag2}.*${ib}.*${fit}.*${varn}" $fin)

lineF1=$(LC_ALL=C egrep "${tag1}.*${ib}.*${fit1}.*${varn1}" $fin)
lineF2=$(LC_ALL=C egrep "${tag1}.*${ib}.*${fit2}.*${varn2}" $fin)
lineF3=$(LC_ALL=C egrep "${tag1}.*${ib}.*${fit3}.*${varn3}" $fin)

lineF1BTAG=$(LC_ALL=C egrep "${tag2}.*${ib}.*${fit1}.*${varn1}" $fin)
lineF2BTAG=$(LC_ALL=C egrep "${tag2}.*${ib}.*${fit2}.*${varn2}" $fin)
lineF3BTAG=$(LC_ALL=C egrep "${tag2}.*${ib}.*${fit3}.*${varn3}" $fin)

lineTAG1=$(LC_ALL=C egrep "${tag1}.*${ib}.*${fit}.*${varn}" $fin)
lineTAG2=$(LC_ALL=C egrep "${tag2}.*${ib}.*${fit}.*${varn}" $fin)

if [[ $i == 0 ]]; then
dl=""
else
dl=","
fi

ptb1=$ptb1$dl$(echo $ib | sed 's\pt\\g' | tr 't' ' ' | awk '{print $1;}')
ptb2=$ptb2$dl$(echo $ib | sed 's\pt\\g' | tr 't' ' ' | awk '{print $2;}')

usePRETAGb=$(echo $lineTAG1 | awk '{print $22;}')
usePRETAGc=$(echo $lineTAG1 | awk '{print $23;}')
fr1=$fr1$dl$(echo $lineTAG1 | awk '{print $24;}')
fr2=$fr2$dl$(echo $lineTAG2 | awk '{print $24;}')

# fit scale factor before b-tagging
##p0=$p0$dl$(echo $lineTAG1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
##p0err=$p0err$dl$(echo $lineTAG1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
##p1=$p1$dl$(echo $lineTAG1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
##p1err=$p1err$dl$(echo $lineTAG1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
##p2=$p2$dl$(echo $lineTAG1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
##p2err=$p2err$dl$(echo $lineTAG1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# flavour composition for tag1 selection (unfit)
##eff0=$eff0$dl$(echo $lineALL | awk '{print $10;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff0err=$eff0err$dl$(echo $lineALL | awk '{print $10;}' | tr 'pm' ' ' | awk '{print $2;}')
##eff1=$eff1$dl$(echo $lineALL | awk '{print $11;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff1err=$eff1err$dl$(echo $lineALL | awk '{print $11;}' | tr 'pm' ' ' | awk '{print $2;}')
##eff2=$eff2$dl$(echo $lineALL | awk '{print $12;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff2err=$eff2err$dl$(echo $lineALL | awk '{print $12;}' | tr 'pm' ' ' | awk '{print $2;}')

# flavour composition for tag2 selection (unfit)
##eff0tag2=$eff0tag2$dl$(echo $lineALL2 | awk '{print $10;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff0errtag2=$eff0errtag2$dl$(echo $lineALL2 | awk '{print $10;}' | tr 'pm' ' ' | awk '{print $2;}')
##eff1tag2=$eff1tag2$dl$(echo $lineALL2 | awk '{print $11;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff1errtag2=$eff1errtag2$dl$(echo $lineALL2 | awk '{print $11;}' | tr 'pm' ' ' | awk '{print $2;}')
##eff2tag2=$eff2tag2$dl$(echo $lineALL2 | awk '{print $12;}' | tr 'pm' ' ' | awk '{print $1;}')
##eff2errtag2=$eff2errtag2$dl$(echo $lineALL2 | awk '{print $12;}' | tr 'pm' ' ' | awk '{print $2;}')

# flavour composition before b-tagging (fit)
eff0b1=$eff0b1$dl$(echo $lineTAG1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
eff0errb1=$eff0errb1$dl$(echo $lineTAG1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
eff1b1=$eff1b1$dl$(echo $lineTAG1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
eff1errb1=$eff1errb1$dl$(echo $lineTAG1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
eff2b1=$eff2b1$dl$(echo $lineTAG1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
eff2errb1=$eff2errb1$dl$(echo $lineTAG1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')
n0b1=$n0b1$dl$(echo $lineTAG1 | awk '{print $16;}' | tr 'pm' ' ' | awk '{print $1;}')
n0errb1=$n0errb1$dl$(echo $lineTAG1 | awk '{print $16;}' | tr 'pm' ' ' | awk '{print $2;}')
n1b1=$n1b1$dl$(echo $lineTAG1 | awk '{print $17;}' | tr 'pm' ' ' | awk '{print $1;}')
n1errb1=$n1errb1$dl$(echo $lineTAG1 | awk '{print $17;}' | tr 'pm' ' ' | awk '{print $2;}')
n2b1=$n2b1$dl$(echo $lineTAG1 | awk '{print $18;}' | tr 'pm' ' ' | awk '{print $1;}')
n2errb1=$n2errb1$dl$(echo $lineTAG1 | awk '{print $18;}' | tr 'pm' ' ' | awk '{print $2;}')
#n0b1=$n0b1$dl$(echo $lineTAG1 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $1;}')
#n0errb1=$n0errb1$dl$(echo $lineTAG1 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $2;}')
#n1b1=$n1b1$dl$(echo $lineTAG1 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $1;}')
#n1errb1=$n1errb1$dl$(echo $lineTAG1 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $2;}')
#n2b1=$n2b1$dl$(echo $lineTAG1 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $1;}')
#n2errb1=$n2errb1$dl$(echo $lineTAG1 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $2;}')

# integrals of flavour composition before b-tagging (fit)
##i0b1=$i0b1$dl$(echo $lineTAG1 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $1;}')
##i0errb1=$i0errb1$dl$(echo $lineTAG1 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $2;}')
##i1b1=$i1b1$dl$(echo $lineTAG1 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $1;}')
##i1errb1=$i1errb1$dl$(echo $lineTAG1 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $2;}')
##i2b1=$i2b1$dl$(echo $lineTAG1 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $1;}')
##i2errb1=$i2errb1$dl$(echo $lineTAG1 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $2;}')

# flavour composition after b-tagging (fit)
eff0b2=$eff0b2$dl$(echo $lineTAG2 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
eff0errb2=$eff0errb2$dl$(echo $lineTAG2 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
eff1b2=$eff1b2$dl$(echo $lineTAG2 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
eff1errb2=$eff1errb2$dl$(echo $lineTAG2 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
eff2b2=$eff2b2$dl$(echo $lineTAG2 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
eff2errb2=$eff2errb2$dl$(echo $lineTAG2 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')
n0b2=$n0b2$dl$(echo $lineTAG2 | awk '{print $16;}' | tr 'pm' ' ' | awk '{print $1;}')
n0errb2=$n0errb2$dl$(echo $lineTAG2 | awk '{print $16;}' | tr 'pm' ' ' | awk '{print $2;}')
n1b2=$n1b2$dl$(echo $lineTAG2 | awk '{print $17;}' | tr 'pm' ' ' | awk '{print $1;}')
n1errb2=$n1errb2$dl$(echo $lineTAG2 | awk '{print $17;}' | tr 'pm' ' ' | awk '{print $2;}')
n2b2=$n2b2$dl$(echo $lineTAG2 | awk '{print $18;}' | tr 'pm' ' ' | awk '{print $1;}')
n2errb2=$n2errb2$dl$(echo $lineTAG2 | awk '{print $18;}' | tr 'pm' ' ' | awk '{print $2;}')
#n0b2=$n0b2$dl$(echo $lineTAG2 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $1;}')
#n0errb2=$n0errb2$dl$(echo $lineTAG2 | awk '{print $13;}' | tr 'pm' ' ' | awk '{print $2;}')
#n1b2=$n1b2$dl$(echo $lineTAG2 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $1;}')
#n1errb2=$n1errb2$dl$(echo $lineTAG2 | awk '{print $14;}' | tr 'pm' ' ' | awk '{print $2;}')
#n2b2=$n2b2$dl$(echo $lineTAG2 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $1;}')
#n2errb2=$n2errb2$dl$(echo $lineTAG2 | awk '{print $15;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 1 before b-tagging
p0f1=$p0f1$dl$(echo $lineF1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf1=$p0errf1$dl$(echo $lineF1 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f1=$p1f1$dl$(echo $lineF1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf1=$p1errf1$dl$(echo $lineF1 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f1=$p2f1$dl$(echo $lineF1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf1=$p2errf1$dl$(echo $lineF1 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 2 before b-tagging
p0f2=$p0f2$dl$(echo $lineF2 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf2=$p0errf2$dl$(echo $lineF2 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f2=$p1f2$dl$(echo $lineF2 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf2=$p1errf2$dl$(echo $lineF2 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f2=$p2f2$dl$(echo $lineF2 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf2=$p2errf2$dl$(echo $lineF2 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 3 before b-tagging
p0f3=$p0f3$dl$(echo $lineF3 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf3=$p0errf3$dl$(echo $lineF3 | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f3=$p1f3$dl$(echo $lineF3 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf3=$p1errf3$dl$(echo $lineF3 | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f3=$p2f3$dl$(echo $lineF3 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf3=$p2errf3$dl$(echo $lineF3 | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 1 after b-tagging
p0f1BTAG=$p0f1BTAG$dl$(echo $lineF1BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf1BTAG=$p0errf1BTAG$dl$(echo $lineF1BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f1BTAG=$p1f1BTAG$dl$(echo $lineF1BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf1BTAG=$p1errf1BTAG$dl$(echo $lineF1BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f1BTAG=$p2f1BTAG$dl$(echo $lineF1BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf1BTAG=$p2errf1BTAG$dl$(echo $lineF1BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 2 after b-tagging
p0f2BTAG=$p0f2BTAG$dl$(echo $lineF2BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf2BTAG=$p0errf2BTAG$dl$(echo $lineF2BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f2BTAG=$p1f2BTAG$dl$(echo $lineF2BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf2BTAG=$p1errf2BTAG$dl$(echo $lineF2BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f2BTAG=$p2f2BTAG$dl$(echo $lineF2BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf2BTAG=$p2errf2BTAG$dl$(echo $lineF2BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# FIT 3 after b-tagging
p0f3BTAG=$p0f3BTAG$dl$(echo $lineF3BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $1;}')
p0errf3BTAG=$p0errf3BTAG$dl$(echo $lineF3BTAG | awk '{print $7;}' | tr 'pm' ' ' | awk '{print $2;}')
p1f3BTAG=$p1f3BTAG$dl$(echo $lineF3BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $1;}')
p1errf3BTAG=$p1errf3BTAG$dl$(echo $lineF3BTAG | awk '{print $8;}' | tr 'pm' ' ' | awk '{print $2;}')
p2f3BTAG=$p2f3BTAG$dl$(echo $lineF3BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $1;}')
p2errf3BTAG=$p2errf3BTAG$dl$(echo $lineF3BTAG | awk '{print $9;}' | tr 'pm' ' ' | awk '{print $2;}')

# CHISQ
chisq1=$chisq1$dl$(echo $lineTAG1 | awk '{print $20;}')
ndof1=$ndof1$dl$(echo $lineTAG1 | awk '{print $21;}')
chisq2=$chisq2$dl$(echo $lineTAG2 | awk '{print $20;}')
ndof2=$ndof2$dl$(echo $lineTAG2 | awk '{print $21;}')

# Data stats
nd1=$nd1$dl$(echo $lineTAG1 | awk '{print $19;}' | tr 'pm' ' ' | awk '{print $1;}')
nderr1=$nderr1$dl$(echo $lineTAG1 | awk '{print $19;}' | tr 'pm' ' ' | awk '{print $2;}')
nd2=$nd2$dl$(echo $lineTAG2 | awk '{print $19;}' | tr 'pm' ' ' | awk '{print $1;}')
nderr2=$nderr2$dl$(echo $lineTAG2 | awk '{print $19;}' | tr 'pm' ' ' | awk '{print $2;}')

i=$[$i+1]
done

# make plots

# fit scale factor
#root -l -b makeFitPlotALLPAR.C\(\"${ptb1}\",\"${ptb2}\",\"${p0}\",\"${p1}\",\"${p2}\",\
#\"${p0err}\",\"${p1err}\",\"${p2err}\"\)

# flavour composition
#root -l -b makeFitPlotCOMP.C\(\"${ptb1}\",\"${ptb2}\",\"${eff0}\",\"${eff1}\",\"${eff2}\",\
#\"${eff0err}\",\"${eff1err}\",\"${eff2err}\",\""tag1"\"\)
#root -l -b makeFitPlotCOMP.C\(\"${ptb1}\",\"${ptb2}\",\"${eff0tag2}\",\"${eff1tag2}\",\"${eff2tag2}\",\
#\"${eff0errtag2}\",\"${eff1errtag2}\",\"${eff2errtag2}\",\""tag2"\"\)

# b/c/l-tagging efficiency (SF)
outf="input/makeFitPlotEFF.txt"
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${eff0b1} >> ${outf}
echo ${eff0b2} >> ${outf}
echo ${eff0errb1} >> ${outf} 
echo ${eff0errb2} >> ${outf}
echo ${n0b1} >> ${outf} 
echo ${n0b2} >> ${outf} 
echo ${n0errb1} >> ${outf}
echo ${n0errb2} >> ${outf}
echo ${n1b1} >> ${outf}
echo ${n1b2} >> ${outf}
echo ${n1errb1} >> ${outf}
echo ${n1errb2} >> ${outf}
echo ${n2b1} >> ${outf}
echo ${n2b2} >> ${outf}
echo ${n2errb1} >> ${outf}
echo ${n2errb2} >> ${outf}
echo ${nd1} >> ${outf}
echo ${nd2} >> ${outf}
echo ${nderr1} >> ${outf}
echo ${nderr2} >> ${outf}
echo ${fr1} >> ${outf}
echo ${fr2} >> ${outf}
root -l -b makeFitPlotEFF.C\(\""beauty"\","${usePRETAGb}","${usePRETAGc}"\)
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${eff1b1} >> ${outf}
echo ${eff1b2} >> ${outf}
echo ${eff1errb1} >> ${outf} 
echo ${eff1errb2} >> ${outf}
echo ${n0b1} >> ${outf} 
echo ${n0b2} >> ${outf} 
echo ${n0errb1} >> ${outf}
echo ${n0errb2} >> ${outf}
echo ${n1b1} >> ${outf}
echo ${n1b2} >> ${outf}
echo ${n1errb1} >> ${outf}
echo ${n1errb2} >> ${outf}
echo ${n2b1} >> ${outf}
echo ${n2b2} >> ${outf}
echo ${n2errb1} >> ${outf}
echo ${n2errb2} >> ${outf}
echo ${nd1} >> ${outf}
echo ${nd2} >> ${outf}
echo ${nderr1} >> ${outf}
echo ${nderr2} >> ${outf}
echo ${fr1} >> ${outf}
echo ${fr2} >> ${outf}
root -l -b makeFitPlotEFF.C\(\""charm"\","${usePRETAGb}","${usePRETAGc}"\)
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${eff2b1} >> ${outf}
echo ${eff2b2} >> ${outf}
echo ${eff2errb1} >> ${outf} 
echo ${eff2errb2} >> ${outf}
echo ${n0b1} >> ${outf} 
echo ${n0b2} >> ${outf} 
echo ${n0errb1} >> ${outf}
echo ${n0errb2} >> ${outf}
echo ${n1b1} >> ${outf}
echo ${n1b2} >> ${outf}
echo ${n1errb1} >> ${outf}
echo ${n1errb2} >> ${outf}
echo ${n2b1} >> ${outf}
echo ${n2b2} >> ${outf}
echo ${n2errb1} >> ${outf}
echo ${n2errb2} >> ${outf}
echo ${nd1} >> ${outf}
echo ${nd2} >> ${outf}
echo ${nderr1} >> ${outf}
echo ${nderr2} >> ${outf}
echo ${fr1} >> ${outf}
echo ${fr2} >> ${outf}
root -l -b makeFitPlotEFF.C\(\""light"\","${usePRETAGb}","${usePRETAGc}"\)

# b-tagging efficiency (MC)
outf="input/makeFitPlotCOMPEFF.txt"
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${n0b1} >> ${outf} 
echo ${n0b2} >> ${outf} 
echo ${n0errb1} >> ${outf}
echo ${n0errb2} >> ${outf}
echo ${n1b1} >> ${outf}
echo ${n1b2} >> ${outf}
echo ${n1errb1} >> ${outf}
echo ${n1errb2} >> ${outf}
echo ${n2b1} >> ${outf}
echo ${n2b2} >> ${outf}
echo ${n2errb1} >> ${outf}
echo ${n2errb2} >> ${outf}
#root -l -b makeFitPlotCOMPEFF.C\(\"${ptb1}\",\"${ptb2}\",\
#\"${n0b1}\",\"${n0b2}\",\
#\"${n0errb1}\",\"${n0errb2}\",\
#\"${n1b1}\",\"${n1b2}\",\
#\"${n1errb1}\",\"${n1errb2}\",\
#\"${n2b1}\",\"${n2b2}\",\
#\"${n2errb1}\",\"${n2errb2}\"\
#\)
root -l -b makeFitPlotCOMPEFF.C

# FIT1 vs FIT2
##root -l -b makeFitPlotFIT12.C\(\"${ptb1}\",\"${ptb2}\",\"${p0f1}\",\"${p1f1}\",\"${p2f1}\",\
##\"${p0errf1}\",\"${p1errf1}\",\"${p2errf1}\",\
##\"${p0f2}\",\"${p1f2}\",\"${p2f2}\",\
##\"${p0errf2}\",\"${p1errf2}\",\"${p2errf2}\",\
##\"${fit1tit}\",\"${fit2tit}\"\
##\)

# FIT1 vs FIT2 vs FIT3
outf="input/makeFitPlotFIT123.txt"
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${p0f1} >> ${outf} 
echo ${p1f1} >> ${outf} 
echo ${p2f1} >> ${outf}
echo ${p0errf1} >> ${outf}
echo ${p1errf1} >> ${outf}
echo ${p2errf1} >> ${outf}
echo ${p0f2} >> ${outf}
echo ${p1f2} >> ${outf}
echo ${p2f2} >> ${outf}
echo ${p0errf2} >> ${outf}
echo ${p1errf2} >> ${outf}
echo ${p2errf2} >> ${outf}
echo ${p0f3} >> ${outf}
echo ${p1f3} >> ${outf}
echo ${p2f3} >> ${outf}
echo ${p0errf3} >> ${outf}
echo ${p1errf3} >> ${outf}
echo ${p2errf3} >> ${outf}
#root -l -b makeFitPlotFIT123.C\(\"${ptb1}\",\"${ptb2}\",\"${p0f1}\",\"${p1f1}\",\"${p2f1}\",\
#\"${p0errf1}\",\"${p1errf1}\",\"${p2errf1}\",\
#\"${p0f2}\",\"${p1f2}\",\"${p2f2}\",\
#\"${p0errf2}\",\"${p1errf2}\",\"${p2errf2}\",\
#\"${p0f3}\",\"${p1f3}\",\"${p2f3}\",\
#\"${p0errf3}\",\"${p1errf3}\",\"${p2errf3}\",\
#\"${fit1tit}\",\"${fit2tit}\",\"${fit3tit}\",\
#\""beforeBTAG"\"\
#\)
root -l -b makeFitPlotFIT123.C\(\"${fit1tit}\",\"${fit2tit}\",\"${fit3tit}\",\
\""beforeBTAG"\"\)

# FIT1 vs FIT2 vs FIT3
outf="input/makeFitPlotFIT123.txt"
rm -f ${outf}
echo ${ptb1} >> ${outf} 
echo ${ptb2} >> ${outf} 
echo ${p0f1} >> ${outf} 
echo ${p1f1} >> ${outf} 
echo ${p2f1} >> ${outf}
echo ${p0errf1} >> ${outf}
echo ${p1errf1} >> ${outf}
echo ${p2errf1} >> ${outf}
echo ${p0f2} >> ${outf}
echo ${p1f2} >> ${outf}
echo ${p2f2} >> ${outf}
echo ${p0errf2} >> ${outf}
echo ${p1errf2} >> ${outf}
echo ${p2errf2} >> ${outf}
echo ${p0f3} >> ${outf}
echo ${p1f3} >> ${outf}
echo ${p2f3} >> ${outf}
echo ${p0errf3} >> ${outf}
echo ${p1errf3} >> ${outf}
echo ${p2errf3} >> ${outf}
#root -l -b makeFitPlotFIT123.C\(\"${ptb1}\",\"${ptb2}\",\"${p0f1BTAG}\",\"${p1f1BTAG}\",\"${p2f1BTAG}\",\
#\"${p0errf1BTAG}\",\"${p1errf1BTAG}\",\"${p2errf1BTAG}\",\
#\"${p0f2BTAG}\",\"${p1f2BTAG}\",\"${p2f2BTAG}\",\
#\"${p0errf2BTAG}\",\"${p1errf2BTAG}\",\"${p2errf2BTAG}\",\
#\"${p0f3BTAG}\",\"${p1f3BTAG}\",\"${p2f3BTAG}\",\
#\"${p0errf3BTAG}\",\"${p1errf3BTAG}\",\"${p2errf3BTAG}\",\
#\"${fit1tit}\",\"${fit2tit}\",\"${fit3tit}\",\
#\""afterBTAG"\"\
#\)
root -l -b makeFitPlotFIT123.C\(\"${fit1tit}\",\"${fit2tit}\",\"${fit3tit}\",\
\""afterBTAG"\"\)

# CHISQ
root -l -b makeFitPlotCHISQ.C\(\"${ptb1}\",\"${ptb2}\",\"${chisq1}\",\"${ndof1}\",\""${tag1}"\",\""beforeBTAG"\"\)
root -l -b makeFitPlotCHISQ.C\(\"${ptb1}\",\"${ptb2}\",\"${chisq2}\",\"${ndof2}\",\""${tag2}"\",\""afterBTAG"\"\)
root -l -b makeFitTable.C

mv results/fit_EFF_beauty.root results/fit_EFF_beauty_${sysOpt}.root
mv results/fit_EFF_charm.root results/fit_EFF_charm_${sysOpt}.root
mv results/fit_EFF_light.root results/fit_EFF_light_${sysOpt}.root

mv pics/fit_EFF_beauty.eps pics/fit_EFF_beauty_${sysOpt}.eps
mv pics/fit_EFF_charm.eps pics/fit_EFF_charm_${sysOpt}.eps
mv pics/fit_EFF_light.eps pics/fit_EFF_light_${sysOpt}.eps

# CONVERT TABLES
./convertTable.zsh

mv results/table_inc_heavy_1.tex results/table_inc_heavy_1_${sysOpt}.tex
mv results/table_inc_heavy_2.tex results/table_inc_heavy_2_${sysOpt}.tex
mv results/table_heavy_1.tex results/table_heavy_1_${sysOpt}.tex
mv results/table_heavy_2.tex results/table_heavy_2_${sysOpt}.tex
mv results/table_heavy_1.pdf results/table_heavy_1_${sysOpt}.pdf
mv results/table_heavy_2.pdf results/table_heavy_2_${sysOpt}.pdf

# QCD cross-section
#root -l -b makeFitPlotXSEC.C\(\"${ptb1}\",\"${ptb2}\",\
#\"${nd1}\",\
#\"${nderr1}\",\
#\"${n0b1}\",\
#\"${n0errb1}\",\
#\"${n1b1}\",\
#\"${n1errb1}\",\
#\"${n2b1}\",\
#\"${n2errb1}\",\
#\"${i0b1}\",\
#\"${i0errb1}\",\
#\"${i1b1}\",\
#\"${i1errb1}\",\
#\"${i2b1}\",\
#\"${i2errb1}\"\
#\)
