#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *to_delete, void (*del)(void *))
{
    if (!lst || !*lst || !to_delete)
        return;
    if (to_delete->prev)
        to_delete->prev->next = to_delete->next;
    else
        *lst = to_delete->next;
    if (to_delete->next)
        to_delete->next->prev = to_delete->prev;
    ft_lstdelone(to_delete, del);
}