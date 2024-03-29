/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:37:13 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/04 02:01:59 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <limits.h>
# define BUFF_SIZE_GNL 4028

typedef struct		s_get
{
	struct s_get	*next;
	char			content[BUFF_SIZE_GNL];
	struct s_get	*fd_ptr[OPEN_MAX];
	int				first;
}					t_get;

typedef struct		s_list
{

	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_void
{
	struct s_void *next;
}					t_void;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *haystack, \
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strndup(char *src, size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstsize(t_list *begin_list);
int					ft_sqrt(int nb);
char				*ft_strrev(char *str);
void				ft_swap(void *a, void *b, size_t size);
int					ft_max(int a, int b);
char				*ft_strcapitalize(char *str);
char				*ft_itoa_base(int value, int base);
int					ft_abs(int a);
int					ft_strindex(const char *str, int c);
int					ft_strnindex(const char *str, int c, int n);
char				*ft_strcdup(const char *s1, int c);
int					ft_binsearch(const void *arr, const void *value,
					size_t size, size_t length);
t_list				*ft_lstadd_back(t_list **alst, void const *content,
					size_t content_size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_sortstrings(char **ptr, size_t size,
					int (*f)(char *, char *));
int					ft_min(int a, int b);
int					get_next_line(const int fd, char **line);
char				**ft_strsplitwhitespace(char *str);

int					size_list(void *a);
void				*last_elem(void *a);
int					str_alnum(char *str);
char				*ft_strjoin_multiple(int nb_args, ...);
void				delstr(int nb_args, ...);
void				del_arr(char ***arr);

# define MY_INT_MAX 2147483647
# define MY_INT_MIN -2147483648

#endif
