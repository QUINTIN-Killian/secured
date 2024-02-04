##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile for mylib
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

H_NAME	=	my.h

all:	compile copy_header

compile:	$(OBJ)
	cp $? ../../obj

copy_header:
	cp $(H_NAME) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean

re:	fclean all
