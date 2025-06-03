/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:33:09 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:33:11 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	error_exit(char *msg, t_game *g)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (g)
	{
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		if (g->mlx)
		{
			if (g->wall)
				mlx_destroy_image(g->mlx, g->wall);
			if (g->floor)
				mlx_destroy_image(g->mlx, g->floor);
			if (g->player)
				mlx_destroy_image(g->mlx, g->player);
			if (g->collectible)
				mlx_destroy_image(g->mlx, g->collectible);
			if (g->exit)
				mlx_destroy_image(g->mlx, g->exit);
		}
		if (g->map)
			free_map(g->map);
	}
	exit(EXIT_FAILURE);
}

int	free_pointer(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}
