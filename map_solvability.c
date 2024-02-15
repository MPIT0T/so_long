/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvability.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:40:07 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/15 13:41:11 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_path_finding(char **copy, t_map *map, size_t	x, size_t y)
{
	if (copy[y][x] == '1' || copy[y][x] == '.')
		return ;
	copy[y][x] = '.';
	ft_path_finding(copy, map, x - 1, y);
	ft_path_finding(copy, map, x, y - 1);
	ft_path_finding(copy, map, x + 1, y);
	ft_path_finding(copy, map, x, y + 1);
}

static char	**ft_mapdup(t_map *map)
{
	size_t	i;
	char	**copy;

	copy = malloc(sizeof(char *) * (map->line_count + 1));
	if (!copy)
	{
		ft_free_tab(map->map);
		ft_putstr_fd("Error\n\tMalloc error\n", 2);
		exit(1);
	}
	i = -1;
	while (map->map[++i])
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			ft_free_tab(copy);
			ft_free_tab(map->map);
			ft_putstr_fd("Error\n\tMalloc error\n", 2);
			exit(1);
		}
	}
	return (copy[i] = NULL, copy);
}

int	ft_solvable(t_map *map)
{
	size_t	i;
	char	**copy;

	copy = ft_mapdup(map);
	ft_path_finding(copy, map, map->player_x, map->player_y);
	i = -1;
	while (copy[++i])
	{
		if (ft_strchr(copy[i], 'C') || ft_strchr(copy[i], 'E'))
			return (ft_free_tab(copy), 1);
	}
	return (ft_free_tab(copy), 0);
}
