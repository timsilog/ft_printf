# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:03:02 by tjose             #+#    #+#              #
#    Updated: 2017/01/31 14:14:34 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
SRCFILES = handle_number.c \
		   handle_char.c \
		   handle_str.c \
		   handle_flags.c \
		   handle_length.c \
		   handle_precision.c \
		   handle_width.c \
		   handle_specifier.c \
		   handle_nospec.c \
		   ft_printf.c \
		   place.c \
		   convert_length.c \
		   get_size.c \
		   is_mb.c
LIBFT = $(addprefix $(LIBFTDIR), $(LIBFTFILES))
LIBFTFILES = ft_putchar.c \
			 ft_putstr.c \
			 ft_putnbr.c \
			 ft_strcat.c \
			 ft_strncat.c \
			 ft_strlcat.c \
			 ft_strcmp.c \
			 ft_strncmp.c \
			 ft_strcpy.c \
			 ft_strncpy.c \
			 ft_strlen.c \
			 ft_strdup.c \
			 ft_strstr.c \
			 ft_strnstr.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_isalpha.c \
			 ft_isascii.c \
			 ft_isdigit.c \
			 ft_isprint.c \
			 ft_isalnum.c \
			 ft_is_wp.c \
			 ft_atoi.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memccpy.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memmove.c \
			 ft_memset.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_itoa.c \
			 ft_memalloc.c \
			 ft_memdel.c \
			 ft_putchar_fd.c \
			 ft_putendl.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_strclr.c \
			 ft_strdel.c \
			 ft_strequ.c \
			 ft_striter.c \
			 ft_striteri.c \
			 ft_strjoin.c \
			 ft_strmap.c \
			 ft_strmapi.c \
			 ft_strnequ.c \
			 ft_strsplit.c \
			 ft_itoabase.c \
			 ft_uitoabase.c \
			 ft_numlen.c \
			 ft_strsub.c \
			 ft_strtrim.c \
			 ft_strnew.c \
			 ft_lstnew.c \
			 ft_lstdelone.c \
			 ft_lstdel.c \
			 ft_lstadd.c \
			 ft_lstiter.c \
			 ft_lstmap.c \
			 ft_isneg.c \
			 ft_isprime.c \
			 ft_sqrt.c \
			 ft_pow.c \
			 ft_lstadd_back.c \
			 ft_wctomb.c \
			 ft_wcstombs.c \
			 ft_wclen.c \
			 ft_wcslen.c

OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))
LIBFTO = $(addprefix $(LIBODIR), $(LIBFTFILES:.c=.o))
LIBFTDIR = ./libft/
SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/
LIBODIR = ./libft/objs/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(LIBODIR)%.o: $(LIBFTDIR)%.c
	mkdir -p $(LIBODIR)
	$(CC) $(CFLAGS) -I ./libft/ -o $@ -c $<

BOTH = $(OBJS) $(LIBFTO)

$(NAME): $(BOTH)
	ar rc $(NAME) $(BOTH)
	ranlib $(NAME)

clean:
	rm -fr $(OBJDIR) $(LIBODIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all
