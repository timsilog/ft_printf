# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:03:02 by tjose             #+#    #+#              #
#    Updated: 2017/01/10 13:57:51 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf #change to .a later
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
SRCFILES = main.c \
		   handle_decimal.c \
		   handle_flags.c \
		   handle_length.c \
		   handle_precision.c \
		   handle_width.c \
		   handle_specifier.c \
		   ft_printf.c
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
