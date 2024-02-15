/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:16:29 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/15 13:41:11 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_get_read_len(const char *path)
{
	int		fd;
	ssize_t	sz;
	size_t	i;
	char	str[1024];

	fd = open(path, O_RDONLY);
	sz = 1;
	i = 0;
	while (sz > 0)
	{
		sz = read(fd, str, 1024);
		if (sz == -1)
		{
			close(fd);
			ft_putstr_fd("Error\n\tRead error\n", 2);
			exit(1);
		}
		i += sz;
	}
	close(fd);
	return (i);
}

static char	*ft_read(const char *path)
{
	char	*str;
	size_t	size;
	int		fd;
	ssize_t	sz;

	size = ft_get_read_len(path);
	if (size == 0)
		return (NULL);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
	{
		ft_putstr_fd("Error\n\tMalloc error\n", 2);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	sz = read(fd, str, size);
	close(fd);
	if (sz == -1)
	{
		free(str);
		ft_putstr_fd("Error\n\tRead error\n", 2);
		exit(1);
	}
	return (str);
}

static int	ft_check_double_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || !str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse(const char *path, t_map *map)
{
	char	*str;

	str = ft_read(path);
	if (ft_check_double_nl(str))
	{
		free(str);
		ft_putstr_fd("Error\n\tMap not valid\n", 2);
		exit(1);
	}
	map->map = ft_split(str, '\n');
	free(str);
	if (!map->map)
	{
		free(str);
		ft_putstr_fd("Error\n\tSplit error\n", 2);
		exit(1);
	}
	if (ft_check_map(map))
	{
		ft_free_tab(map->map);
		ft_putstr_fd("Error\n\tMap not valid\n", 2);
		exit(1);
	}
	return (0);
}