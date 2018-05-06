start : a.out
	./a.out


a.out: main.o test_double.o test_type.o
	g++ main.o test_double.o test_type.o

main.o: main.cpp Customstack.h node.h
	g++ -c -Wall main.cpp

test_double.o: test_double.cpp test_double.h
	g++ -c -Wall test_double.cpp

test_type.o: test_type.cpp type.h test_type.h
	g++ -c -Wall test_type.cpp

clean:
	rm -f *.o
	rm -f *.out