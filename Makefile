CC     = cc
CFLAGS = -Wall -Wextra -Wshadow -pedantic -O2 -ansi
EXEC   = line-printer
SRC    = line-printer.c

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
