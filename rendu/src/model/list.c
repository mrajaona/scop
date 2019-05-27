#include "list.h"

t_list	*new_elem(t_list **list, size_t data_size)
{
	t_list	*elem;
	t_list	*prev;

	if (!list || !(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);

	if (!(elem->data = malloc(data_size)))
	{
		free(elem);
		return (NULL);
	}

	elem->next = NULL;
	if (!(*list))
		*list = elem;
	else
	{
		prev = *list;
		while (prev->next)
			prev = prev->next;
		prev->next = elem;
	}
	return (elem);
}

void	free_list(t_list **list)
{
	t_list	*next;
	t_list	*cur;

	if (!list)
		return ;
	cur = *list;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*list = NULL;
}
