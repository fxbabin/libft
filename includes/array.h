/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 00:50:15 by fbabin            #+#    #+#             */
/*   Updated: 2019/07/19 15:43:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

/*
** --------------------------- ARRAY FUNCTIONS ----------------------------
*/

int		            ft_qs_intcmp(void *n1, void *n2);
int		            ft_qs_strcmp(void *s1, void *s2);

char				*ft_join(char **tab, char *sep);
void			    ft_quicksort(void **array, int left, int right,
                        int (cmp)(void*, void*));
void				ft_mergesort(int **array, int left, int right);
void				ft_strmergesort(char **array, int left, int right);
void				ft_char2dump(char **array);
void				ft_int2dump(int **array);

#endif
