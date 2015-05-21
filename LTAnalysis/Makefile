# Makefile

CC = g++ -g -Wno-write-strings

JESINC    = -I/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src
JESLIB    = -L/home-pbs/kskovpen/bTag/CMSSW_7_4_0/lib/slc6_amd64_gcc491 \
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

SRC = src/LTAnalysis.cxx src/Hist.cxx src/Tree.cxx \
src/Syst.cxx src/Helper.cxx src/Reweight.cxx

INC = include/Hist.h include/Common.h include/Tree.h \
include/Ranges.h include/Syst.h include/Helper.h include/Reweight.h

OBJ = LTAnalysis.o Hist.o Tree.o Syst.o Helper.o Reweight.o

EXE = LTAnalysis

all:  	     		$(EXE)
#			@rm -f *.o

$(EXE):     	 	$(OBJ) $@

$(OBJ):     		$(SRC) $(INC)
		        $(CC) -c $(ROOTCFLAGS) $(ADDINC) $(SRC)

clean: 		
			@rm -f $(OBJ) $(EXE)
