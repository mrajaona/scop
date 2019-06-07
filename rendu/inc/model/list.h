#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct	s_list
{
	unsigned int	index;
	void			*data;
	struct s_list	*next;
}				t_list;

t_list		*new_elem(t_list **list, size_t data_size);
void		free_list(t_list **list);

#endif