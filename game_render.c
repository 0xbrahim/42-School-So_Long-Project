/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:20 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:22 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	render(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			mlx_put_image_to_window(g->mlx, g->win, g->floor, x * TILE, y
				* TILE);
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->wall, x * TILE, y
					* TILE);
			else if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->collectible, x
					* TILE, y * TILE);
			else if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->exit, x * TILE, y
					* TILE);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->player, g->p_x * TILE, g->p_y
		* TILE);
}

void	load_texture(t_game *g, void **img, char *path)
{
	int	width;
	int	height;

	width = TILE;
	height = TILE;
	*img = mlx_xpm_file_to_image(g->mlx, path, &width, &height);
	if (!*img)
		error_exit("Failed to load texture", g);
}
