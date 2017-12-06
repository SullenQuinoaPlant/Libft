#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = 0;
	if (lst)
		if ((new = (*f)(lst))
			new->next = ft_lstmap(lst->next, f);
	return (new);
}
