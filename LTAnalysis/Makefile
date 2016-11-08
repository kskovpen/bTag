# Makefile

CC = g++ -g -Wno-write-strings -Wno-attributes

JESINC    = -I/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/CMSSW_8_0_12/src
JESLIB    = -L/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/CMSSW_8_0_12/lib/slc6_amd64_gcc530/\
              -lCondFormatsJetMETObjects

SOVERSION               = $(shell echo $(VERSION) | \
                               sed 's/\(.*\)\.\(.*\)\.\(.*\)/\1:\2:0/')
ROOTCONF                = root-config
ROOTCINT                = $(shell $(ROOTCONF) --prefix)/bin/rootcint
ROOTLIBS                = $(shell $(ROOTCONF) --libs)
ROOTGLIBS               = $(shell $(ROOTCONF) --glibs)
ROOTCFLAGS              = $(shell $(ROOTCONF) --cflags)
INCLUDES                = $(shell $(ROOTCONF) --incdir) $(ROOTCFLAGS)
CINTINCLUDES            = $(shell $(ROOTCONF) --incdir)
LIBS                    = $(ROOTLIBS)

LDLIBS  = $(ROOTLIBS) $(JESLIB)

ADDINC = $(JESINC)

SRC = src/LTAnalysis.cxx src/Hist.cxx src/HistBoost.cxx src/Tree.cxx src/TreeSub.cxx \
src/Syst.cxx src/Helper.cxx src/Reweight.cxx src/Trigger.cxx src/PU.cxx src/PS.cxx

INC = include/Hist.h include/HistBoost.h include/Common.h include/Tree.h include/TreeSub.h \
include/Ranges.h include/RangesFat.h include/RangesSub.h include/Syst.h include/Helper.h include/Reweight.h \
include/Trigger.h include/PU.h include/PS.h

OBJ = LTAnalysis.o Hist.o HistBoost.o Tree.o TreeSub.o Syst.o Helper.o Reweight.o Trigger.o PU.o PS.o

EXE = LTAnalysis

all:  	     		$(EXE)
#			@rm -f *.o

$(EXE):     	 	$(OBJ) $@

$(OBJ):     		$(SRC) $(INC)
		        $(CC) -c $(ROOTCFLAGS) $(ADDINC) $(SRC)

clean: 		
			@rm -f $(OBJ) $(EXE)
