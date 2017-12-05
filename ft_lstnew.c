#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))))
	{
		new->content = content;
		new->content_size = content ? content_size : 0;
		new->next = 0;
	}
	return (new);
}
