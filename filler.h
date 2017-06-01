/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:09:36 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/30 12:09:40 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "libft/ft_printf.h"
# define MAP main->map
# define PAT main->pat
# define M_X 0
# define M_Y 1
# define P_X 2
# define P_Y 3
# define ST_X 0
# define ST_Y 1
# define SP_X 2
# define SP_Y 3
# define TRUE 1
# define FALSE 0

typedef	struct	s_main
{
	char		player;
	int			map_w;
	int			map_h;
	char		**map;
	int			pat_w;
	int			pat_h;
	char		**pat;
	int			not_first;
	int			backup_x;
	int			backup_y;
	long double	distance;
	int			ret_x;
	int			ret_y;
	int			no;
	int			p_x;
	int			p_y;
}				t_main;

void			ft_clean_main(t_main *main);
void			input_data(t_main *main);
void			map_param(t_main *main);
void			pat_param(t_main *main);
void			map_or_pat_size(int *width, int *height);
int				ft_put_pat(t_main *main);
int				ft_try_put(t_main *main, int y, int x);
int				ft_try_this_position(t_main *main, int *arr, int p_x, int p_y);
void			minimum_distance_search(t_main *main);
long double		distance(t_main *main, int y, int x);
#endif
