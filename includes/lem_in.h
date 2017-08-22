/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:52:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 11:33:42 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

//debug
# include <stdio.h>
# define DEB debug(__FILE__, __LINE__);
void				debug(char *file, int line);
void				putf(char *s, char *n);
//

typedef	struct s_lem_in_file	t_lem_in_file;
typedef struct s_lem_in_path	t_lem_in_path;
typedef struct s_lem_in_room	t_lem_in_room;
typedef struct s_lem_in_var		t_lem_in_var;
typedef struct s_lem_in_ant		t_lem_in_ant;

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
	int				value;
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

struct				s_lem_in_ant
{
	char			*name;
	int				escaped;
	t_lem_in_room	*position;
	t_lem_in_ant	*prev;
	t_lem_in_ant	*next;
};
/*
**	File manipulation functions
*/

t_lem_in_file		*stock_content(void);


/*
**	Parsing functions
*/

int					parse_content_light(t_lem_in_var *v, t_lem_in_file *file);
int					check_ants_nb(t_lem_in_var *v, char *s);
int					check_commands_and_comments(
					t_lem_in_var *v, t_lem_in_file **file);
int					check_if_str_identical(char *s1, char *s2);
int					check_if_room_or_path(char *s);
int					check_room(char *s);
int					check_path(char *s);
int					estimate_if_doable(t_lem_in_var *v);
int					parse_content_in_depth(t_lem_in_room *room);


/*
**	Linked lists manipulation functions
*/

void				init_t_lem_in_var(t_lem_in_var *v);
t_lem_in_file		*set_t_lem_in_file(t_lem_in_file *file, char *ptr);
int					rewind_t_lem_in_file(t_lem_in_file **file);
t_lem_in_room		*set_t_lem_in_room(
					t_lem_in_room *room, char *line, int is_start, int is_end);
int					rewind_t_lem_in_room(t_lem_in_room **room);
t_lem_in_path		*set_t_lem_in_path(t_lem_in_room *room, t_lem_in_path *path,
					char *target_room);
int					rewind_t_lem_in_path(t_lem_in_path **path);
t_lem_in_ant		*init_t_lem_in_ant(int ant_nb, t_lem_in_room *room);
t_lem_in_ant		*set_t_lem_in_ant(
					t_lem_in_ant *ant, int nb, t_lem_in_room *room);
int					rewind_t_lem_in_ant(t_lem_in_ant **ant);

/*
**	Core functions
*/

t_lem_in_room		*format_content_into_lst(t_lem_in_file *file);
int					add_path_to_room(t_lem_in_room *room, char *line);
int					apply_algorithm(t_lem_in_room *room);
void				print_file(t_lem_in_file *file);
int					find_and_print_solution(int ant_nb, t_lem_in_ant *ant);

/*
**	Error handling functions
*/

int					handle_error();

#endif
