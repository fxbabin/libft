/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:19:46 by fbabin            #+#    #+#             */
/*   Updated: 2019/10/20 21:53:13 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"
#include "str.h"

int		ft_opt_add(t_optlist **opt, char flag, char *param)
{
	t_optlist	*tmp;

	tmp = *opt;
	while (tmp)
	{
		if (tmp->flag == flag)
		{
			tmp->param = param;
			return (0);
		}
		tmp = tmp->next;
	}
	ft_optlist_pushback(opt, flag, NULL);
	return (0);
}

static void		add_option(t_optlist **opt, char **argv, int i, int y)
{
	if (argv[i][y + 1] == '\0')
	{
		if (!argv[i + 1])
		{
			ft_opt_add(opt, argv[i][y], NULL);
			return ;
		}
		ft_opt_add(opt, argv[i][y], argv[i + 1]);
	}
	else
		ft_opt_add(opt, argv[i][y], NULL);
}

static int		parse_options(t_optlist **opts, char **argv, int i,
					char *avail_opts)
{
	int		y;

	y = 0;
	while (argv[i][++y])
	{
		if (ft_charinset(argv[i][y], avail_opts))
			add_option(opts, argv, i, y);
		else
		{
			ft_dprintf(2, "%s: illegal option -- %c\n", argv[0], argv[i][y]);
			return (-1);
		}
	}
	return (0);
}

int				ft_getopt(t_optlist **opts, int argc,
					char **argv, char *avail_opts)
{
	int			i;
	int			count;

	i = 0;
	while (++i < argc)
	{
		if (count == 2 || !ft_strcmp(argv[i], "--"))
			break ;
		if (argv[i][0] != '-')
		{
			count++;
			continue ;
		}
		count = 0;
		if (parse_options(opts, argv, i, avail_opts) == -1)
		{
			ft_optlist_del(opts);
			return (-1);
		}
	}
	return (i - 1);
}
