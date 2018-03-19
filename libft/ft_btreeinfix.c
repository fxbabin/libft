/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:24:15 by fbabin            #+#    #+#             */
/*   Updated: 2018/03/19 17:27:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_btreeinfix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_btreeinfix(root->left, applyf);
		applyf(root->item);
		ft_btreeinfix(root->right, applyf);
	}
}
