/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:39:34 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/03 14:00:46 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_in(char c, const char *charset)
{
	int		i;
	int		b;

	i = -1;
	b = 0;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (b);
}

int			ft_strspn(const char *s, const char *charset)
{
	int		i;

	i = -1;
	while (s[++i] && ft_in(s[i], charset))
		;
	return (i);
}
