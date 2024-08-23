/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:22:33 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *mapfile)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	check_images(game);
	check_alive_character(game);
	check_mapfile(game, mapfile);
	game->map = set_map(mapfile, game);
	render_game(game);
	mlx_hook(game->win, 2, (1L << 0), move, game);
	mlx_hook(game->win, 17, 0, destroy_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
	{
		printf("Error\nThe game requires a single argument.\n");
		return (1);
	}
	return (0);
}
