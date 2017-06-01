/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:27:39 by ybelilov          #+#    #+#             */
/*   Updated: 2017/05/17 17:27:41 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	input_data(t_main *main)
{
	char *line;

	if (main->not_first == 1)
	{
		get_next_line(0, &line);
		main->player = line[10] == '1' ? 'O' : 'X';
		free(line);
	}
	map_param(main);
	pat_param(main);
}

void	map_param(t_main *main)
{
	char	*line;
	int		i;

	i = -1;
	map_or_pat_size(&main->map_w, &main->map_h);
	get_next_line(0, &line);
	free(line);
	main->map = (char**)malloc(sizeof(char*) * main->map_h);
	while (++i < main->map_h)
	{
		get_next_line(0, &line);
		main->map[i] = ft_strcpy(ft_strnew(main->map_w), &line[4]);
		free(line);
	}
}

void	pat_param(t_main *main)
{
	char	*line;
	int		i;

	i = -1;
	map_or_pat_size(&main->pat_w, &main->pat_h);
	main->pat = (char**)malloc(sizeof(char*) * main->pat_h);
	while (++i < main->pat_h)
	{
		get_next_line(0, &line);
		main->pat[i] = ft_strcpy(ft_strnew(main->pat_w), line);
		free(line);
	}
	while (++main->p_y < main->pat_h)
	{
		main->p_x = -1;
		while (++main->p_x < main->pat_w)
			if (PAT[main->p_y][main->p_x] == '*')
				break ;
	}
}

void	map_or_pat_size(int *width, int *height)
{
	char	*line;
	char	**split;

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	*height = ft_atoi(split[1]);
	*width = ft_atoi(split[2]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split[3]);
	free(split);
	free(line);
}
