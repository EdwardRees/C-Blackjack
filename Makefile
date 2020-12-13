# Output binary name
bin=blackjack

# Compiler/linker flags
CFLAGS += -g -Wall -fPIC
LDLIBS += -lm -lncurses
LDFLAGS +=

# Source C files
src=blackjack.c card.c hand.c printer.c setup.c game.c
obj=$(src:.c=.o)

$(bin): $(obj)
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -o $@

blackjack.o: blackjack.c card.h hand.h printer.h setup.h game.h structs.h
card.o: card.c card.h structs.h
hand.o: hand.c hand.h card.h structs.h 
printer.o: printer.c printer.h structs.h
setup.o: setup.c setup.h structs.h
game.o: game.c game.h hand.h printer.h structs.h


docs: Doxyfile
	doxygen

clean:
	rm -f $(bin) $(obj)
	rm -rf docs

