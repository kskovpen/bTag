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

ADDLIBS = -Latlasstyle-00-03-04 -lAtlasStyle -lAtlasUtils

LDLIBS  = $(ROOTLIBS) $(ADDLIBS)

SRC = rw.cxx

INC = def.h addbin.h addbin2D.h ratioErr.h makeErrorBand.h func.h

OBJ = rw.o

EXE = rw

all:  	     		$(EXE)
			@rm -f *.o

$(EXE):     	 	$(OBJ) $@

$(OBJ):     		$(SRC) $(INC)
		        $(CC) -c $(ROOTCFLAGS) $(ADDINC) $(SRC)

clean: 		
			@rm -f $(OBJ) $(EXE)
