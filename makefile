MODULES = dict_couple.c dict_chain.c
SRC_DIR = dict_couple_library
OBJS = $(MODULES:.c=.o)

main: $(OBJS)
	gcc $(OBJS) -o main

%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@