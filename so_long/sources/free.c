/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:51:23 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/07 15:30:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free2d(char	**str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_game_map(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (map->mapfill[i] != NULL)
	{
		free(map->mapfill[i]);
		i++;
	}
	free(map->mapfill);
	free(map);
	free(game);
	exit(1);
}

int	destroy_game(void *arg)
{
	t_game	*game;

	game = arg;
	mlx_destroy_image(game->mlx, game->character->character);
	free(game->character);
	mlx_destroy_image(game->mlx, game->sea);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->weed);
	mlx_destroy_image(game->mlx, game->deadf);
	mlx_destroy_image(game->mlx, game->alive);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game_map(game, game->map);
	return (1);
}
