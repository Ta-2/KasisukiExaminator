test: test.o
	g++ -Wall -std=c++17 -o test test.o -L../lib -L../../StatisticsCalculator/lib -lKasiEx -lStaCal

test.o: test.cpp
	g++ -Wall -std=c++17 -I../include -I../../StatisticsCalculator/include -c test.cpp

.PHONY: clean rebuild
clean:
	-rm *.o test
	
rebuild:
	-rm ../lib/*
	g++ -Wall -std=c++17 -I../include -I../../StatisticsCalculator/include \
	-o ../lib/KasisukiExaminator.o \
	-c ../src/KasisukiExaminatorSource.cpp \
	-L ../../StatisticsCalculator/lib -lStaCal
	ar rcs ../lib/libKasiEx.a ../lib/KasisukiExaminator.o
