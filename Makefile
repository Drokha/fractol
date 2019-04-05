# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trabut <trabut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 14:31:08 by trabut            #+#    #+#              #
#    Updated: 2019/04/02 18:50:11 by trabut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O2

SRC = img_tool.c\
	main.c\
	mandelbrot.c\
	julia.c\
	mandelbar.c\
	julia_cube.c\
	mandelbrotz3.c\
	key_tools.c\
	mouse_tools.c\
	tools.c\
	threads.c\
	hud.c\

OBJ := $(patsubst %.c,%.o,$(SRC))

INC = fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	gcc -o $(NAME) -I /usr/local/include $(OBJ) -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit
	echo "fractol ready"

p: all clean

clean:
	/bin/rm -f $(OBJ)
	echo "Objects Destroyed"

fclean:	clean
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:	fclean all

norm:
	norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm p

.SILENT: