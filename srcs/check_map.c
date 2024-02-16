/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/15 13:57:26 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_checkstr(t_map *map, size_t	*doors)
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
			doors[1]++;
		if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
			return (1);
		if (c == 'P')
		{
			map->player_x = i;
			map->player_y = map->line_count;
			doors[0]++;
		}
		if (c == 'C')
			map->c_count++;
	}
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
	size_t	doors[2];

	map->line_len = ft_strlen(map->map[0]);
	map->line_count = 0;
	map->c_count = 0;
	map->door_open = 1;
	doors[0] = 0;
	doors[1] = 0;
	if (ft_wall(map->map[0]))
		return (1);
	while (map->map[map->line_count])
	{
		if (ft_checkstr(map, doors))
			return (1);
		map->line_count++;
	}
	if (ft_wall(map->map[map->line_count - 1]))
		return (1);
	if (doors[0] != 1 || doors[1] != 1)
		return (1);
	if (map->c_count)
		map->door_open = 0;
	return (ft_solvable(map));
}
