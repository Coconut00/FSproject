all:
	g++ -g -Wall -o my_shell my_shell.cpp File.cpp Disk.cpp -lpthread

clean:
	rm -rf main my_shell
