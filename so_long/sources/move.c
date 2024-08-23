/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:15:06 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p(t_game *game, int x, int y)
{
	if (game->map->weed == 0 && game->map->mapfill[y / 32][x / 32] == 'E')
	{
		game->character->points++;
		printf("You have moved %d times\nYou WON!\n", game->character->points);
		game->map->won = 1;
	}
	if (game->map->mapfill[y / 32][x / 32] != '1' && (game->map->weed == 0 
		|| game->map->mapfill[y / 32][x / 32] != 'E'))
	{
		if (game->map->mapfill[y / 32][x / 32] == 'C')
			game->map->weed--;
		game->map->mapfill[y / 32][x / 32] = 'P';
		game->map->mapfill[game->character->y / 32]
		[game->character->x / 32] = '0';
		game->character->points++;
		if (game->map->won != 1)
			printf("You have moved %d times\n", game->character->points);
	}
}

int	move(int keycode, void *parameter)
{
	t_game	*game;

	game = parameter;
	mlx_clear_window(game->mlx, game->win);
	if (game->map->won != 1)
	{
		if (keycode == 65362)
			move_p(game, game->character->x, game->character->y - 32);
		if (keycode == 65364)
			move_p(game, game->character->x, game->character->y + 32);
		if (keycode == 65363)
			move_p(game, game->character->x + 32, game->character->y);
		if (keycode == 65361)
			move_p(game, game->character->x - 32, game->character->y);
	}
	if (keycode == 65307)
		destroy_game(game);
	render_map(game);
	return (keycode);
}
