/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:43:20 by vaferrei          #+#    #+#             */
/*   Updated: 2021/12/22 15:24:10 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_flags
{
	int	w_number;
	int	f_minus;
	int	p_dot;
	int	w_number_n;
	int	f_minus_n;
	int	p_dot_n;
	int	f_zero;
	int	f_hash;
	int	f_space;
	int	f_plus;
	int	error;
	int	control;
	int	len;
	int	plen;
	int	nlen;
	int	tlen;
}	t_flags;

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n );
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(char const *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_numberlen(int n);
int		ft_hexlen(unsigned long n);
char	*get_next_line(int fd);

int		ft_countwords(char const *str, char c);
int		ft_atoi_base(char *str, char *base);

int		ft_printf(const char *str, ...);
t_flags	ft_pf_char(int c, t_flags flags);
t_flags	ft_pf_string(char *str, t_flags flags);
t_flags	ft_pf_str_p(char *str, t_flags flags);
t_flags	ft_pf_str_md(char *str, t_flags flags);
t_flags	ft_pf_str_m(char *str, t_flags flags);
t_flags	ft_pf_str_d(char *str, t_flags flags);
t_flags	ft_pf_str_n(char *str, t_flags flags);
t_flags	ft_pf_str_b(char *str, t_flags flags);
t_flags	ft_pf_decimal(int number, t_flags flags);
t_flags	ft_pf_dec_b(int number, t_flags flags);
t_flags	ft_pf_nn(int number, int quant, int ftype, t_flags flags);
t_flags	ft_pf_pn(int number, int quant, int ftype, t_flags flags);
t_flags	ft_pf_sn(int number, t_flags flags);
t_flags	ft_pf_dec_d(int number, t_flags flags);
t_flags	ft_pf_dec_m(int number, t_flags flags);
t_flags	ft_pf_dec_md(int number, t_flags flags);
t_flags	ft_pf_dec_z(int number, t_flags flags);
t_flags	ft_pf_dec_zd(int number, t_flags flags);
t_flags	ft_pf_undecimal(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_b(unsigned int number, t_flags flags);
t_flags	ft_pf_un(unsigned int number, int quant, int ftype, t_flags flags);
void	ft_putunbr_fd(unsigned int n, int fd);
t_flags	ft_pf_undec_d(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_m(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_md(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_z(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_zd(unsigned int number, t_flags flags);
t_flags	ft_pf_hexa(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_b(int number, t_flags flags, int tcase);
void	ft_putitohex(unsigned int num, int typec);
t_flags	ft_pf_hex_d(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_m(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_md(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_z(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_zd(int number, t_flags flags, int tcase);
t_flags	ft_pf_pointer(unsigned long int number, t_flags flags);
t_flags	ft_pf_poi_b(unsigned long int number, t_flags flags, int aux);
t_flags	ft_pf_poi_none(unsigned long int number, t_flags flags);
void	ft_putitohexlong(unsigned long int num, int typec);
t_flags	ft_pf_poi_n(unsigned long int number, t_flags flags);
t_flags	ft_pf_poi_m(unsigned long int number, t_flags flags);
int		put_flag(int quant, int ftype);
t_flags	ft_pf_init(void);
t_flags	ft_pf_reinit_e(t_flags flags);
t_flags	ft_pf_reinit_c(t_flags flags);

#endif
