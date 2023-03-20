CC = g++
CPPFLAGS = -Wall -g -std=c++11
APP_NAME = main
OBJ_FILES = list.o table.o website.o main.o ./helpers/getters.o

main: $(OBJ_FILES)

compile: $(OBJ_FILES)
	$(CC) *.cpp $(CPPFLAGS) -o $(APP_NAME)

main.o: main.h
website.o: website.h
table.o: table.h
list.o: list.h
./helpers/getters.o: ./helpers/getters.h

run:
	./$(APP_NAME)

leak:
	valgrind --leak-check=full ./$(APP_NAME)

.PHONY: clean
clean:
	$(info -- cleaning the directory -- )
	rm -rf *.o
	rm -f main
