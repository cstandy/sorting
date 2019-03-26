ifeq ($(SORT), issort)
	SORT_DEF=INSERTION_SORT
endif 

ifeq ($(SORT), mgsort)
	SORT_DEF=MERGE_SORT
endif 

sort.out: main.o $(SORT).o 
	g++ -o sort.out main.o $(SORT).o
main.o: main.cpp
	g++ -D$(SORT_DEF) -c main.cpp
$(SORT).o: $(SORT).cpp
	g++ -c $(SORT).cpp
clean:
	rm -f $(SORT).o main.o sort.out
