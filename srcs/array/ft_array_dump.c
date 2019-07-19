/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:28:30 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/16 00:34:35 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "io.h"

void	ft_dumpstr(void *s)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = (char*)s;
	if (!s)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (tmp[++i])
		;
	write(1, tmp, i);
}

void	ft_dumpint(void *nb)
{
	int		tmp;

	tmp = *((int*)nb);
	ft_putnbr(tmp);
}

void	ft_array_dump(void **array, int len, void (dump)(void*))
{
	int		i;

	i = -1;
	if (!array || !*array)
		return ;
	ft_putstr("[");
	while (++i < len - 1)
	{
		dump(array[i]);
		ft_putstr(", ");
	}
	dump(array[i]);
	ft_putstr("]\n");
}