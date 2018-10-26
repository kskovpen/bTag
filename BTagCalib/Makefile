# Makefile

CC = g++ -g -std=c++11 -Wall -pedantic

ROOTCONF                = root-config
ROOTLIBS                = $(shell $(ROOTCONF) --libs)
ROOTGLIBS               = $(shell $(ROOTCONF) --glibs)
ROOTCFLAGS              = $(shell $(ROOTCONF) --cflags)
INCLUDES                = $(shell $(ROOTCONF) --incdir) $(ROOTCFLAGS)
LIBS                    = $(ROOTLIBS)

LDLIBS  = $(ROOTLIBS)

SRC = BTagCalibrationStandalone.cpp testCalib.C

INC = BTagCalibrationStandalone.h testCalib.h

OBJ = BTagCalibrationStandalone.o testCalib.o

EXE = testCalib

all:       $(EXE)

$(EXE):      $(OBJ) $@

$(OBJ):     $(SRC) $(INC) 
	$(CC) -c $(ROOTCFLAGS) $(ADDINC) $(SRC)
	    
clean:
	@rm -f $(OBJ) $(EXE)
