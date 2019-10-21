all: test.out

test.out: main.o test_unit.o Unit.o State.o
	g++ -o test.out main.o test_unit.o Unit.o State.o
	
main.o:
	g++ -c main.cpp
	
test_unit.o:
	g++ -c test_unit.cpp

Unit.o:
	g++ -c ../units/Unit.cpp

State.o:
	g++ -c ../states/State.cpp

clean:
	rm -f *.o

run_tests:
	make clean && make && make clean && ./test.out
