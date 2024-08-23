/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:49:39 by tkasapog          #+#    #+#             */
/*   Updated: 2024/08/23 10:27:50 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(t_map *map, int *x, int *y)
{
	char	**ffill_map;
	int		i;
	int		j;

	ffill_map = malloc(sizeof(char *) * (map->height + 1));
	ffill_map[map->height] = NULL;
	i = 0;
	while (i < map->height)
	{
		ffill_map[i] = malloc(map->width + 1);
		j = 0;
		while (map->mapfill[i][j])
		{
			if (map->mapfill[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			ffill_map[i][j] = map->mapfill[i][j];
			j++;
		}
		ffill_map[i][j] = '\0';
		i++;
	}
	return (ffill_map);
}

void	fill_algo(char **ffill_map, int x, int y, int *reach)
{
	int	height;
	int	width; 

	width = ft_strlen(ffill_map[0]);
	height = ft_strlen2d(ffill_map);
	if (x < 0 || x >= height || y < 0 || y >= width 
		|| ffill_map[x][y] == '1' || ffill_map[x][y] == 'v')
		return ;
	if (ffill_map[x][y] == 'C' || ffill_map [x][y] == 'E')
		(*reach)++; 
	ffill_map[x][y] = 'v';
	fill_algo(ffill_map, x + 1, y, reach);
	fill_algo(ffill_map, x - 1, y, reach);
	fill_algo(ffill_map, x, y + 1, reach);
	fill_algo(ffill_map, x, y - 1, reach);
}

void	flood_fill(t_game *game, t_map *map)
{
	char	**ffill_map;
	int		reach;
	int		x;
	int		y;

	reach = 0;
	x = 0;
	y = 0;
	ffill_map = fill_map(map, &x, &y);
	fill_algo(ffill_map, x, y, &reach);
	free2d(ffill_map);
	if (map->weed + 1 != reach)
	{
		printf("Error\nInvalid map.\n");
		free_game_map(game, map);
		exit(1);
	}
}

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
