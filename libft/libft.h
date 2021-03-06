/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:09:09 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 15:26:29 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 32

typedef struct          l_list
{
        void            *content;
        struct s_list   *next;
}                                       v_list;

v_list              *ft_lstnew(void *content);
void                ft_lstadd_front(v_list **alst, v_list *new);
int                 ft_lstsize(v_list *lst);
v_list              *ft_lstlast(v_list *lst);
void                ft_lstadd_back(v_list **alst, v_list *new);
void                ft_lstdelone(v_list *lst, void (*del)(void      *));
void                ft_lstclear(v_list **lst, void (*del)(void *));
void                ft_lstiter(v_list *lst, void (*f)(void *));
v_list              *ft_lstmap(v_list *lst, void *(*f)(void *));
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int		            ft_strchr(char *s, int c);
int		            ft_strlen(char *str);
char                *ft_strjoin(char *s1, char *s2);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, char *src, size_t n);
size_t				ft_strlcat(char *dst, char *src, size_t size);
int                 ft_strnstr(const char *s1, const char *s2, size_t n);
long				ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char                *ft_strdup(const char *s);
int		            get_next_line(int fd, char **line);
char	            *ft_strjoinn(char *s1, char *s2);
char	            *ft_strdup_backline(char *s);

#endif
