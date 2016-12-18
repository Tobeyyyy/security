FLAGS = -std=c++0x -Wall

all: hello

hello:	monitor.o class.o main.o
	g++ monitor.o class.o main.o  -o hello
main.o:	main.cpp
	g++ $(FLAGS) -c main.cpp
class.o: class.cpp
	g++ $(FLAGS) -c class.cpp
monitor.o: monitor.cpp
	g++ $(FLAGS) -c monitor.cpp
run:
	./hello input
clean:
	rm -rf *o hello
