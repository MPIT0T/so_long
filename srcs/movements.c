/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:55:54 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/18 21:11:30 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map->map[vars->map->p_y - 1][vars->map->p_x] == '1')
		return ;
	if (vars->map->map[vars->map->p_y - 1][vars->map->p_x] == 'E')
	{
		if (!vars->map->c_count)
		{
			ft_printf("You Win !\t");
			close_window(vars);
		}
		vars->map->map[vars->map->p_y - 1][vars->map->p_x] = 'A';
		vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
	}
	else if (vars->map->map[vars->map->p_y - 1][vars->map->p_x] == '0'
	|| vars->map->map[vars->map->p_y - 1][vars->map->p_x] == 'C')
	{
		if (vars->map->map[vars->map->p_y - 1][vars->map->p_x] == 'C')
			vars->map->c_count--;
		vars->map->map[vars->map->p_y - 1][vars->map->p_x] = 'P';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'P')
			vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'A')
			vars->map->map[vars->map->p_y][vars->map->p_x] = 'E';
	}
	vars->map->p_y--;
	ft_printf("Moves count: %d\n", ++vars->move_count);
}

void	move_down(t_vars *vars)
{
	if (vars->map->map[vars->map->p_y + 1][vars->map->p_x] == '1')
		return ;
	if (vars->map->map[vars->map->p_y + 1][vars->map->p_x] == 'E')
	{
		if (!vars->map->c_count)
		{
			ft_printf("You Win !\t");
			close_window(vars);
		}
		vars->map->map[vars->map->p_y + 1][vars->map->p_x] = 'A';
		vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
	}
	else if (vars->map->map[vars->map->p_y + 1][vars->map->p_x] == '0'
	|| vars->map->map[vars->map->p_y + 1][vars->map->p_x] == 'C')
	{
		if (vars->map->map[vars->map->p_y + 1][vars->map->p_x] == 'C')
			vars->map->c_count--;
		vars->map->map[vars->map->p_y + 1][vars->map->p_x] = 'P';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'P')
			vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'A')
			vars->map->map[vars->map->p_y][vars->map->p_x] = 'E';
	}
	vars->map->p_y++;
	ft_printf("Moves count: %d\n", ++vars->move_count);
}

void	move_left(t_vars *vars)
{
	if (vars->map->map[vars->map->p_y][vars->map->p_x - 1] == '1')
		return ;
	if (vars->map->map[vars->map->p_y][vars->map->p_x - 1] == 'E')
	{
		if (!vars->map->c_count)
		{
			ft_printf("You Win !\t");
			close_window(vars);
		}
		vars->map->map[vars->map->p_y][vars->map->p_x - 1] = 'A';
		vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
	}
	else if (vars->map->map[vars->map->p_y][vars->map->p_x - 1] == '0'
	|| vars->map->map[vars->map->p_y][vars->map->p_x - 1] == 'C')
	{
		if (vars->map->map[vars->map->p_y][vars->map->p_x - 1] == 'C')
			vars->map->c_count--;
		vars->map->map[vars->map->p_y][vars->map->p_x - 1] = 'P';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'P')
			vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'A')
			vars->map->map[vars->map->p_y][vars->map->p_x] = 'E';
	}
	vars->map->p_x--;
	ft_printf("Moves count: %d\n", ++vars->move_count);
}

void	move_right(t_vars *vars)
{
	if (vars->map->map[vars->map->p_y][vars->map->p_x + 1] == '1')
		return ;
	if (vars->map->map[vars->map->p_y][vars->map->p_x + 1] == 'E')
	{
		if (!vars->map->c_count)
		{
			ft_printf("You Win !\t");
			close_window(vars);
		}
		vars->map->map[vars->map->p_y][vars->map->p_x + 1] = 'A';
		vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
	}
	else if (vars->map->map[vars->map->p_y][vars->map->p_x + 1] == '0'
	|| vars->map->map[vars->map->p_y][vars->map->p_x + 1] == 'C')
	{
		if (vars->map->map[vars->map->p_y][vars->map->p_x + 1] == 'C')
			vars->map->c_count--;
		vars->map->map[vars->map->p_y][vars->map->p_x + 1] = 'P';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'P')
			vars->map->map[vars->map->p_y][vars->map->p_x] = '0';
		if (vars->map->map[vars->map->p_y][vars->map->p_x] == 'A')
			vars->map->map[vars->map->p_y][vars->map->p_x] = 'E';
	}
	vars->map->p_x++;
	ft_printf("Moves count: %d\n", ++vars->move_count);
}
