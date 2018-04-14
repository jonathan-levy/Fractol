/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:34:56 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/13 09:35:00 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_program_name(char const *argv0)
{
	char *name;

	name = (char *)argv0;
	while (*name && *name != '/')
		name += 1;
	if (!name)
		return ((char *)argv0);
	return (name + 1);
}
