/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:32:44 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:32:46 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_line(t_game *g, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (g->cols == -1)
		g->cols = len;
	else if (len != g->cols)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static void	get_size(t_game *g, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Map file error", NULL);
	g->rows = 0;
	g->cols = -1;
	line = get_next_line(fd);
	while (line && ++g->rows)
	{
		if (!process_line(g, line))
			error_exit("Map not rectangular", NULL);
		line = get_next_line(fd);
	}
	close(fd);
}

static int	read_and_check_lines(int fd, t_game *g, char **map)
{
	int		i;
	int		len;
	char	*line;

	i = -1;
	while (++i < g->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = line;
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len != g->cols)
			break ;
	}
	return (i);
}

static void	read_lines(int fd, t_game *g, char **map)
{
	int	i;

	i = read_and_check_lines(fd, g, map);
	if (i < g->rows)
	{
		close(fd);
		free_map(map);
		if (i > 0)
			error_exit("Map reading failed", NULL);
		else
			error_exit("Map not rectangular", NULL);
	}
}

char	**read_map(char *file, t_game *g)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	get_size(g, file);
	map = ft_calloc(g->rows + 1, sizeof(char *));
	if (!map)
		error_exit("Memory allocation failed", NULL);
	read_lines(fd, g, map);
	close(fd);
	return (map);
}
