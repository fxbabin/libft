/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreepostfix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:30:37 by fbabin            #+#    #+#             */
/*   Updated: 2018/03/19 17:31:31 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreepostfix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_btreepostfix(root->left, applyf);
		ft_btreepostfix(root->right, applyf);
		applyf(root->item);
	}
}
