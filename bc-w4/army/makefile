all: a.out

a.out: main.o Unit.o SpellCaster.o State.o StateMagic.o
	g++ -o a.out main.o Unit.o SpellCaster.o State.o StateMagic.o
	
main.o:
	g++ -c main.cpp
	
Unit.o:
	g++ -c units/Unit.cpp
	
SpellCaster.o:
	g++ -c units/mages/SpellCaster.cpp
	
State.o:
	g++ -c states/State.cpp
	
StateMagic.o:
	g++ -c states/StateMagic.cpp
	
clean:
	rm -f *.o

run:
	make clean && make && make clean && ./a.out
