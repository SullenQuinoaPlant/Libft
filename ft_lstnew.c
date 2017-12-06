/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:41:13 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:58:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))))
	{
		new->content = (void*)content;
		new->content_size = content ? content_size : 0;
		new->next = 0;
	}
	return (new);
}
