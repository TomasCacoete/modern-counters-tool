FLAGS = -Wall -Wextra

ifeq ($(DEBUG), 1)
    FLAGS += -g
endif

SRCS = src/vector.c src/card.c src/shoe.c src/hand.c src/player.c src/settings.c src/table.c src/blackjack.c

main:
	gcc $(FLAGS) $(SRCS) main.c -o main

clean: 
	rm main

valgrind:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./main

.PHONY: main