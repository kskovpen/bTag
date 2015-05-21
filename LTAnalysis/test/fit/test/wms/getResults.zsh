#!/bin/env zsh

#dpath="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FIT"
dpath="/opt/sbg/scratch1/vo.sbg.in2p3.fr/kskovpen/bTag/CSVL50DATA"
#dpath="/opt/sbg/scratch1/vo.sbg.in2p3.fr/kskovpen/bTag/TCHPT50DATA"
#fpath="../results/SFSYS_TIGHT_2011CSVv2"
#fpath="../results/SFSYS_LOOSE_2011CSVTEST1"
#fpath="../results/SFSYS_MEDIUM_2011TCHPv2"
#fpath="../results/SFSYS_TIGHT_cM20"
#fpath="../results/SFSYS_TIGHT_2011"
#fpath="../results/SFSYS_MEDIUM_MAX2"
#fpath="../results/SFSYS_LOOSE_BARLOW"
#fpath="../results/SFSYS_MEDIUM_RWMAX2"
#fpath="../results/SFSYS_LOOSE_TTBAR"
#fpath="../results/SFSYS_LOOSE_2011FINALCSV_SYS1NEW"
fpath="../results/SFSYS_TIGHT_2011FINALCSV_9"
#fpath="../results/SFSYS_TIGHT_2011FINALTCHP_15"
rm -rf ${fpath}

cp -r ${dpath} ${fpath}
#/home/kskovpen/bin/rfcpr ${dpath} ${fpath}
