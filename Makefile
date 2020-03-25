##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Makefile
##

################
# Source Files #
################

CC	=	gcc

RENDER_SRCS	=	render/simple_render.c

DESTROY_SRCS	=	destroy/simple_destroy.c

EVENT_SRCS	=	events/analyse_event.c	\
				events/event_callbacks.c

MENU_FOLD	=	game_objects/menu_scene

GAME_FOLD	=	game_objects/game_scene

GAME_OBJECTS	=	$(MENU_FOLD)/menu_callbacks.c	\
					$(MENU_FOLD)/menu_scene_init.c	\
					$(GAME_FOLD)/game_scene_init.c

SRC	=	my_rpg.c	\
		init_scenes.c	\
		$(RENDER_SRCS)	\
		$(DESTROY_SRCS)	\
		$(EVENT_SRCS)	\
		$(GAME_OBJECTS)

OSRC	=	$(SRC:.c=.o)

SRC_TESTS	=	tests/tests.c

OSRC_T	=	$(SRC_TESTS:.c=.o)

LIB = lists my

#########
# Mains #
#########

SRC_MAIN	=	main.c

OSRC_M	=	$(SRC_MAIN:.c=.o)

################
# Binary names #
################

NAME	=	my_rpg

NAME_TESTS	=	tests_run

#########
# Tools #
#########

RUN_TESTS	=	./$(NAME_TESTS)

COVERAGE	=	gcovr --exclude tests/

COVERAGE_B	=	gcovr --exclude tests/ -b

#########
# Flags #
#########

CFLAGS += -W -Wall -Wextra -pedantic

TFLAGS += --coverage -lcriterion -g3

IFLAGS += -I./include

TMPFLAGS += $(addsuffix .a, $(addprefix lib/lib, $(LIB)))
LFLAGS = $(addprefix -L. , $(TMPFLAGS)) -l csfml-graphics -l csfml-system -lm

############
# Commands #
############

all: $(OSRC) $(OSRC_M) lib
	$(CC) $(IFLAGS) -o $(NAME) $(OSRC) $(OSRC_M) $(LFLAGS)

lib:
ifeq ($(MAKECMDGOALS), re)
	@for i in $(LIB); do \
		(cd ./lib/$$i/ && make re -s);\
		done;
else
	@for i in $(LIB); do \
		(cd ./lib/$$i/ && make -s); \
		done;
endif

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

tests_run:	clean $(OSRC) $(OSRC_T) lib
	$(CC) -o $(NAME_TESTS) $(OSRC_T) $(OSRC) $(IFLAGS) $(TFLAGS) $(LFLAGS)
	$(RUN_TESTS)

debug: fclean lib
	$(CC) $(IFLAGS) -o $(NAME) $(SRC) $(SRC_MAIN)  $(LFLAGS) -g3

coverage:
	$(COVERAGE)
	$(COVERAGE_B)

clean:
	find -type f -name "*~" -delete
	find -type f -name "#*#" -delete
	find -type f -name "*.o" -delete

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_TESTS)
	find -type f -name "a.out" -delete
	find -type f -name "*.a" -delete
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete
	find -type f -name "vgcore.*" -delete

re:	fclean all

.PHONY: all, tests_run, coverage, clean, fclean, re, debug, lib