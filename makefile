cc = g++
cflag = -c -g -std=c++0x
file = basic

run:main.o
	${cc} -o run main.o
main.o:main.cpp basic.h
	${cc} ${cflag} main.cpp basic.h
clean:
	rm *.o
	rm run
