/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:39:34 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/02 21:44:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t		i;
	int			y;

	i = 0;
	while (s[i])
	{
		y = -1;
		while (charset[++y])
		{
			if (s[i] != charset[y])
				return (i);
		}
		i++;
	}
	return (i);
}
