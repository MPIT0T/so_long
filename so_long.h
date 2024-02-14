/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:16 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/13 16:00:15 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/incs/libft.h"
# include <stdbool.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

typedef struct s_player
{
	size_t	x;
	size_t	y;
	int		facing;
	char	*image;
}	t_player;

typedef struct	s_map
{
	size_t	line_len;
	size_t	line_count;
	size_t	player_x;
	size_t	player_y;
	char	**map;
	bool	door_open;

}	t_map;

typedef struct	s_collectible
{
	size_t	x;
	size_t	y;

}	t_collectible;

#endif
