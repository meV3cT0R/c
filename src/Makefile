BIN=../bin
PROGRAM=algorithms
IDIR=include
ODIR=obj
CFLAGS=-I$(IDIR)
LIBS=-lm

_DEPS=tree.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ=main.o tree.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	gcc -o $(BIN)/$@ $^ -Wall $(LIBS) 

run:
	$(BIN)/$(PROGRAM)