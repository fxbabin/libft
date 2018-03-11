/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:18:29 by fbabin            #+#    #+#             */
/*   Updated: 2018/03/11 22:46:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct		s_opt
{
	char			*flag;
	char			*value;
	struct s_opt	*next;
}					t_opt;

t_opt		*ft_optlstcreate(const char *flag, const char *value)
{
	t_opt		*t;

	if ((t = (t_opt*)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	t->flag = ft_strdup(flag);
	if (value && *value)
		t->value = ft_strdup(value);
	else
		t->value = NULL;
	t->next = NULL;
	return (t);
}

void		ft_optlstpushback(t_opt **begin_list, char *flag, char *value)
{
	t_opt		*tmp;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_optlstcreate(flag, value);
	}
	else
		*begin_list = ft_optlstcreate(flag, value);
}

int			ft_tabsize(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	return (i + 1);
}

int			ft_isinopts(const char *str, char **tabopt)
{
	char	**tmp;
	int		ex;
	int		i;
	int		x;

	i = -1;
	x = (str[0] == '-') ? 1 : 0;
	ft_printf("%d\n", ex);
	while (tabopt[++i])
	{
		if (!(tmp = ft_split(tabopt[i], ":")))
			return (-1);
		ex = (ft_tabsize(tmp) == 2) ? 1 : 0;
		//ex = (ex == 1 && tmp[1][0]) ? tmp[1][0] : 0;
		if (ex != 0 && ex != 105 && ex != 115)
		{
			ft_free2((void**)tmp);
			return (0);
		}
		//x = (str[0] == '-') ? 1 : 0;
		//if (opts[
		if (ex == 0 && !ft_strcmp(str + x, tmp[0]))
			return (1);
		ft_free2((void**)tmp);
	}
	return (0);
}



int			check_opt(t_opt *opt, char **argv, int i, char **tabopt)
{
	int		x;

	x = 0;
	if (ft_isinopts(argv[i], tabopt))
		ft_optlstpushback(&opt, argv[i], NULL); 
	//ft_printf("%s\n", argv[i]);
	/*else
	  {
	  while (argv[i][++x])
	  {
	  if (ft_isinopts(argv[i][x], opts))

	  else
	  ft_dprintf(2, "%s: illegal option -- %c\n", argv[0], argv[*i][y]);
	  }*/
	return (1);
}

void    add_option(t_opt **opt, char flag, char *value)
{
	char	*t;
	t_opt	*tmp;
	int		b;

	b = 0;
	tmp = *opt;
	if (!(t = (char*)ft_memalloc(2 * sizeof(char))))
		return ;
	ft_memcpy(t, &flag, 1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->flag, t))
		{
			b++;
			break ;
		}
		tmp = tmp->next;
	}
	if (b == 0)
		ft_optlstpushback(opt, t, value); 
	ft_strdel(&t);
}

int			parse_options(t_opt **opt, char **argv, int *i, const char *opts)
{
	int		y;

	y = 0;
	//if (argv[*i][1] == '-' && argv[*i][2])
	//	return (1);
	while (argv[*i][++y])
	{
		if (ft_charinset(argv[*i][y], opts))
			add_option(opt, argv[*i][y], NULL);
		else
		{
			ft_dprintf(2, "%s: illegal option -- %c\n", argv[0], argv[*i][y]);
			return (0);
		}
	}
	return (1);
}

int		parse_complex(t_opt **opt, char **argv, int *i, const char *opts)
{

	return (0);
}

void	display_opt(t_opt *opt)
{
	t_opt	*tmp;

	tmp = opt;
	while (tmp)
	{
		ft_printf("%s -> %s\n", tmp->flag, tmp->value);
		tmp = tmp->next;
	}
}

void	*ft_optlstdel(t_opt **alst)
{
	t_opt		*tmp;

	if (!alst)
		return (NULL);
	while (*alst)
	{
		tmp = (*alst)->next;
		if ((*alst)->flag && *((*alst)->flag))
			ft_strdel(&(*alst)->flag);
		if ((*alst)->value && *((*alst)->value))
			ft_strdel(&(*alst)->value);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
	return (NULL);
}

t_opt		*ft_get_options(int argc, char **argv, const char *opts)
{
	char	**tabopt;
	t_opt	*opt;
	int		i;

	i = 0;
	opt = NULL;
	if (!(tabopt = ft_split((char*)opts, ";")))
		return (NULL);
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--", 2))
			break ;
		if (argv[i][0] != '-')
			break ;
		if (!parse_options(&opt, argv, &i, tabopt[0]))
			return (ft_optlstdel(&opt));
	}
	if (tabopt[1])
	{
		i -= 1;
		while (++i < argc)
		{
			if (argv[i][0] != '-' || argv[i][1] != '-')
				break ;
			if (!parse_complex(&opt, argv, &i, tabopt[1]))
				return (ft_optlstdel(&opt));
		}
	}
	ft_free2((void**)tabopt);
	return (opt);
}



int		main(int argc, char **argv)
{
	t_opt	*opt;

	opt = ft_get_options(argc, argv, "abcG@");
	//ft_printf("%s -> %s\n", opt->flag, opt->value);
	display_opt(opt);
	ft_optlstdel(&opt);
	//ft_printf("%d\n", ret);
	return (0);
}
