#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/08 07:55:14 by gmevelec          #+#    #+#              #
#    Updated: 2015/05/06 11:52:38 by gmevelec         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRCDIR = src/
LIB_FOLD = libft/
LIBDIR = obj/
HEADDIR = inc
CFLAGS = -Wall -Wextra -Werror -I$(HEADDIR) -L./lib -lmlx -O3

SRC = $(SRCDIR)/main.c \
	$(SRCDIR)/init.c \
	$(SRCDIR)/thread.c \
	$(SRCDIR)/error.c \
	$(SRCDIR)/color_convert.c \
	$(SRCDIR)/draw_fractal.c \
	$(SRCDIR)/check_param.c \
	$(SRCDIR)/render.c \
	$(SRCDIR)/move.c \

TSRC=$(subst src/,../src/,$(SRC))

TMP=$(subst src/,obj/,$(SRC))

OBJ = $(TMP:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		make -C $(LIB_FOLD)
		@llvm-gcc -o $(NAME) $(OBJ) $(CFLAGS) -framework OpenGL -framework AppKit -L$(LIB_FOLD) -lft
		@echo "Creating $(NAME)"

$(OBJ) :: $(SRC)
		@mkdir -p $(LIBDIR)
		@(cd obj;llvm-gcc -c $(TSRC))
		@echo "Creating .o"

clean :
		@rm -f $(OBJ)
		@echo "Suppressing all .o"

fclean : clean
		@rm -f $(NAME)
		@echo "Suppressing $(NAME)"

re : fclean all

.PHONY: all clean fclean re
