pa3: main.cpp Money.o Account.o
	g++ -o pa3 -std=c++11 main.cpp Money.o Account.o

Money.o: Money.h Money.cpp
	g++ -c -std=c++11 Money.cpp

Account.o: Account.h Account.cpp
	g++ -c -std=c++11 Account.cpp

clean:
	rm -f pa3 *.o
