#include "ft_ls.h"

int    check_for_directories(char **av, t_list **dirs, int ac)
{
    int     ret;
    DIR     *dirp;
    int     i;
    t_ls    *dir;
    t_list  *new_elem;


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
            {
                if (!(dir = ft_calloc(1, sizeof(t_ls))))
                    return(-1);
                dir->dirp = dirp;
                dir->dirn = av[i];
                if (!(new_elem = ft_lstnew(dir)))
                    return(-1);
                ft_lstadd_back(dirs, new_elem);
            }
        }
        i++;
    }
    return (ret);
}

void current(int flags)
{
    DIR     *dirp;
    t_ls    *dir;
    char    current[2];

    current[0] = '.';
    current[1] = 0;
    if ((dirp = opendir(current)) == NULL)
    {
        perror(strerror(errno));
        exit(1);
    }
    if (!(dir = ft_calloc(1, sizeof(t_ls))))
    {
        closedir(dirp);
        perror(strerror(errno));
        exit(1);
    }
    dir->dirp = dirp;
    dir->dirn = current;
    look_in_dir(dir, flags);
}

void    dirclose(DIR *dirp)
{
    (void)dirp;
    return;
}

void    launcher(char **av, int flags, int ac)
{
    t_list  *dir_list_static = NULL;
    t_list **dir_list = &dir_list_static;
    int     check;

    (void)flags;
    check = check_for_directories(av, dir_list, ac);
    if (check == -1)
    {
        ft_lstclear(dir_list, (void*) &closedir_struct);
        perror(strerror(errno));
        exit(1);
    }
    if (!check)
    {
        if (flags & flag_value('r'))
        {
            if(ft_lstiterr_with_flag(*dir_list, (void *)look_in_dir, flags))
            {
                perror(strerror(errno));
                exit(1);
            }
        }
        else
        {
            if (ft_lstiter_with_flag(*dir_list, (void *)look_in_dir, flags))
            {
                perror(strerror(errno));
                exit(1);
            }
        }
    }
    else
        current(flags);
    ft_lstclear(dir_list, (void*)dirclose);
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
