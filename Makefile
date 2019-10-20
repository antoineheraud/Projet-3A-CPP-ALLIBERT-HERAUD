executable: programP.o mainprogram.o
	g++ -o prog.exe programP.o mainprogram.o

program.o: programP.cpp
	g++ -o programP.o programP.cpp

mainprogram.o: mainprogram.cpp program.h
	g++ -o mainprogram.o -c mainprogram.cpp


clean:
	rm -f *.o core
