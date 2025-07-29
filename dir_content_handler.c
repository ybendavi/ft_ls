#include "ft_ls.h"

int    to_lower_map(int i, int c)
{
    (void)i;
    return (ft_tolower(c));
}


//Only for testing
/*void    print_l(t_list **to_print)
{
    t_list *elem;

    elem = *to_print;

    while (elem)
    {
        printf("%s\n", (char*)elem->content);
        elem = elem->next;
    }
}*/

void    sort_and_add(char *to_sort, t_list **content)
{
    t_list  *new_elem;
    t_list  *on;
    char    *str;
    char    *str2;

    on = *content;
    new_elem = ft_lstnew(to_sort);
    str =  ft_strmapi(to_sort, (void *)&to_lower_map);
    str2 = on ? ft_strmapi(on->content, (void *)&to_lower_map) : NULL;
    while (on && on->next && ft_strncmp(str2, str, ft_strlen(str))< 0)
    {
        on = on->next;
        if (str2)
            free(str2);
        str2 = on ? ft_strmapi(on->content, (void *)&to_lower_map) : NULL;
    }
    if ((!on || !on->next) && (str2 == NULL || ft_strncmp(str2, str, ft_strlen(str)) < 0))
        ft_lstadd_back(content, new_elem);
    else if (!on->prev)
        ft_lstadd_front(content, new_elem);
    else
        ft_lstadd_before(new_elem, on);
    if (str2)
        free(str2);
    if (str)
        free(str);
}

void lookup(DIR *dirp, struct dirent *dp, t_list **dircontent_list)
{ 
    t_list *first;

    first = *dircontent_list;
        if (dp)
        {
            sort_and_add(dp->d_name, dircontent_list);
            lookup(dirp, readdir(dirp), dircontent_list);
        }
}

void    clear(char *str)
{
    (void)str;
    return;
}

void    look_in_dir(DIR *dirp, int flags)
{
    t_list  **dircontent_list;
    t_list  *first;

    (void)flags;
    dircontent_list = ft_calloc(sizeof(t_list*), 1);
    lookup(dirp, readdir(dirp), dircontent_list);
    first = *dircontent_list;
    while (first)
    {
        printf("%s ", (char*)first->content);
        first = first->next;
        
    }
    ft_lstclear(dircontent_list, (void*)&clear);
    free(dircontent_list);
    printf("\n");
}