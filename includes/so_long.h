/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:16 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/15 17:12:30 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/incs/libft.h"
# include <stdbool.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct	s_map
{
	size_t	line_len;
	size_t	line_count;
	size_t	player_x;
	size_t	player_y;
	char	**map;
	bool	door_open;

}	t_map;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;
}	t_vars;

int		ft_parse(const char *path, t_map *map);
int	ft_solvable(t_map *map);
int	ft_check_map(t_map *map);

#endif
