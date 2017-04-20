IDIR =../Include
CXX= g++
CXXFLAGS=-I$(IDIR) -g -D_TEST

ODIR=../OBJ
LDIR=../LIB

LIBS= -lgtest -lpthread -lgtest_main -g

_DEPS= Conversor.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= main.o TDD.o
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
