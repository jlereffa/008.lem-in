/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:52:10 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 10:52:56 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 10

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	void			*data;
	size_t			data_size;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_gnl
{
	int				fd;
	int				ret;
	char			buf[BUFF_SIZE];
	char			*rest;
	char			*tmp;
	char			*ptr;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_find_charset(const char *str, const char *charset);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
char				*ft_strdup_c(char *s, char c);
char				*ft_strdup_n(char *s, unsigned int n);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrealloc(char **str, size_t new_size);
char				*ft_strrealloc_more(char **str, size_t more_bytes);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *hay, const char *needle, size_t n);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_charset(char *str, char *charset);
char				**ft_array_realloc(char ***array, size_t new_size);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putnbr_endl(int n);
void				ft_putchar_endl(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_del_array(char ***array);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_print_words_table(char **array);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				*ft_memalloc(size_t size);
void				*ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
t_lst				*ft_strsplit_lst(char *str, char c);
t_lst				*ft_strsplit_whitespaces_lst(char *str);
t_lst				*ft_strsplit_charset_lst(char *str, char *charset);
t_lst				*ft_set_lst(t_lst *lst, void *data, size_t data_size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_set_list(t_list *lst, void *content, size_t size);

int					get_next_line(int fd, char **line);
#endif
