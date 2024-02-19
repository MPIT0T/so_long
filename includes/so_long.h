/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:16 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/19 12:02:43 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/incs/libft.h"
# include <stdbool.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct s_map
{
	size_t	line_len;
	size_t	line_count;
	size_t	p_x;
	size_t	p_y;
	size_t	c_count;
	char	**map;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	t_map	*map;
	bool	victory;
	size_t	move_count;
}	t_vars;

int		ft_parse(const char *path, t_map *map);
int		ft_solvable(t_map *map);
int		ft_check_map(t_map *map);

void	ft_mlx(t_vars *vars);
int		close_window(t_vars *vars);

void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

#endif
