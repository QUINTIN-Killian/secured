##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

SRC	=	hash.c	\
		hashtable.c	\
		ht_insert.c	\
		ht_delete.c	\
		ht_search.c	\
		ht_dump.c

OBJ	=	$(SRC:.c=.o)

LIB_NAME	=	libhashtable.a

CFLAGS	=	-g3 -W -Wall

all:	compile_lib create_lib

compile_lib:
	make -C lib/my

mv_obj:	$(OBJ)
	mv *.o obj

create_lib:	mv_obj
	ar rc $(LIB_NAME) obj/*

clean:
	rm -f obj/*
	make clean -C lib/my

fclean:	clean
	rm -f $(LIB_NAME)
	make fclean -C lib/my

re:	fclean all
