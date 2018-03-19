/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 15:25:19 by fbabin            #+#    #+#             */
/*   Updated: 2018/03/19 17:13:40 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btreecreate(void *item)
{
	t_btree		*bt;

	if (!(bt = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	bt->item = item;
	bt->left = NULL;
	bt->right = NULL;
	return (bt);
}
