/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:55 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:57 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_components(t_game *g, int y, int x)
{
	char	c;

	c = g->map[y][x];
	if (c == 'P')
	{
		g->p_count++;
		g->p_x = x;
		g->p_y = y;
	}
	else if (c == 'E')
		g->e_count++;
	else if (c == 'C')
		g->collect++;
}

static void	check_walls(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			if ((y == 0 || y == g->rows - 1 || x == 0 || x == g->cols - 1)
				&& g->map[y][x] != '1')
				error_exit("Map not surrounded by walls", g);
		}
	}
}

void	validate_map(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	g->p_count = 0;
	g->e_count = 0;
	g->collect = 0;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			count_components(g, y, x);
			if (!ft_strchr("01CEP", g->map[y][x]))
				error_exit("Invalid character in map", g);
		}
	}
	if (g->p_count != 1 || g->e_count != 1 || g->collect < 1)
		error_exit("Invalid P/E/C count", g);
	check_walls(g);
	if (!is_valid_path(g))
		error_exit("No valid path exists", g);
}
