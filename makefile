# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescobar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 10:16:56 by sescobar          #+#    #+#              #
#    Updated: 2020/10/12 11:42:25 by sescobar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LNAME = libftprintf.a

SOURCES = ft_printf.c\
	  ft_print_char.c\
	  ft_check_flags.c\
	  ft_precision.c\

OBJFOLDER = srcs/lib/

LIBSOURCES = srcs/lib/ft_atoi.c\
			 srcs/lib/ft_isdigit.c\
			 srcs/lib/ft_putstr_fd.c\
			 srcs/lib/ft_strlcat.c\
			 srcs/lib/ft_strrchr.c\
			 srcs/lib/ft_bzero.c\
			 srcs/lib/ft_isprint.c\
			 srcs/lib/ft_memmove.c\
			 srcs/lib/ft_split.c\
			 srcs/lib/ft_strlcpy.c\
			 srcs/lib/ft_strtrim.c\
			 srcs/lib/ft_calloc.c\
			 srcs/lib/ft_itoa.c\
			 srcs/lib/ft_memset.c\
			 srcs/lib/ft_strchr.c\
			 srcs/lib/ft_strlen.c\
			 srcs/lib/ft_substr.c\
			 srcs/lib/ft_isalnum.c\
			 srcs/lib/ft_memccpy.c\
			 srcs/lib/ft_putchar_fd.c\
			 srcs/lib/ft_strcpy.c\
			 srcs/lib/ft_strmapi.c\
			 srcs/lib/ft_tolower.c\
			 srcs/lib/ft_isalpha.c\
			 srcs/lib/ft_memchr.c\
			 srcs/lib/ft_putendl_fd.c\
			 srcs/lib/ft_strncmp.c\
			 srcs/lib/ft_toupper.c\
			 srcs/lib/ft_isascii.c\
			 srcs/lib/ft_memcmp.c\
			 srcs/lib/ft_putnbr_fd.c\
			 srcs/lib/ft_strjoin.c\
			 srcs/lib/ft_strnstr.c\
			 srcs/lib/ft_putchar.c\
			 srcs/lib/ft_putnbr.c

OBJ = $(SOURCES:.c=.o)

LIBOBJ = $(LIBSOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(LIBSOURCES)
	@mv -f *.o srcs/lib
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCES)
	@ar rc $(LNAME) $(OBJ) $(LIBOBJ)
	@ranlib $(LNAME)

clean:
	@rm -f $(LIBOBJ) $(OBJ) $(LIBOBJ) libft/*.o

fclean: clean
	@rm -f $(LNAME)

re: fclean all
