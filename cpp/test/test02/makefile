all: a.exe
a.exe: 1.o 2.o
	g++ 1.o 2.o -o a.exe
1.o: 1.cpp fun.h
	g++ 1.cpp -c -o 1.o
2.o: 2.cpp fun.h
	g++ 2.cpp -c -o 2.o
clean:
	del *.o *.exe