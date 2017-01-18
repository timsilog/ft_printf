# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:03:02 by tjose             #+#    #+#              #
#    Updated: 2017/01/17 16:04:30 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf #change to .a later
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
SRCFILES = main.c \
		   handle_number.c \
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
		   get_size.c
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))
LIBFT = ./libft/libft.a
LIBFTDIR = -I./libft
LIBFTL = -L./libft -lft
SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTL) -o $(NAME) #make library instead later

clean:
	make -C ./libft clean
	rm -fr $(OBJDIR)

fclean: clean 
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
