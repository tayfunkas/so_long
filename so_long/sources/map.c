/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:01:46 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(char *mapfile, t_map *map)
{
	char	*str;
	int		fd;

	map->height = 0;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->height++;
		free(str);
		str = NULL;
	}
	free(str);
	map->mapfill = malloc(sizeof(char *) * (map->height + 1));
	map->mapfill[map->height] = NULL;
	close(fd);
}

void	map_width(char *mapfile, t_map *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	while (i < map->height)
	{
		str = get_next_line(fd);
		map->mapfill[i] = malloc(ft_strlen(str) + 1);
		j = 0;
		while (str[j] && str[j] != '\n')
		{
			map->mapfill[i][j] = str[j];
			j++;
		}
		map->mapfill[i][j] = '\0';
		free(str);
		str = NULL;
		i++;
	}
	close(fd);
}

int	item_validity(t_map *map, char c, int i, int j)
{
	map->won = 0;
	if (c != 'C' && c != 'P' && c != '1' && c != '0' && c != 'E')
	{
		printf("Error\nInvalid map.\n");
		return (1);
	}
	if ((i == 0 || j == 0 || i == map->height - 1 || j == map->width) 
		&& (c != '1'))
	{
		printf("Error\nInvalid map.\n");
		return (1);
	}
	if (c == 'C')
		map->weed++;
	if (c == 'P')
		map->player++;
	if (c == 'E')
		map->deadf++;
	return (0);
}

void	map_validity(t_map *map, t_game *game)
{
	int		i;
	size_t	len;
	int		j;

	map->weed = 0;
	map->player = 0;
	map->deadf = 0;
	len = ft_strlen(map->mapfill[0]);
	map->width = len;
	i = -1;
	while (++i < map->height)
	{
		if (ft_strlen(map->mapfill[i]) != len)
		{
			printf("Error\nInvalid map.\n");
			free_game_map(game, map);
			exit(1);
		}
		j = -1;
		while (map->mapfill[i][++j])
		{
			if (item_validity(map, map->mapfill[i][j], i, j) == 1)
				free_game_map(game, map);
		}
	}
}

t_map	*set_map(char *mapfile, t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map_height(mapfile, map);
	map_width(mapfile, map);
	map_validity(map, game);
	if (map->weed == 0 || map->player != 1 || map->deadf != 1)
	{
		printf("Error\nInvalid map.\n");
		free_game_map(game, map);
		exit(1);
	}
	flood_fill(game, map);
	return (map);
}
