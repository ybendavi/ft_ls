#include "ft_ls.h"

int    to_lower_map(int i, int c)
{
    (void)i;
    return (ft_tolower(c));
}
void    ft_lstadd_before(t_list *element, t_list *list_element)
{
    t_list  *prev;

    prev = list_element->prev;
    list_element->prev = element;
    element->next = list_element;
    element->prev = prev;
    element->prev->next = element;
}
void    print_l(t_list **to_print)
{
    t_list *elem;

    elem = *to_print;

    while (elem)
    {
        printf("%s\n", (char*)elem->content);
        elem = elem->next;
    }
}
void    sort_and_add(char *to_sort, t_list **content)
{
    t_list  *new_elem;
    t_list  *on;
    char    *str;
    int     cmp;
    int     cmp_mak;
    char    *str2;

    on = *content;
    new_elem = ft_lstnew(to_sort);
    str =  ft_strmapi(to_sort, (void *)&to_lower_map);
    //printf("str:%s\n", str);
    cmp_mak = ft_strncmp("libft", str, ft_strlen(str));
    if (cmp_mak == 0)
    {
        //printf("list:\n");
        //print_l(content);
    }
    str2 = on ? ft_strmapi(on->content, (void *)&to_lower_map) : NULL;
    while (on && on->next && (cmp = ft_strncmp(str2, str, ft_strlen(str))) < 0)
    {
        on = on->next;
        if (str2)
            free(str2);
        str2 = on ? ft_strmapi(on->content, (void *)&to_lower_map) : NULL;
        printf("str2:%s\n", str2);
    }
    if (str2)
        free(str2);
    if (cmp == 0)
    {
       // printf("tosort:%s\ncontent%s\n", to_sort, (char*)on->content);
    }
    if (!on || !on->next)
        ft_lstadd_back(content, new_elem);
    else if (!on->prev)
        ft_lstadd_front(content, new_elem);
    else
    {
        
        ft_lstadd_before(new_elem, on->next);
    }
}

void lookup(DIR *dirp, struct dirent *dp, t_list **dircontent_list)
{ 
    t_list *first;

    first = *dircontent_list;
        if (dp)
        {
            sort_and_add(dp->d_name, dircontent_list);
    while (first)
    {
        first = first->next;
    }
            lookup(dirp, readdir(dirp), dircontent_list);
        }
}

void    look_in_dir(DIR *dirp)
{
    t_list  **dircontent_list;
    t_list  *first;

    dircontent_list = ft_calloc(sizeof(t_list*), 1);
    lookup(dirp, readdir(dirp), dircontent_list);
    first = *dircontent_list;
    while (first)
    {
        printf("%s ", (char*)first->content);
        first = first->next;
    }
    printf("\n");
}