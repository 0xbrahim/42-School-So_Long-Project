/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:50 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:52 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *g, char **map, int x, int y)
{
	if (x < 0 || x >= g->cols || y < 0 || y >= g->rows || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(g, map, x + 1, y);
	flood_fill(g, map, x - 1, y);
	flood_fill(g, map, x, y + 1);
	flood_fill(g, map, x, y - 1);
}

static char	**copy_map(t_game *g)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(g->rows + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < g->rows)
	{
		map_copy[i] = ft_strdup(g->map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
	}
	return (map_copy);
}

int	is_valid_path(t_game *g)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = copy_map(g);
	if (!map_copy)
		error_exit("Memory allocation failed", g);
	flood_fill(g, map_copy, g->p_x, g->p_y);
	i = -1;
	while (++i < g->rows)
	{
		j = -1;
		while (++j < g->cols)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map(map_copy);
				return (0);
			}
		}
	}
	free_map(map_copy);
	return (1);
}
