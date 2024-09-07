FLAGS = -Wall -Wextra

ifeq ($(DEBUG), 1)
    FLAGS += -g
endif

SRCS = src/playing_card.c src/blackjack_hand.c

main:
	gcc $(FLAGS) $(SRCS) main.c -o main

clean: 
	rm main

.PHONY: main