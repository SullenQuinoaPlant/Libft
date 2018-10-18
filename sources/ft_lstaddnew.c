/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:32:33 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 10:40:59 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddnew(t_list **alst, void const *content, size_t content_sz)
{
	t_list	*new;

	if (!(new = ft_lstnew(content, content_sz)))
		return (-1);
	new->next = *alst;
	*alst = new;
	return (0);
}
