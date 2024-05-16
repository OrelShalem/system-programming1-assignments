CC = gcc

CFLAGS = -Wall -Wextra -pedantic

SRC = compress.c encodemain.c

OBJ = compress.o encodemain.o

TARGET = digitcompress

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)