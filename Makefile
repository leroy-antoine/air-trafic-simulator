##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

SRC	=	src/main.c				\
		src/how_to_use.c		\
		src/parse_argument.c	\
		src/h_flag.c			\
		src/my_radar.c			\
		src/open_window.c		\
		src/handle_sprite.c		\
		src/event.c				\
		src/parse_infos.c		\
		src/handle_movements.c	\
		src/lerp.c

OBJ     =   $(SRC:.c=.o)

NAME    =	my_radar

LIB	=	make -C lib/my/

CFLAGS += -Wall -Wextra

CPPFLAGS += -iquote include/

CSFML += -lcsfml-graphics -lcsfml-window -lcsfml-system

VALGRIND = -g3

all:	$(OBJ)
	$(LIB)
	$(CC)  -o $(NAME) $(CPPFLAGS) $(CFLAGS) $(SRC) -L lib/my/ -lmy $(CSFML) -lm

clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) coding-style*
	$(RM) *~
	$(RM) *#
	$(RM) *.o
	$(RM) src/*~
	$(RM) src/#*
	$(RM) include/*#
	$(RM) include/*~
fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a
	$(RM) libmy.a

re:	fclean all

.PHONY: all clean fclean re
