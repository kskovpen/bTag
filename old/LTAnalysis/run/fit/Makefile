# Makefile

CC = g++ -g

SOVERSION               = $(shell echo $(VERSION) | \
                               sed 's/\(.*\)\.\(.*\)\.\(.*\)/\1:\2:0/')
ROOTCONF                = root-config
ROOTCINT                = $(shell $(ROOTCONF) --prefix)/bin/rootcint
ROOTLIBS                = $(shell $(ROOTCONF) --libs) -lMinuit
ROOTGLIBS               = $(shell $(ROOTCONF) --glibs)
ROOTCFLAGS              = $(shell $(ROOTCONF) --cflags)
INCLUDES                = $(shell $(ROOTCONF) --incdir) $(ROOTCFLAGS)
CINTINCLUDES            = $(shell $(ROOTCONF) --incdir)
LIBS                    = $(ROOTLIBS)

ADDLIBS = -L/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491 -lAtlasStyle -lAtlasUtils

ADDINC = -I/home/kskovpen/plugins/

LDLIBS  = $(ROOTLIBS) $(ADDLIBS)

SRC = fit.cxx

INC = def.h func.h addbin.h addbin2D.h makeErrorBand.h \
removeMCNeg.h removeMCSys.h adjust.h label.h

OBJ = fit.o

EXE = fit

all:  	     		$(EXE)
			@rm -f *.o

$(EXE):     	 	$(OBJ) $@

$(OBJ):     		$(SRC) $(INC)
		        $(CC) -c $(ROOTCFLAGS) $(ADDINC) $(SRC)

clean: 		
			@rm -f $(OBJ) $(EXE)
