#include "h.h"

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
	if (delthis) 
	{
		next = (*delthis);
		while (*delthis)
		{
			curr = *delthis;
			*delthis = (*delthis)->next;
			del(curr->content, curr->content_size);
			free(curr);
		}
	}
}
