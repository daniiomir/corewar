/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:46:18 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_double_linked_list
{
	void						*content;
	size_t						content_size;
	struct s_double_linked_list	*next;
	struct s_double_linked_list	*prev;
}					t_dlist;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
ssize_t				ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int a);
int					ft_isprint(int a);
int					ft_isascii(int a);
int					ft_isalnum(int a);
int					ft_isalpha(int a);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
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
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(long long int n);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_rejoin(char *s1, char const *s2);
int					get_next_line(const int fd, char **line);
void				ft_lsthead_del(t_list **head);
void				ft_lstadd_end(t_list **val_list, t_list *new);
void				ft_addnode(t_list **val_list, char *buffer, int size);

void				ft_addnode_dlist(t_dlist **val_list, char *buffer,
	int size);
void				ft_dlisthead_del(t_dlist **head);
void				ft_dlistadd_end(t_dlist **val_list, t_dlist *new);
t_dlist				*ft_dlist_new(void const *content, size_t content_size);
void				ft_free_dlist(t_dlist *list);
void				ft_free_list(t_list *list);
char				*ft_itoa_base(unsigned long long int value, int base);
int					ft_abs(int nb);
char				*ft_strlower(char *string);
char				*ft_strupper(char *string);
char				*ft_strjoin_free2(char *s1, char *s2);
char				*ft_strjoin_free_all(char *s1, char *s2);
int					ft_search_helper(const char *string, char search);
void				ft_strset(char *string, size_t len, char c);
size_t				ft_count_words(const char *s, char c);

typedef struct		s_pf
{
	char			flag;
	int				wide;
	int				prec;
	char			mode;
	char			type;
	char			sign;
	char			*arg;
	char			proc;
	int				dot;
	int				b;
	int				len;
	int				malloc;
	int				wst;
}					t_pf;

void				ft_putstr_printf(char const *s, t_pf **pf);
void				flag_digit(va_list ap, t_pf **pf);
void				flag_str(va_list ap, t_pf **pf);
void				flag_percent(t_pf **pf);
void				flag_double(va_list ap, t_pf **pf);
void				add_flag(t_pf **pf, const char *str);
void				add_wide(va_list ap, t_pf **pf, const char *str, int *a);
int					add_prec(va_list ap, t_pf **pf, const char *str, int *a);
void				add_mode(t_pf **pf, const char *str, int *a);
void				final_print(t_pf **pf);
void				final_print_c(t_pf **pf);
t_pf				*pf_new();

#endif
