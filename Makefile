CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c my_printf.c

TARGET = my_program

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)