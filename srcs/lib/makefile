# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescobar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 12:49:01 by sescobar          #+#    #+#              #
#    Updated: 2020/02/12 12:57:29 by sescobar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LNAME = libft.a

SOURCES = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c\
		  ft_strrchr.c ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c\
		  ft_strlcpy.c ft_strtrim.c ft_calloc.c ft_itoa.c ft_memset.c\
		  ft_strchr.c ft_strlen.c ft_substr.c ft_isalnum.c ft_memccpy.c\
		  ft_putchar_fd.c ft_strcpy.c ft_strmapi.c ft_tolower.c ft_isalpha.c\
		  ft_memchr.c ft_putendl_fd.c ft_strdup.c ft_strncmp.c ft_toupper.c\
		  ft_isascii.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c\
		  ft_putchar.c ft_putnbr.c
LSOURCES = $(SOURCES:.c=.o)
LFLAG = -c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(LFLAG) $(SOURCES)
	ar rc $(LNAME) $(LSOURCES)

clean:
	rm  -f $(LSOURCES)

fclean:
	rm  -f $(LNAME)

re:	fclean	all
