/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:52:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 20:36:43 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

//debug
# define DEB debug(__FILE__, __LINE__);
void				debug(char *file, int line);
//

typedef	struct s_lem_in_file	t_lem_in_file;
typedef struct s_lem_in_path	t_lem_in_path;
typedef struct s_lem_in_room	t_lem_in_room;
typedef struct s_lem_in_var		t_lem_in_var;

struct				s_lem_in_file
{
	char			*line;
	t_lem_in_file	*prev;
	t_lem_in_file	*next;
};

struct				s_lem_in_path
{
	t_lem_in_room	*room;
	t_lem_in_path	*prev;
	t_lem_in_path	*next;
};

struct				s_lem_in_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				is_start;
	int				is_end;
	t_lem_in_path	*path;
	t_lem_in_room	*prev;
	t_lem_in_room	*next;
};

struct				s_lem_in_var
{
	int				ants_nb;
	int				stated_start;
	int				stated_end;
	int				has_room;
	int				has_path;
};

/*
**	File manipulation functions
*/

t_lem_in_file		*stock_content(void);


/*
**	Parsing functions
*/

int					parse_content(t_lem_in_var *v, t_lem_in_file *file);
int					check_ants_nb(t_lem_in_var *v, char *s);
int					check_commands_and_comments(
					t_lem_in_var *v, t_lem_in_file *file);
int					check_if_str_strictly_identical(char *s1, char *s2);
int					check_if_room_or_path(char *s);
int					check_room(char *s);
int					check_path(char *s);
int					estimate_if_doable(t_lem_in_var *v);

/*
**	Linked lists manipulation functions
*/

void				init_t_lem_in_var(t_lem_in_var *v);
t_lem_in_file		*set_t_lem_in_file(t_lem_in_file *file, char *ptr);
int					rewind_t_lem_in_file(t_lem_in_file **file);
/*
**	Error handling functions
*/

int					handle_error(void);

#endif
