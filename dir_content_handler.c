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

void    format_element(char *path, struct stat *sblstat, int flags){
    
    char    *cutted;
    char    *path_c;
    if (path)
    {
        cutted = ft_strrchr(path, '/');
        path_c = cutted ? cutted + 1 : path;
        //printf("path:%s\nis_arg:%d\n", path_c, flags & 32);
        if (path_c
                && path_c[0]
                && (path_c[0] != '.'
                    || (path_c[0] == '.'
                        && ((flags & flag_value('a')) || (flags & 32)))))
        {
            if (flags & flag_value('l'))
                get_infos(path, sblstat);
            else
                ft_printf("%s ", (char*)path);
        }
    }
}

void    apply_format_tolst(t_de *content, int flags)
{
    format_element(content->dp->d_name, content->sblstat, flags);
}
void    delcuf(t_list **dircontent, int flags)
{
    t_de    *content;
    t_list  *tmp;
    t_list  *tmp2;

    tmp = *dircontent;
    while (tmp)
    {
        content = tmp->content;
        tmp2 = tmp->next;
        if (ft_strncmp(content->dp->d_name, ".", ft_strlen(content->dp->d_name)) == 0
                || ft_strncmp(content->dp->d_name, "..", ft_strlen(content->dp->d_name)) == 0
                || ((!(flags & flag_value('a'))) && content->dp->d_name[0] == '.'))
            ft_lstremove(dircontent, tmp, (void*)free_de);
        tmp = tmp2;
    }
}

int     format_dircontent_for_launcher(t_list *dircontent, int flags, t_ls *dir_struct)
{
    int  lstn;
    char    **args;
    int     i;
    int  size;
    t_de    *content;
    t_list  *first;

    first = dircontent;
    lstn = ft_lstsize(dircontent);
    args = ft_calloc(sizeof(char *), lstn + 1);
    i = 0;
    while (i < lstn)
    {
        content = dircontent->content;
        size = ft_strlen(dir_struct->dirn) + 3 + ft_strlen(content->dp->d_name);
        if (!(args[i] = ft_calloc(size, sizeof(char))))
        {
            free(args);
            closedir_struct(dir_struct);
            return (1);
        }
        ft_memcpy(args[i], dir_struct->dirn, ft_strlen(dir_struct->dirn));
        //ft_printf("argAfterCopy:%s\nsize:%d\n", args[i], ft_strlen(dir_struct->dirn));
        args[i][ft_strlen(dir_struct->dirn)] = '/';
        ft_strlcat(args[i], content->dp->d_name, size);
        //ft_printf("%s\n", args[i]);
        dircontent = dircontent->next;
        i++;
    }

    ft_lstclear(&first, (void*)&free_de);
    closedir_struct(dir_struct);
    if (launcher(args, flags, lstn, 0))
    {
        closedir_struct(dir_struct);
        return (1);
    }
    return (0);
}

int     maybef(t_ls *dir_struct, int flags)
{
    struct stat sblstat;

    if (lstat(dir_struct->dirn, &sblstat) == -1)
    {
        write(2, "ft_ls: cannot access '", 22);
        write(2, dir_struct->dirn, ft_strlen(dir_struct->dirn));
        write(2, "': ", 3);
        perror(dir_struct->dirn);
        free(dir_struct->dirn);
        free(dir_struct);
        return(0);
    }
    if (!(sblstat.st_mode & S_IFDIR))
    {
        format_element(dir_struct->dirn, &sblstat, flags);
        free(dir_struct->dirn);
        if (dir_struct->dirp)
            closedir(dir_struct->dirp);
        free(dir_struct);
        ft_printf("\n");
        return (0);
    }
    return (1);
}

int    look_in_dir(t_ls *dir_struct, int flags)
{
    t_list *dircontent_list_static = NULL;
    t_list  **dircontent_list = &dircontent_list_static;
    int     isdir;


    isdir = maybef(dir_struct, flags);
    if (!isdir)
        return (0);

    if (lookup(dir_struct, readdir(dir_struct->dirp), dircontent_list, flags))
    {
        ft_lstclear(dircontent_list, (void*)&free_de);
        closedir_struct(dir_struct);
        return (1);
    };
    if (flags & flag_value('R'))
        ft_printf("%s:\n", dir_struct->dirn);
    if (flags & flag_value('r'))
        ft_lstiterr_with_flag(*dircontent_list, (void*)&apply_format_tolst, flags);
    else
        ft_lstiter_with_flag(*dircontent_list, (void*)&apply_format_tolst, flags);
    ft_printf("\n");
    if (flags & 32)
        flags -= 32;
    if (flags & flag_value('R'))
    {
        delcuf(dircontent_list, flags);
        return (format_dircontent_for_launcher(*dircontent_list, flags, dir_struct));
    }
    ft_lstclear(dircontent_list, (void*)&free_de);
    closedir_struct(dir_struct);
    return(0);
}