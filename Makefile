CC = gcc
CFLAGS = -Wall -Wextra -g -O0

SRCDIR = src

ENC = $(SRCDIR)/encode.c $(SRCDIR)/usage.c $(SRCDIR)/file.c $(SRCDIR)/option.c $(SRCDIR)/list.c $(SRCDIR)/mtf.c
DEC = $(SRCDIR)/decode.c $(SRCDIR)/usage.c $(SRCDIR)/file.c $(SRCDIR)/option.c $(SRCDIR)/list.c $(SRCDIR)/mtf.c

TARGET = enc dec

all: $(TARGET)

enc: $(ENC)
	$(CC) $(CFLAGS) -o $@ $^

dec: $(DEC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
