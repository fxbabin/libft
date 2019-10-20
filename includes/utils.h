/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 01:28:40 by fbabin            #+#    #+#             */
/*   Updated: 2019/10/20 21:51:11 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** ----------------------------- UTILS FUNCTIONS ------------------------------
*/

typedef struct			s_optlist
{
	char				flag;
	char				*param;
	struct s_optlist	*next;
}						t_optlist;

int					ft_isalnum(int c);
int					ft_iswp(char c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_abs(int nb);
void				ft_swap(int *a, int *b);
int					ft_tabsize(void **tab);

void				ft_optlist_pushback(t_optlist **begin_list,
						char flag, char *value);
void				*ft_optlist_del(t_optlist **begin);
void				display_optlist(t_optlist *opt);
int					ft_getopt(t_optlist **opts, int argc,
						char **argv, char *avail_opts);

#endif
