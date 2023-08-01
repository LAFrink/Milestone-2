CC=g++
exe_file=run

$(exe_file): main.cpp backlog.o 
	$(CC) main.cpp backlog.o -o $(exe_file)
backlog.o: backlog.cpp backlog.h 
	$(CC) -c backlog.cpp
clean:
	rm -f *.o $(exe_file)