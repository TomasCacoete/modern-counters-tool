FLAGS = -Wall -Wextra

ifeq ($(DEBUG), 1)
    FLAGS += -g
endif

SRCS = src/vector.c src/card.c src/shoe.c

main:
	gcc $(FLAGS) $(SRCS) main.c -o main

clean: 
	rm main

valgrind:
	valgrind --track-origins=yes --leak-check=full -s ./main

.PHONY: main