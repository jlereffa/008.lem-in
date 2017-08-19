/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:52:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 11:01:12 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef	struct	s_lem_in_file	t_lem_in_file;
struct	s_lem_in_file
{
	char			*line;
	t_lem_in_file	*prev;
	t_lem_in_file	*next;
};

typedef struct s_lem_in_path	t_lem_in_path;
struct	s_lem_in_path
{
	t_lem_in_room	*room;
	t_lem_in_path	*prev;
	t_lem_in_path	*next;
};

typedef struct s_lem_in_room	t_lem_in_room;
struct	s_lem_in_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	t_lem_in_path	*path;
	t_lem_in_room	*prev;
	t_lem_in_room	*next;
};

#endif
