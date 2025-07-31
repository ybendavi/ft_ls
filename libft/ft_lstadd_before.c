#include "libft.h"

// Add the element element before the element list_element in a lst

void    ft_lstadd_before(t_list **lst, t_list *element, t_list *list_element)
{
    t_list  *prev;

    if (!element || !list_element)
        return;
    prev = list_element->prev;
    element->next = list_element;
    element->prev = prev;
    list_element->prev = element;
    if (prev)
        prev->next = element;
    else
        *lst = element;
}