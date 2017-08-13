/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 23:48:45 by agautier          #+#    #+#             */
/*   Updated: 2016/11/28 22:03:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *postf_elem;
	t_list *pref_elem;

	new_lst = NULL;
	if (lst && (*f))
	{
		new_lst = (*f)(lst);
		pref_elem = new_lst;
		lst = lst->next;
		while (lst)
		{
			postf_elem = (*f)(lst);
			pref_elem->next = postf_elem;
			pref_elem = postf_elem;
			lst = lst->next;
		}
		pref_elem->next = NULL;
	}
	return (new_lst);
}
