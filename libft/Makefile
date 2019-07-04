# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 17:22:00 by lolee             #+#    #+#              #
#    Updated: 2019/05/16 19:10:31 by lolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra  -c
HEADER	= libft.h
FILES	= ft_atoi.c \
				ft_bzero.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memalloc.c \
				ft_memchr.c \
				ft_memccpy.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strdel.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_toupper.c \
				ft_tolower.c 

OBJ		= $(FILES:%.c=%.o)

#all: $(NAME) $(FILES) $(HEADER)
#	$(CC) $(CFLAGS) $(FILES)
#	ar rc $(NAME) $(OBJ)
#	ranlib $(NAME)

all	: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(FILES) $(HEADER)
	$(CC) $(CFLAGS) $(FILES)

clean:
	echo " clean, rm -f *.o ............................................ "
	/bin/rm -f $(OBJ)

fclean: clean
	echo " rm *.o and libxx.a .................................................. "
	/bin/rm -f $(NAME)

re: fclean all
