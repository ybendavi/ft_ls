#include "ft_ls.h"

int    check_for_directories(char **av, t_list **dirs, int ac)
{
    int     ret;
    DIR     *dirp;
    int     i;


    ret = 1;
    i = 1;
    while (i < ac)
    {
        if (*av[i] != '-')
        {
            ret = 0;
            if ((dirp = opendir(av[i])) == NULL)
                perror(av[i]);
            else
                ft_lstadd_back(dirs, ft_lstnew(dirp));
        }
        i++;
    }
    return (ret);
}

void current(int flags)
{
    DIR     *dirp;

    if ((dirp = opendir(".")) == NULL)
        perror(".");
    look_in_dir(dirp, flags);
    if (dirp)
        closedir(dirp);
}

void    launcher(char **av, int flags, int ac)
{
    t_list **dir_list;

    (void)flags;
    dir_list = ft_calloc(sizeof(t_list*), 1);
    if (!check_for_directories(av, dir_list, ac))
    {
        if (flags & flag_value('r'))
            ft_lstiterr_with_flag(*dir_list, (void *)look_in_dir, flags);
        else
            ft_lstiter_with_flag(*dir_list, (void *)look_in_dir, flags);
    }
    else
        current(flags);
    ft_lstclear(dir_list, (void*)closedir);
    free(dir_list);

}

int main(int ac, char **av)
{
    int flags;
    

    flags = flags_checker(&av[1], ac);
    //ft_printf("%s", flags);

    launcher(av, flags, ac);
    //lookup(av[1]);
    return (0);
}
