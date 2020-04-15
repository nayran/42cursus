/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:41:42 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/28 10:18:26 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memchr(const void *buffer, int c, size_t count);
void				*ft_memmove(void *to, const void *from, size_t numbytes);
void				*ft_memset(void *str, int x, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t num);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t num);
size_t				ft_strlen(const char *string);
void				*ft_memccpy
	(void *to, const void *from, int ch, size_t nbytes);
void				ft_bzero(void *str, size_t x);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s1, int c);
char				*ft_strncpy(char *s1, const char *s2, size_t tam);
int					ft_strncmp(const char *s1, const char *s2, size_t max);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
char				*ft_strnstr(const char *s, const char *find, size_t slen);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t num_elements, size_t size);
char				*ft_strdup (const char *source);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)
		(void *), void (*del)(void *));

#	endif
