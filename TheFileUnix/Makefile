TARGET = filestat
CC = gcc
SRC = filestat.c
OBJ = filestat.o
CFLAGS = -Wall -g

all: $(TARGET)
&(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
%.o:%.c
	$(CC) -c $< -o $@


clean:
	rm -f *.o $(TARGET)