PROG := assignment1

all: $(PROG)


assignment1: main.cpp
	g++ main.cpp Game.cpp -o gol
		
clean:
	rm -f $(PROG) *.o *~