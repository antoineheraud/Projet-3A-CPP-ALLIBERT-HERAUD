CC = g++
CFLAGS = -Wall
EXEC_NAME = simul.exe
INCLUDES = 
LIBS =
OBJ_FILES = data_value.o plateform.o display.o memory.o program.o CPU_register.o CPU.o bus.o main.o
INSTALL_DIR = /usr/bin

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) -std=c++11 $(CFLAGS) $(INCLUDES) -o $@ -c $<
