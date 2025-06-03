/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:31 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:34 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (filename[len - 4] == '.' && filename[len - 3] == 'b' && filename[len
			- 2] == 'e' && filename[len - 1] == 'r');
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>", NULL);
	if (!has_ber_extension(argv[1]))
		error_exit("File must have .ber extension", NULL);
	init_game(&game, argv[1]);
	render(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
