##
## Makefile for  in /home/nasrat_v/rendu/tek2/malloc/PSU_2020_malloc
## 
## Made by Valentin Nasraty
## Login   <valentin.nasraty@epitech.eu>
## 
## Started on  Fri Feb  3 15:34:25 2017 Valentin Nasraty
## Last update Sun Feb 12 23:05:18 2017 Valentin Nasraty
##

SRC		=  malloc.c \
	   	   free.c \
		   realloc.c \
		   manage_bloc.c \
		   get_bloc.c \
		   copy.c \
		   thread_safe.c \
		   show_alloc_mem.c \
		   basic_func.c

NAME		= libmy_malloc.so

CFLAGS  	= -c -fpic -W -Wall -ansi -pedantic -std=gnu99

CC		= cc

OBJ		= $(SRC:.c=.o)

all:		 $(NAME)

$(NAME):	$(OBJ)
		$(CC) -c -fpic $(SRC) $(CFLAGS)
		$(CC) -shared -o $(NAME) $(OBJ) -lpthread

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
