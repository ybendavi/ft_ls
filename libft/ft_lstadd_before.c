#include "libft.h"

// Add the element element before the element list_element in a lst

void    ft_lstadd_before(t_list *element, t_list *list_element)
{
    t_list  *prev;

    prev = list_element->prev;
    list_element->prev = element;
    element->next = list_element;
    element->prev = prev;
    element->prev->next = element;
}