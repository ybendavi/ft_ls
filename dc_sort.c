#include "ft_ls.h"


int compare_name(char *elem, char *elem2, size_t len, size_t len2)
{
    char    str[len + 1];
    char    str2[len2 + 1];
    size_t  to_use;

    ft_bzero(str, len + 1);
    ft_bzero(str2, len2 + 1);
    ft_memcpy(str, elem, len);
    ft_memcpy(str2, elem2, len2);
    striter(str, &to_lower_map);
    striter(str2, &to_lower_map);
    to_use = len >= len2 ? len :len2;
    return (ft_strncmp(str2, str, to_use));
}
int compare(t_de *elem, t_de *elem2, int flags)
{
    size_t  strlen;
    size_t  strlen2;

    if (!(flags & flag_value('t')))
    {
        strlen = ft_strlen(elem->dp->d_name);
        strlen2 = ft_strlen(elem2->dp->d_name);
        return (compare_name(elem->dp->d_name, elem2->dp->d_name, strlen, strlen2));
    }
    else
    {
        if (elem->sblstat->st_mtime < elem2->sblstat->st_mtime)
            return(-1);
        else if (elem->sblstat->st_mtime > elem2->sblstat->st_mtime)
            return (1); 
    }
    return (0);
}
int   sort_and_add(t_de *element, t_list **content, int flags)
{
    t_list  *new_elem;
    t_list  *on;


    on = *content;
    if (!(new_elem = ft_lstnew(element)))
        return (1);
    while (on && on->next && compare(element, on->content, flags) < 0)
        on = on->next;
    if ((!on || !on->next) && (!on || compare(element, on->content, flags) < 0))
        ft_lstadd_back(content, new_elem);
    else if (!on->prev)
        ft_lstadd_front(content, new_elem);
    else
        ft_lstadd_before(content, new_elem, on);
    return (0);
}