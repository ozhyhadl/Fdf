# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 13:45:25 by ozhyhadl          #+#    #+#              #
#    Updated: 2019/03/08 13:52:45 by ozhyhadl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf

SRC     = src/main.c \
			src/ft_del_list.c \
			src/ft_draw.c \
			src/ft_matrix_b.c\
			src/ft_read_m.c \
			src/ft_work_space.c \
			src/key.c \
			src/ft_cal.c

OBJ     = $(SRC:.c=.o)
LIBFT   = libft/
HDR  = include/fdf.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: fdf"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> FDF was deleted"


re:     fclean all

.PHONY:     re all clean fclean



	