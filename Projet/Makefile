

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = affichage.c baseDeConnaissance.c regle.c SystemExpert.c
OBJ = $(SRC:.c=.o)

TARGET = exe

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c SystemExpert.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
