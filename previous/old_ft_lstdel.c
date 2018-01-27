/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:38:16 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/15 08:34:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
void	del_here(t_list *elem, void(*f)(void*, size_t))
{
	if (elem->next)
		del_here(elem->next, f);
	(*f)(elem->content, elem->content_size);
	free(elem);
}

void	delthis(t_list **delthis, void(*del)(void*, size_t))
{
	t_list	*curr;

//	if ((curr = *delthis))
//		del_here(curr, del);
//	*delthis = 0;

	t_list	*next;
	if (*delthis) 
	{
		next = (*delthis);
		while (next)
		{
			curr = next;
			next = curr->next;
			del(curr->content, curr->content_size);
			free(curr);
		}
		*delthis = 0;
	}
}
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst) 
	{
		while (*alst)
		{
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
		*alst = 0;
	}
}
//{
////printf("\n from ft_lstdel, content is: %s", (char*)(*alst)->content);
//	if ((*alst)->next)
//		ft_lstdel(&((*alst)->next), del);
//	(*del)((*alst)->content, (*alst)->content_size);
//	free(*alst);
//	*alst = 0;
//}
//{
//	t_list	*curr;
//
//	while ((curr = *alst))
//	{
////		printf("\ngoing to free %lu\n", (unsigned long)curr);
//		*alst = curr->next;
//		del(curr->content, curr->content_size);
////		printf("\ngoing to free %lu\n", (unsigned long)curr);
//		free(curr);
//	}
//}
//{
//	delthis(alst, del);
//}
