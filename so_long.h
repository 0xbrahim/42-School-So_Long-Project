/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahmed <bahmed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:33:00 by bahmed            #+#    #+#             */
/*   Updated: 2025/05/23 07:33:02 by bahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE 64
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		p_x;
	int		p_y;
	int		collect;
	int		moves;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
	void	*floor;
	int		p_count;
	int		e_count;
}			t_game;

char		**read_map(char *file, t_game *g);
void		validate_map(t_game *g);
int			is_valid_path(t_game *g);
void		init_game(t_game *g, char *file);
int			close_game(t_game *g);
void		render(t_game *g);
void		load_texture(t_game *g, void **img, char *path);
int			key_hook(int key, t_game *g);
void		handle_movement(t_game *g, int new_x, int new_y);
void		error_exit(char *msg, t_game *g);
void		free_map(char **map);
int			free_pointer(char **ptr);
char		*get_next_line(int fd);

#endif
