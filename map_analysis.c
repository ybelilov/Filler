/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:36:07 by ybelilov          #+#    #+#             */
/*   Updated: 2017/05/17 17:36:11 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			minimum_distance_search(t_main *main)
{
	int			i;
	int			j;
	long double	a;

	i = -1;
	while (++i < main->map_h)
	{
		j = -1;
		while (++j < main->map_w)
		{
			if (MAP[i][j] != main->player && MAP[i][j] != '.')
			{
				a = distance(main, i, j);
				if (a <= main->distance)
				{
					main->distance = a;
					main->backup_x = main->ret_x;
					main->backup_y = main->ret_y;
					if (main->ret_x == 0 && main->ret_y == 0)
						main->no = 1;
				}
			}
		}
	}
}

long double		distance(t_main *main, int y, int x)
{
	return (main->ret_x - x + main->p_x) * (main->ret_x - x + main->p_x) +
	(main->ret_y - y + main->p_y) * (main->ret_y - y + main->p_y);
}
