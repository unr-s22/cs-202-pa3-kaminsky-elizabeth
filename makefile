pa3: main.cpp Money.o
	g++ -o pa3 -std=c++11 main.cpp Money.o

Money.o: Money.h Money.cpp
	g++ -c -std=c++11 Money.cpp

clean:
	rm -f pa3 *.o
