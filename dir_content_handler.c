#include "ft_ls.h"



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



int    look_in_dir(t_ls *dir_struct, int flags)
{
    t_list *dircontent_list_static = NULL;
    t_list  **dircontent_list = &dircontent_list_static;
    t_list  *first;


    if (lookup(dir_struct, readdir(dir_struct->dirp), dircontent_list, flags))
    {
        ft_lstclear(dircontent_list, (void*)&free_de);
        closedir(dir_struct->dirp);
        free(dir_struct);
        dir_struct = NULL;
        return (1);
    };
    first = *dircontent_list;
    while (first)
    {
        t_de *content;

        content = first->content;
        if (content && content->dp && content->dp->d_name)
            printf("%s ", (char*)content->dp->d_name);
        first = first->next;
    }
    ft_lstclear(dircontent_list, (void*)&free_de);
    closedir(dir_struct->dirp);
    free(dir_struct);
    dir_struct = NULL;
    printf("\n");
    return(0);
}