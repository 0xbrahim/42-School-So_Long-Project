# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 07:32:37 by bahmed            #+#    #+#              #
#    Updated: 2025/05/23 08:45:29 by bahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c map_parsing.c map_validation.c map_validation_path.c \
		  game_init.c game_render.c game_controls.c utils.c get_next_line.c
OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a
MLX_DIR	= minilibx
MLX		= $(MLX_DIR)/libmlx.a

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) \
		-framework OpenGL -framework AppKit -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C $(MLX_DIR) clean

re: fclean all
