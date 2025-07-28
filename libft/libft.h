/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:33:45 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:43:24 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void
				*));
void	ft_lstclear(t_list **lst, void (*del)(void
				*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstiterr(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));

// PRINTF //

char		*ft_itoa_base(unsigned long long int n, const char *base);
char		*type_flag_handler(char flag, va_list arg, char *flags);
char		*type_flag_handler_p2(char flag, va_list arg, char *flags);
char		*star_flag(va_list arg, char *flags, int n);
char		*flags_for_p(char *flags, char *str);
char		*flags_for_int(char *flags, char *str);
char		*flags_for_char(char *flags, char c);
char		*flags_for_string(char *flags, char *str);
char		*digit_str(char *str, int width);
char		*minus_str(char *str, int width);
char		*zero_str(char *str, int width);
char		*point_str(char *flags, char *str);
char		*minus(int width, char *str);
char		*digit(int width, char *str);
char		*zero(int width, char *str);
char		*point(int width, char *str, char flag, int s);
char		*p_point(int width, char *str, char flag, int s);
char		*inferior_width(int width, char *str, char flag, int size);
char		*superior_width(int width, char *str, char flag, int size);
char		*equal_width(char *str, int size);
char		*str_fuller(char *str, int width, char flag, int i);
char		*p_zero(int width, char *str);
char		*set_flags(const char *format, va_list arg);
char		*set_minus_o_zero(const char *format, char *list);
char		*end_listing(const char *format, char *list, va_list arg,
		int count);
const char	*set_point(const char *format, char *list, va_list arg);
const char	*check_flags(const char *format);
int			check_flags_assets(const char *format, int i);
int			width_size(char *flags);
int			analize_format(const char *format, va_list arg);
int			format_printer(const char *format);
int			calc_width(char	*flags);
int			ft_printf(const char *format, ...);

#endif
