/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/15 13:43:34 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_checkstr(t_map *map, size_t	*vars)
{
	char	c;
	size_t	i;

	if (map->line_len != ft_strlen(map->map[map->line_count]))
		return (1);
	i = -1;
	while (++i < map->line_len)
	{
		c = map->map[map->line_count][i];
		if ((i == 0 && c != '1') || (i == map->line_len - 1 && c != '1'))
			return (1);
		if (c == 'E')
			vars[1]++;
		if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
			return (1);
		if (c == 'P')
		{
			map->player_x = i;
			map->player_y = map->line_count;
			vars[0]++;
		}
	}
	map->line_count++;
	return (0);
}

static int	ft_wall(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_map(t_map *map)
{
	size_t	vars[2];

	map->line_len = ft_strlen(map->map[0]);
	map->line_count = 0;
	vars[0] = 0;
	vars[1] = 0;
	if (ft_wall(map->map[0]))
		return (1);
	while (map->map[map->line_count])
	{
		if (ft_checkstr(map, vars))
			return (1);
	}
	if (ft_wall(map->map[map->line_count - 1]))
		return (1);
	if (vars[0] != 1 || vars[1] != 1)
		return (1);
	return (ft_solvable(map));
}
