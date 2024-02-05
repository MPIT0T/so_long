/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:16 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/30 15:17:18 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
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
	size_t	x;
	size_t	y;
	char	**map;
	bool	door_open;

}	t_map;

typedef struct	s_collectible
{
	size_t	x;
	size_t	y;

}	t_collectible;

#endif
