# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 10:32:39 by lvoyance          #+#    #+#              #
#    Updated: 2020/05/16 22:14:46 by alorilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= main.c \
			draw.c \
			menu.c \
			options.c \
			read_file.c \


OBJS	= $(addprefix $(OBJDIR),$(SRCS:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLX		= ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I ./minilibx_macos
MLX_LNK	= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= createlib
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/


all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCDIR)fdf.h
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)
	
$(MLX_LIB):
	make -C $(MLX)
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm $(FT)libft.a
	/bin/rm -f $(NAME)

re: fclean all
