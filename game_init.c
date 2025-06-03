/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:16 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:17 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	init_game(t_game *g, char *file)
{
	g->moves = 0;
	g->map = read_map(file, g);
	validate_map(g);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->cols * TILE, g->rows * TILE, "so_long");
	load_texture(g, &g->wall, "textures/wall.xpm");
	load_texture(g, &g->floor, "textures/floor.xpm");
	load_texture(g, &g->player, "textures/player.xpm");
	load_texture(g, &g->collectible, "textures/collectible.xpm");
	load_texture(g, &g->exit, "textures/exit.xpm");
}

int	close_game(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_image(g->mlx, g->wall);
		mlx_destroy_image(g->mlx, g->floor);
		mlx_destroy_image(g->mlx, g->player);
		mlx_destroy_image(g->mlx, g->collectible);
		mlx_destroy_image(g->mlx, g->exit);
	}
	free_map(g->map);
	exit(0);
}
