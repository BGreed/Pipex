/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:54:52 by braugust          #+#    #+#             */
/*   Updated: 2025/01/23 20:37:54 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

char	*ft_buff_to_all(char *all, char *buff);
char	*ft_read_file(int fd, char *sortie, char *buff);
int		ft_strlen_gnl(char *str, int cas);
int		ft_check_if_newline(char *sortie);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_format_sortie(char *sortie);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nprt);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_re_strjoin(char *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_putstr(const char *str);
int		ft_putnbr_base(unsigned long nb, char *base);
int		ft_convert_ptr(void *pt);
int		ft_putnbr(int nb);
int		ft_putusig(unsigned int nb);
int		ft_printhexa(unsigned int nb, const char base);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char    *ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

#endif
