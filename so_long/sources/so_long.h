/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:15:32 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h> 
# include <fcntl.h>
# include <stdint.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct s_character
{
	void	*character;
	int		x;
	int		y;
	int		points;
}	t_character;

typedef struct s_map
{
	char	**mapfill;
	int		height;
	int		width;
	int		player;
	int		weed;
	int		deadf;
	int		deadfx;
	int		deadfy;
	int		won;
}				t_map;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	void		*sea;
	void		*wall;
	void		*alive;
	void		*weed;
	void		*deadf;
	int			height;
	int			width;
	t_map		*map;
	t_character	*character;
}	t_game;

void	check_alive_character(t_game *game);
void	check_images(t_game *game);
void	check_empty_map(t_game *game, int fd);
void	check_mapfile(t_game *game, char *map);
char	**fill_map(t_map *map, int *x, int *y);
void	fill_algo(char **ffill_map, int x, int y, int *reach);
int		ft_strlen2d(char **str);
void	flood_fill(t_game *game, t_map *map);
void	map_height(char *mapfile, t_map *map);
void	map_width(char *mapfile, t_map *map);
int		item_validity(t_map *map, char c, int i, int j);
void	map_validity(t_map *map, t_game *game);
t_map	*set_map(char *mapfile, t_game *game);
void	move_p(t_game *game, int x, int y);
int		move(int keycode, void *parameter);
void	fill__image(t_game *game, int w, int h);
void	fill_elements(t_game *game, char c, int x, int y);
void	render_map(t_game *game);
void	render_game(t_game *game);
void	so_long(char *mapfile);
void	free2d(char	**str);
void	free_game_map(t_game *game, t_map *map);
int		destroy_game(void *arg);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif
