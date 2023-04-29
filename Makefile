##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	./src//my_hunter.c	\
		./src//events.c		\
		./src/duck_movement.c	\
		./src/menu.c		\
		./src/events_menu.c	\
		./src/game_over.c	\
		./src/my_strcmp.c	\
		./src/text_game_over.c

OBJ =	$(SRC:.c=.o)

NAME = my_hunter

FLAG = -Wall -o

CSFML_FLAG = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) $(NAME) $(CSFML_FLAG) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

