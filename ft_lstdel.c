/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:38:16 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:38:18 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
//{
//printf("\n from ft_lstdel, content is: %s", (char*)(*alst)->content);
//	if ((*alst)->next)
//		ft_lstdel(&((*alst)->next), del);
//	(*del)((*alst)->content, (*alst)->content_size);
//	free(*alst);
//	*alst = 0;
//}
{
	t_list	*curr;

	while ((curr = *alst))
	{
		*alst = curr->next;
		del(curr->content, curr->content_size);
		free(curr);
	}
}
