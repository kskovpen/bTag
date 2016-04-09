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

export ROOTSYS=/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-ikhhed
ls $ROOTSYS/bin/thisroot.sh
source $ROOTSYS/bin/thisroot.sh
rootV=$(root-config --version)
echo "ROOT v${rootV} has been set up"

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${WDIR}

export LD_LIBRARY_PATH=\
/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/gcc/4.9.3/lib64:\
/usr/lib64:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/gcc/4.9.3/lib:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/cmssw/CMSSW_7_6_1/external/slc6_amd64_gcc493/lib/:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/cmssw/CMSSW_7_6_1/lib/slc6_amd64_gcc493/:\
$LD_LIBRARY_PATH

export PATH=/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/gcc/4.9.3/bin:$PATH

echo "Executing .././SimPlot ${line2} ${dout}${fout} ${noe} ${xsec} ${eff}"
${dout}/.././SimPlot ${line2} ${dout}${fout} ${noe} ${xsec} ${eff}
