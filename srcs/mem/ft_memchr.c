/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:06:06 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/15 21:37:42 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *s)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
