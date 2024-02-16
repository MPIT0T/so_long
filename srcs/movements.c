/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:55:54 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/16 14:55:54 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map.map[vars->map.player_y - 1][vars->map.player_x] == '1')
		return ;
	if (vars->map.map[vars->map.player_y - 1][vars->map.player_x] == 'E' && vars->map.door_open)
	{
		ft_printf("You Win !");
		close_window(vars);
	}
	else if (vars->map.map[vars->map.player_y - 1][vars->map.player_x] == 'E')
	{
		vars->map.map[vars->map.player_y - 1][vars->map.player_x] = 'A';
		vars->map.map[vars->map.player_y][vars->map.player_x] = '0';
	}
	else if (vars->map.map[vars->map.player_y - 1][vars->map.player_x] == '0' || vars->map.map[vars->map.player_y - 1][vars->map.player_x] == 'C')
	{
		if (vars->map.map[vars->map.player_y - 1][vars->map.player_x] == 'C')
			vars->map.c_count--;
		vars->map.map[vars->map.player_y - 1][vars->map.player_x] = 'P';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'P')
			vars->map.map[vars->map.player_y - 1][vars->map.player_x] = '0';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'A')
			vars->map.map[vars->map.player_y - 1][vars->map.player_x] = 'E';
	}
	vars->map.player_y--;
}

void	move_down(t_vars *vars)
{
	if (vars->map.map[vars->map.player_y + 1][vars->map.player_x] == '1')
		return ;
	if (vars->map.map[vars->map.player_y + 1][vars->map.player_x] == 'E' && vars->map.door_open)
	{
		ft_printf("You Win !");
		close_window(vars);
	}
	else if (vars->map.map[vars->map.player_y + 1][vars->map.player_x] == 'E')
	{
		vars->map.map[vars->map.player_y + 1][vars->map.player_x] = 'A';
		vars->map.map[vars->map.player_y][vars->map.player_x] = '0';
	}
	else if (vars->map.map[vars->map.player_y + 1][vars->map.player_x] == '0' || vars->map.map[vars->map.player_y + 1][vars->map.player_x] == 'C')
	{
		if (vars->map.map[vars->map.player_y + 1][vars->map.player_x] == 'C')
			vars->map.c_count--;
		vars->map.map[vars->map.player_y + 1][vars->map.player_x] = 'P';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'P')
			vars->map.map[vars->map.player_y + 1][vars->map.player_x] = '0';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'A')
			vars->map.map[vars->map.player_y + 1][vars->map.player_x] = 'E';
	}
	vars->map.player_y++;
}

void	move_left(t_vars *vars)
{
	if (vars->map.map[vars->map.player_y][vars->map.player_x - 1] == '1')
		return ;
	if (vars->map.map[vars->map.player_y][vars->map.player_x - 1] == 'E' && vars->map.door_open)
	{
		ft_printf("You Win !");
		close_window(vars);
	}
	else if (vars->map.map[vars->map.player_y][vars->map.player_x - 1] == 'E')
	{
		vars->map.map[vars->map.player_y][vars->map.player_x - 1] = 'A';
		vars->map.map[vars->map.player_y][vars->map.player_x] = '0';
	}
	else if (vars->map.map[vars->map.player_y][vars->map.player_x - 1] == '0' || vars->map.map[vars->map.player_y][vars->map.player_x - 1] == 'C')
	{
		if (vars->map.map[vars->map.player_y][vars->map.player_x - 1] == 'C')
			vars->map.c_count--;
		vars->map.map[vars->map.player_y][vars->map.player_x - 1] = 'P';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'P')
			vars->map.map[vars->map.player_y][vars->map.player_x - 1] = '0';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'A')
			vars->map.map[vars->map.player_y][vars->map.player_x - 1] = 'E';
	}
	vars->map.player_x--;
}

void	move_right(t_vars *vars)
{
	if (vars->map.map[vars->map.player_y][vars->map.player_x + 1] == '1')
		return ;
	if (vars->map.map[vars->map.player_y][vars->map.player_x + 1] == 'E' && vars->map.door_open)
	{
		ft_printf("You Win !");
		close_window(vars);
	}
	else if (vars->map.map[vars->map.player_y][vars->map.player_x + 1] == 'E')
	{
		vars->map.map[vars->map.player_y][vars->map.player_x + 1] = 'A';
		vars->map.map[vars->map.player_y][vars->map.player_x] = '0';
	}
	else if (vars->map.map[vars->map.player_y][vars->map.player_x + 1] == '0' || vars->map.map[vars->map.player_y][vars->map.player_x + 1] == 'C')
	{
		if (vars->map.map[vars->map.player_y][vars->map.player_x + 1] == 'C')
			vars->map.c_count--;
		vars->map.map[vars->map.player_y][vars->map.player_x + 1] = 'P';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'P')
			vars->map.map[vars->map.player_y][vars->map.player_x + 1] = '0';
		if (vars->map.map[vars->map.player_y][vars->map.player_x] == 'A')
			vars->map.map[vars->map.player_y][vars->map.player_x + 1] = 'E';
	}
	vars->map.player_x++;
}
