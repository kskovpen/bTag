#!/bin/sh

export X509_USER_PROXY=/home-pbs/kskovpen/proxy/x509up_u7989

export LD_PRELOAD=/usr/lib64/libglobus_gssapi_gsi.so.4

WDIR=$(pwd)

line2=${line2}
fout=${fout}
noe=${noe}
xsec=${xsec}
eff=${eff}
sample=${sample}
dout=${dout}

export ROOTSYS=/cvmfs/cms.cern.ch/slc6_amd64_gcc491/lcg/root/6.02.00-odfocd4
ls $ROOTSYS/bin/thisroot.sh
source $ROOTSYS/bin/thisroot.sh
rootV=$(root-config --version)
echo "ROOT v${rootV} has been set up"

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${WDIR}

export LD_LIBRARY_PATH=\
/cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/gcc/4.9.1-cms/lib64:\
/usr/lib64:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/gcc/4.9.1-cms/lib:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_4_6/external/slc6_amd64_gcc491/lib/:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_4_6/lib/slc6_amd64_gcc491/:\
$LD_LIBRARY_PATH

export PATH=/cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin:$PATH

echo "Executing .././SimPlot ${line2} ${dout}${fout} ${noe} ${xsec} ${eff}"
${dout}/.././SimPlot ${line2} ${dout}${fout} ${noe} ${xsec} ${eff}
