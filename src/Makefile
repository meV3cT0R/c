BIN=../bin
PROGRAM=algorithms
IDIR=include
ODIR=../build/obj
CFLAGS=-I$(IDIR)

_DEPS=tree.h node.h mergeStrings.h graph.h queue.h removeDuplicates.h gridTraveler.h canSum.h howSum.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ=main.o tree.o node.o mergeStrings.o graph.o queue.o removeDuplicates.o dynamicProgramming/fib.o dynamicProgramming/gridTraveler.o dynamicProgramming/canSum.o dynamicProgramming/howSum.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	gcc -o $(BIN)/$@ $^ -Wall -g -O2 -Wextra -rdynamic $(LIBS) 

run:
	$(BIN)/$(PROGRAM)
	