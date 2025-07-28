#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list	*new_list;
    t_list	*new_elem;
    t_list	*last;

    new_list = NULL;
    last = NULL;
    while (lst)
    {
        new_elem = malloc(sizeof(t_list));
        if (!new_elem)
        {
            while (new_list)
            {
                t_list *tmp = new_list->next;
                if (del)
                    del(new_list->content);
                free(new_list);
                new_list = tmp;
            }
            return (NULL);
        }
        new_elem->content = f(lst->content);
        new_elem->next = NULL;
        if (!new_list)
            new_list = new_elem;
        else
            last->next = new_elem;
        last = new_elem;
        lst = lst->next;
    }
    return (new_list);
}