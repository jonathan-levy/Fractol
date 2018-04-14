/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:41:33 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/13 09:41:37 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define FT_SQUARE(x)	(x * x)

int			ft_isupper(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strequ(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strcap(char *str);
char		*ft_program_name(char const *argv0);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strnew(size_t size);
char		*ft_str_to_lowcase(char *str);
void		ft_putstr(char const *s);
void		ft_puterror(char *msg, int ret);
void		ft_putendl(char const *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *str);

#endif
