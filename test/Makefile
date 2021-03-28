test: test.o
	g++ -Wall -std=c++17 -o test test.o -L../lib -L../../StatisticsCalculator/lib -lDupStFin -lStaCal

test.o: test.cpp
	g++ -Wall -std=c++17 -I../include -I../../StatisticsCalculator/include -c test.cpp

.PHONY: clean rebuild
clean:
	-rm *.o test
	
rebuild:
	-rm ../lib/*
	g++ -Wall -std=c++17 -I../include -I../../StatisticsCalculator/include \
	-o ../lib/DuplicateStringFinder.o \
	-c ../src/DuplicateStringFinderSource.cpp \
	-L ../../StatisticsCalculator/lib -lStaCal
	ar rcs ../lib/libDupStFin.a ../lib/DuplicateStringFinder.o
