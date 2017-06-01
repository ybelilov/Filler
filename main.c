/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:46:01 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/28 16:46:04 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_main	main;

	main.not_first = 0;
	while (1)
	{
		ft_clean_main(&main);
		input_data(&main);
		ft_put_pat(&main);
		ft_printf("%d %d\n", main.backup_y, main.backup_x);
		if (!main.backup_y && !main.backup_x && !main.no)
			break ;
	}
	return (0);
}

void	ft_clean_main(t_main *main)
{
	int i;

	main->not_first++;
	main->ret_x = 0;
	main->ret_y = 0;
	main->distance = 999999999;
	main->backup_x = 0;
	main->backup_y = 0;
	main->no = 0;
	main->p_y = -1;
	if (main->not_first == 1)
		return ;
	i = -1;
	while (++i < main->map_h)
		free(MAP[i]);
	free(MAP);
	i = -1;
	while (++i < main->pat_h)
		free(PAT[i]);
	free(PAT);
}
