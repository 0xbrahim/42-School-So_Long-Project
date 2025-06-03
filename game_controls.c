/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:02 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:09 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124

void	handle_movement(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->cols || new_y < 0 || new_y >= g->rows)
		return ;
	if (g->map[new_y][new_x] != '1')
	{
		g->p_x = new_x;
		g->p_y = new_y;
		g->moves++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(g->moves, 1);
		ft_putstr_fd("\n", 1);
		if (g->map[new_y][new_x] == 'C')
		{
			g->map[new_y][new_x] = '0';
			g->collect--;
		}
		if (g->map[new_y][new_x] == 'E' && g->collect == 0)
			close_game(g);
		render(g);
	}
}

int	key_hook(int key, t_game *g)
{
	if (key == KEY_ESC)
		close_game(g);
	else if (key == KEY_W || key == KEY_UP)
		handle_movement(g, g->p_x, g->p_y - 1);
	else if (key == KEY_A || key == KEY_LEFT)
		handle_movement(g, g->p_x - 1, g->p_y);
	else if (key == KEY_S || key == KEY_DOWN)
		handle_movement(g, g->p_x, g->p_y + 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		handle_movement(g, g->p_x + 1, g->p_y);
	return (0);
}
