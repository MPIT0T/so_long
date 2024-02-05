/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   main.c                                             :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2024/01/30 14:32:35 by mpitot            #+#    #+#             *//*   Updated: 2024/01/30 16:45:06 by mpitot           ###   ########.fr       *//*                                                                            *//* ************************************************************************** */# include "so_long.h"int	ft_map_errors(t_map *map){	map->x = ft_strlen(map->map[map->y]);	map->y = 0;	while (map->map[map->y])	{		if (ft_strlen(map->map[map->y]) != map->x)			return (1);		map->y++;	}	return (0);}size_t	ft_get_file_len(const char *path){	ssize_t	sz;	size_t	i;	char	tmp;	int		fd;	sz = 1;	i = 0;	fd = open(path, O_RDONLY);	while (sz > 0)	{		sz = read(fd, &tmp, 1);		i++;	}	close(fd);	return (i);}int	ft_parse(char *path, t_map *map){	char	*str;	size_t	size;	ssize_t	sz;	int		fd;	size = ft_get_file_len(path);	str = malloc(sizeof(char) * (size + 1));	if (!str)		return (1);	fd = open(path, O_RDONLY);	sz = read(fd, str, size);	close(fd);	if (sz < 0)		return (free(str), 1);	str[sz] = '\0';	map->map = ft_split(str, '\n');	free(str);	if (!map->map)		return (1);	if (ft_map_errors(map))		return (ft_free_tab(map->map), 1);	return (0);}int	main(void){	t_map	map;	size_t	i;	if (ft_parse("map.ber", &map))		return (ft_printf("1"));	i = 0;	while (map.map[i])	{		ft_printf("%s\n", map.map[i++]);	}	return (0);}