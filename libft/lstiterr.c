#include "libft.h"

void	ft_lstiterr(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
    while (lst)
    {
        (*f)(lst->content);
        lst = lst->prev;
    }
}