/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:46:56 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/01/20 14:46:57 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;

	if (*lst)
	{
		while (*lst)
		{
			aux_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux_lst;
		}
		*lst = 0;
	}
}
