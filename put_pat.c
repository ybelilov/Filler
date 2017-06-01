/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:40:03 by ybelilov          #+#    #+#             */
/*   Updated: 2017/05/17 17:40:05 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_put_pat(t_main *main)
{
	int x;
	int y;

	y = -1;
	while (++y < main->map_h)
	{
		x = -1;
		while (++x < main->map_w)
		{
			if (MAP[y][x] == main->player)
				ft_try_put(main, y, x);
		}
	}
	return (TRUE);
}

int		ft_try_put(t_main *main, int y, int x)
{
	int		*arr;

	arr = (int*)malloc(sizeof(int) * 4);
	arr[M_X] = x;
	arr[M_Y] = y;
	arr[P_Y] = -1;
	while (++arr[P_Y] < main->pat_h)
	{
		if (!ft_strchr(PAT[arr[P_Y]], '*'))
			continue;
		arr[P_X] = -1;
		while (++arr[P_X] < main->pat_w)
		{
			if (ft_try_this_position(main, arr, -1, -1))
			{
				main->ret_x = x - arr[P_X];
				main->ret_y = y - arr[P_Y];
				minimum_distance_search(main);
			}
		}
	}
	free(arr);
	return (TRUE);
}

int		ft_try_this_position(t_main *main, int *arr, int p_x, int p_y)
{
	int		touch;

	p_y = -1;
	touch = 0;
	if ((arr[M_X] - arr[P_X]) < 0 || (arr[M_X] + main->pat_w - arr[P_X]) >
		main->map_w || (arr[M_Y] - arr[P_Y]) < 0 ||
			(arr[M_Y] + main->pat_h - arr[P_Y]) > main->map_h)
		return (FALSE);
	while (++p_y < main->pat_h)
	{
		p_x = -1;
		while (++p_x < main->pat_w)
		{
			if (PAT[p_y][p_x] == '*' && MAP[arr[M_Y] - arr[P_Y] + p_y]
				[arr[M_X] - arr[P_X] + p_x] == main->player)
				touch++;
			if (PAT[p_y][p_x] == '*' && (MAP[arr[M_Y] - arr[P_Y] + p_y]
			[arr[M_X] - arr[P_X] + p_x] != main->player &&
			MAP[arr[M_Y] - arr[P_Y] + p_y][arr[M_X] - arr[P_X] + p_x] != '.'))
				return (FALSE);
		}
	}
	if (touch != 1)
		return (FALSE);
	return (TRUE);
}
