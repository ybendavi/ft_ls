#include "libft.h"

void	ft_lstiterr(t_list *lst, void (*f)(void *))
{
    if (lst)
    {
        ft_lstiterr(lst->next, f);
        if (lst->content)
            (*f)(lst->content);
    }
}
