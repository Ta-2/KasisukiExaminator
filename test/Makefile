test: test.o
	g++ -Wall -std=c++17 -o test test.o -L../lib -L../../StatisticsCalculator/lib -L../../DuplicateStringFinder/lib -lKasiEx -lStaCal -lDupStFin

test.o: test.cpp
	g++ -Wall -std=c++17 -I../include -I../../StatisticsCalculator/include -I../../DuplicateStringFinder/include -c test.cpp

.PHONY: clean rebuild reboot
clean:
	-rm *.o test
	
rebuild:
	-rm ../lib/*
	g++ -Wall -std=c++17 \
	-I../../StatisticsCalculator/include -I../../DuplicateStringFinder/include -I../include \
	-o ../lib/KasisukiExaminator.o \
	-L../../StatisticsCalculator/lib -lStaCal \
	-L../../DuplicateStringFinder/lib -lDupStFin \
	-c ../src/KasisukiExaminatorSource.cpp
	ar rcs ../lib/libKasiEx.a ../lib/KasisukiExaminator.o

reboot: clean rebuild test
