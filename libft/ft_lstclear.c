/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:27:27 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:42:56 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = NULL;
	if (lst != NULL)
	{
		ptr = *lst;
		while (*lst != NULL)
		{
			ptr = ptr->next;
			ft_lstdelone(*lst, del);
			*lst = ptr;
		}
	}
}
