FLAGS = -Wall -Wextra

ifeq ($(DEBUG), 1)
    FLAGS += -g
endif

SRCS = src/card.c src/hand.c src/shoe.c src/player.c

main:
	gcc $(FLAGS) $(SRCS) main.c -o main

clean: 
	rm main

.PHONY: main