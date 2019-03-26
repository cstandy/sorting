sort.out: main.o issort.o 
	g++ -o sort.out main.o issort.o
main.o: main.cpp
	g++ -DINSERTION_SORT -c main.cpp
mgsort.o: issort.cpp
	g++ -c issort.cpp
clean:
	rm -f issort.o main.o sort.out
