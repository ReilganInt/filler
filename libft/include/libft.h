/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:18:04 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/11 05:34:06 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
**  This structure and prototype is about creating a function that, allows to
** read a line ending with a newline character ('\n')from a file descriptor,
** without knowing its size beforehand. One of the goal of this project is to
** learn a highly interesting new concept in C programming: static variables,
** and to gain a deeper understanding of allocations, whether they happen on
** the stack memory or in the heap memory, the manipulation and the life cycle
** of a buffer, the unexpected complexity implied in the use of one or many
** static variables.
*/

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fd
{
	int				fd;
	int				state;
	size_t			numlines;
	t_list			*res;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

/*
**  This structure and prototype seeks to discover variadic functions in C
** in a particularly relevant context, as well as to learn about a great
** example of a basic “dispatcher” in C via the use of an array of
** function’s pointers. This projects represents a good exercise in
** programming, because of printf's versatility in C. The key to a
** successful ft_printf is a well-structured and good extensible code.
*/

# define MAX_INT 922337203685477580
# define BUF_SIZE 1000
# define BASE 10


typedef struct		s_param
{
	unsigned char	length;
	char			minus;
	char			plus;
	char			zero;
	char			hasht;
	char			space;
	int				width;
	int				precision;
}					t_param;

t_param				*ft_param_new(void);
int					ft_param_add(t_param *new, char **str, va_list ap);
void				ft_param_nul(t_param *param);

typedef struct		s_buf
{
	size_t			top;
	size_t			size;
	int				err;
	char			*buf;
}					t_buf;

t_buf				*ft_buf_new(t_buf *new);
void				ft_buf_add_c(t_buf *new, char c);
void				ft_buf_add_nc(t_buf *new, wchar_t c);
void				ft_buf_add_s(t_buf *new, char *str, int flag);
void				ft_buf_add_ns(t_buf *new, char *str, size_t n,
int flag);
int					ft_do_buf_empty(t_buf *buf);

typedef struct		s_lnum
{
	char			ar[100];
	int				size;
}					t_lnum;

void				ft_lnum_new(t_lnum *a);
void				ft_lnum_plus(t_lnum *a, t_lnum b);
void				ft_lnum_plus2(t_lnum *a, int b);
void				ft_lnum_mul(t_lnum *a, int b);

int					ft_printf(char *str, ...);
void				ft_percent(va_list ap, char **str,
		t_param list, t_buf *buf);

int					ft_print_symb(int c, int size);
int					ft_num_dig(uintmax_t n, int base);
char				*un(char *main, char *s);
int					max(int a, int b);

void				ft_bzero(void *s, size_t n);
void				ft_c_up(t_param list, wchar_t c, t_buf *buf);
void				ft_c(t_param list, char c, t_buf *buf);
void				ft_s(t_param list, char *s, t_buf *buf);
void				ft_s_up(t_param list, wchar_t *s, t_buf *buf);
void				ft_p(t_param list, void *ptr, t_buf *buf);
void				ft_d(t_param list, va_list ap, t_buf *buf);
void				ft_d_up(t_param list, va_list ap, t_buf *buf);
void				ft_u(t_param list, va_list ap, t_buf *buf);
void				ft_u_up(t_param list, va_list ap, t_buf *buf);
void				ft_o(t_param list, va_list ap, t_buf *buf);
void				ft_o_up(t_param list, va_list ap, t_buf *buf);
void				prec_neg_null(char *str, t_param list, t_buf *buf);
void				prec_pos_null(t_param list, t_buf *buf);
void				ft_x(t_param list, va_list ap, t_buf *buf);
void				minus_pos_null(t_param list, int tmp, t_buf *buf);
void				minus_neg_null(t_param list, int tmp, t_buf *buf);
void				ft_prcnt(t_param list, t_buf *buf);
void				ft_x_up(t_param list, va_list ap, t_buf *buf);
void				ft_x(t_param list, va_list ap, t_buf *buf);
void				ft_f(t_param list, va_list ap, t_buf *buf);
void				ft_f_up(t_param list, va_list ap, t_buf *buf);
char				*ft_dota(long double f, int precision);
char				*ft_strchr(const char *s, int c);
char				*ft_detect_col(char *str, t_buf *buf);


/*
** This prototype seeks to build on the concepts learned during the c piscine
** (bootcamp), to code a library of useful functions that will be allowed to
** be reused in future projects. Because we don't have access to those highly
** useful standard functions, we have to re-write those functions, to
** understand them and to learn how to use them currently.
*/

int					ft_atoi(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memalloc(size_t size);
char				*ft_itoa(long long n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_mempcpy(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_putchar(unsigned long long c, char *str);
void				ft_putnbr(long int n);
void				ft_putnbr_fd(long int n, int fd);
void				ft_putnbr_base(long int n, int base);
void				ft_putnbr_base_fd(long int n, int base, int fd);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strnlen(const char *s, size_t maxlen);
size_t				ft_strlen(const char *s);
char				*ft_itoa_base_ll(uintmax_t n, int base);
char				*ft_itoa_base(long long n, int base);
long double			ft_neg_pow(long double n, int pow);
char				*ft_memnew(size_t i, int lett);
void				*ft_mempcpy(void *dst, const void *src, size_t len);
void				ft_two_b(unsigned long long c, char *str);
void				ft_three_b(unsigned long long c, char *str);
void				ft_four_b(unsigned long long c, char *str);
int					ft_num_dig(uintmax_t n, int base);
size_t				ft_strnlen(const char *string, size_t max);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_whitespace(char c);
char				**ft_strsplit(char const *s, char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
