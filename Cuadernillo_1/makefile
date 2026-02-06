.PHONY= clean allC allV allL all

CC=g++
OPTIONS= -g
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcomplejo.o tvectorcom.o #tlistacom.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

# Encuentra todos los tads disponibles
TADS_C = $(wildcard pruebas/complejo/tad*.cpp)
TADS_V = $(wildcard pruebas/vector/tad*.cpp)
#TADS_L = $(wildcard pruebas/lista/tad*.cpp)

# Genera nombres de ejecutables
EXES_C = $(patsubst pruebas/complejo/tad%.cpp,tadC%,$(TADS_C))
EXES_V = $(patsubst pruebas/vector/tad%.cpp,tadV%,$(TADS_V))
#EXES_L = $(patsubst pruebas/lista/tad%.cpp,tadL%,$(TADS_L))

all: allC allV allL

allC: $(EXES_C)
allV: $(EXES_V)
allL: $(EXES_L)

tadC%: pruebas/complejo/tad%.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $< $(OBJ) -o $@

tadV%: pruebas/vector/tad%.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $< $(OBJ) -o $@

#tadL%: pruebas/lista/tad%.cpp $(OBJ)
#	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $< $(OBJ) -o $@

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

clean:
	rm -f $(OBJ) tadC* tadV* tadL*
