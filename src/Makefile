BIN=../bin
PROGRAM=algorithms
IDIR=include
ODIR=../build/obj
CFLAGS=-I$(IDIR)
LIBS=-lm

_DEPS=tree.h node.h mergeStrings.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ=main.o tree.o node.o mergeStrings.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	gcc -o $(BIN)/$@ $^ -Wall $(LIBS) 

run:
	$(BIN)/$(PROGRAM)
	