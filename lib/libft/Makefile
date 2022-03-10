# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamigore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 15:04:29 by tamigore          #+#    #+#              #
#    Updated: 2021/01/05 14:36:43 by tamigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC/M = ft_memset.c		\
		ft_memcpy.c 	\
		ft_memccpy.c 	\
		ft_memchr.c  	\
		ft_memmove.c 	\
		ft_memalloc.c	\
		ft_memcmp.c		\
		ft_memdel.c

SRC/O = ft_atoi.c		\
		ft_superatoi.c	\
		ft_bzero.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_itoa.c		\
		ft_swap.c		\
		ft_sorttab.c	\
		get_next_line.c	\
		ft_rmstr.c		\
		ft_rmchar.c		\
		ft_nbrlen.c		\
		ft_free_join.c	\
		ft_free_rmstr.c	\
		ft_free_rmchar.c\
		ft_calloc.c

SRC/I = ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c

SRC/P = ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_puttab.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRC/S = ft_strlen.c		\
		ft_strdup.c		\
		ft_strndup.c	\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strlcpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_strrev.c		\
		ft_search.c

SRC/L = ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_lstclear.c		\
		ft_lstlast.c		\
		ft_lstsize.c

INC = libft.h

DIR_I = includes

DIR_S = srcs

SRC = $(SRC/P) $(SRC/O) $(SRC/I) $(SRC/S) $(SRC/M) $(SRC/L)

SRCS = $(addprefix $(DIR_S)/,$(SRC))

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -I $(DIR_I)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) : $(SRCS) $(DIR_I)/$(INC)
	mkdir -p objs
	$(CC) $(FLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
