/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:38:03 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/13 09:38:05 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && 'z' >= c);
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' \
			|| c == ' ');
}

char		*ft_strcap(char *str)
{
	int		i;

	i = 0;
	if (ft_islower(str[i]))
		str[i] -= 32;
	while (str[i++])
		if (ft_isspace(str[i]))
			if (ft_islower(str[i + 1]))
				str[i + 1] -= 32;
	return (str);
}
