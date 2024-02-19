/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:24:48 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/19 12:13:53 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_img(t_vars *vars, size_t x, size_t y)
{
	int		sz;

	sz = 32;
	if (vars->map->map[y][x] == '1')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/wall.xpm", &sz, &sz);
	if (vars->map->map[y][x] == '0')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/water.xpm", &sz, &sz);
	if (vars->map->map[y][x] == 'C')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/pufferfish.xpm", &sz, &sz);
	if (vars->map->map[y][x] == 'E' && vars->map->c_count != 0)
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/exit_close.xpm", &sz, &sz);
	if (vars->map->map[y][x] == 'E' && vars->map->c_count == 0)
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/exit_open.xpm", &sz, &sz);
	if (vars->map->map[y][x] == 'P')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/dolphin.xpm", &sz, &sz);
	if (vars->map->map[y][x] == 'A')
		vars->img->img = mlx_xpm_file_to_image(vars->mlx,
				"textures/dolphin_on_exit.xpm", &sz, &sz);
}

void	ft_gen_map(t_vars *vars)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < vars->map->line_count)
	{
		x = -1;
		while (++x < vars->map->line_len)
		{
			ft_get_img(vars, x, y);
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img->img, x * 32, y * 32);
			mlx_destroy_image(vars->mlx, vars->img->img);
		}
	}
}

int	close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	event_manager(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	if (keycode == 'w')
		move_up(vars);
	if (keycode == 'a')
		move_left(vars);
	if (keycode == 's')
		move_down(vars);
	if (keycode == 'd')
		move_right(vars);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		ft_gen_map(vars);
	return (0);
}

void	ft_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_free_tab(vars->map->map);
		ft_putstr_fd("Error\n\tMiniLibX error", 2);
		exit(1);
	}
	vars->mlx_win = mlx_new_window(vars->mlx, (vars->map->line_len) * 32,
			(vars->map->line_count) * 32, "So looooong");
	ft_gen_map(vars);
	mlx_hook(vars->mlx_win, 17, 1L << 0, close_window, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, event_manager, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	ft_free_tab(vars->map->map);
	free(vars->mlx);
}
