/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:37:19 by fbabin            #+#    #+#             */
/*   Updated: 2019/10/20 21:41:47 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

t_optlist	*ft_optlist_create(char flag, char *value)
{
	t_optlist	*t;

	if ((t = (t_optlist*)malloc(sizeof(t_optlist))) == NULL)
		return (NULL);
	t->flag = flag;
	if (value && *value)
		t->param = value;
	else
		t->param = NULL;
	t->next = NULL;
	return (t);
}

void		ft_optlist_pushback(t_optlist **begin_list, char flag, char *value)
{
	t_optlist	*tmp;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_optlist_create(flag, value)))
			return ;
	}
	else
		if (!(*begin_list = ft_optlist_create(flag, value)))
			return ;
}

void		*ft_optlist_del(t_optlist **begin)
{
	t_optlist   *tmp;

	if (!begin)
		return (NULL);
	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	return (NULL);
}

void		display_optlist(t_optlist *opt)
{
	t_optlist	*tmp;

	tmp = opt;
	while (tmp)
	{
		ft_printf("%c -> %s\n", tmp->flag, tmp->param);
		tmp = tmp->next;
	}
}
