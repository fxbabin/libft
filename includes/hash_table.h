/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:16:27 by fbabin            #+#    #+#             */
/*   Updated: 2019/09/16 14:28:38 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>

# define HASH_TSIZE 30

typedef struct			s_hash_list
{
	void				*key;
	void				*value;
	struct s_hash_list	*next;
}						t_hash_list;

int						hash_strcmp(void *s1, void *s2);
void					hash_add_key_val(t_hash_list *hash_table, void *key,
										void *val, int (cmp)(void*, void*));
void					*hash_get_val(t_hash_list *hash_table, void *key,
										int (cmp)(void*, void*));

#endif
