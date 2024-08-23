/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:30:46 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/07 15:30:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_image(t_game *game, int w, int h)
{
	game->height = game->map->height * 32;
	game->width = game->map->width * 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->sea = mlx_xpm_file_to_image(game->mlx, "./image/sea.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./image/wall.xpm", &w, &h);
	game->weed = mlx_xpm_file_to_image(game->mlx, "./image/weed.xpm", &w, &h);
	game->deadf = mlx_xpm_file_to_image(game->mlx, "./image/deadf.xpm", &w, &h);
	game->alive = mlx_xpm_file_to_image(game->mlx, "./image/alive.xpm", &w, &h);
	game->character = ft_calloc(1, sizeof(t_character));
	game->character->x = 0;
	game->character->y = 0;
	game->character->points = 0;
	game->character->character = mlx_xpm_file_to_image(game->mlx, 
			"./image/character.xpm", &w, &h);
}

void	fill_elements(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sea, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->weed, x, y);
	else if (c == 'E')
	{
		game->map->deadfx = x;
		game->map->deadfy = y;
		if (game->map->weed > 0)
			mlx_put_image_to_window(game->mlx, game->win, game->deadf, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->alive, x, y);
	}
	else if (c == 'P')
	{
		game->character->x = x;
		game->character->y = y;
		mlx_put_image_to_window(game->mlx, game->win, 
			game->character->character, x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (game->map->mapfill[i])
	{
		j = 0;
		x = 0;
		while (game->map->mapfill[i][j])
		{
			fill_elements(game, game->map->mapfill[i][j], x, y);
			x = x + 32;
			j++;
		}
		y = y + 32;
		i++;
	}
}

void	render_game(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	fill_image(game, w, h);
	render_map(game);
}
