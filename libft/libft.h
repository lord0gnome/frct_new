/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:39:30 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/01 16:45:10 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_i_list
{
	int				content;
	struct s_i_list	*next;
}					t_i_list;

int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, void const *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strcpy(char *src, const char *dst);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *src, const char *dst, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));
int					ft_isspace(char c);
char				**ft_split(char *s);
int					ft_countw(char *str);
void				ft_lastword(char *str);
int					ft_max(int *tab, unsigned int len);
void				ft_strexpand(char *str);
size_t				ft_lstlen(t_list **first);
t_list				*ft_sort_list(t_list *lst, int(*cmp)(int, int));
int					*ft_range(int start, int end);
void				ft_wait(double time);
int					ft_abs(int n);
void				ft_sort_tab(int *tab, unsigned int size);
int					ft_nbrlen(int nbr);


#endif
