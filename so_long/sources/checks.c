/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:53:39 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_alive_character(t_game *game)
{
	int	alive;
	int	character;

	alive = open("./image/alive.xpm", O_RDWR);
	character = open("./image/character.xpm", O_RDWR);
	if (alive < 0 || character < 0)
	{
		close(alive);
		close(character);
		printf("Error\nImage file(s) missing\n");
		free(game);
		exit(1);
	}
	close(alive);
	close(character);
}

void	check_images(t_game *game)
{
	int	sea;
	int	wall;
	int	weed;
	int	deadf;

	sea = open("./image/sea.xpm", O_RDWR);
	wall = open("./image/wall.xpm", O_RDWR);
	weed = open("./image/weed.xpm", O_RDWR);
	deadf = open("./image/deadf.xpm", O_RDWR);
	check_alive_character(game);
	if (sea < 0 || wall < 0 || weed < 0 || deadf < 0)
	{
		close(sea);
		close(wall);
		close(weed);
		close(deadf);
		printf("Error\nImage file(s) missing\n");
		free(game);
		exit(1);
	}
	close(sea);
	close(wall);
	close(weed);
	close(deadf);
}

void	check_empty_map(t_game *game, int fd)
{
	char	buff;

	if (read(fd, &buff, 1) == 0)
	{
		printf("Error\nEmpty map.\n");
		free(game);
		exit(1);
	}
}

void	check_mapfile(t_game *game, char *map)
{
	int	len;
	int	fd;

	len = 0;
	while (map[len])
		len++;
	if (map[len - 4] != '.' || map[len - 3] != 'b' || map[len - 2] != 'e' 
		|| map[len - 1] != 'r')
	{
		printf("Error\nOnly .ber extension is accepted for maps\n");
		free(game);
		exit(1);
	}
	fd = open(map, O_RDWR);
	if (fd < 0)
	{
		printf("Error\nMap is not opened\n");
		free(game);
		exit(1);
	}
	check_empty_map(game, fd);
	close(fd);
}
