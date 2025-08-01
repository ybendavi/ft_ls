#include "ft_ls.h"

int current(int flags)
{
    DIR     *dirp;
    t_ls    *dir;
    char    *current;

    if (!(current = ft_calloc(1, 2)))
        return (1);
    current[0] = '.';
    current[1] = 0;
    if ((dirp = opendir(current)) == NULL)
    {
        lstat_error(current);
        return(1);
    }
    if (!(dir = ft_calloc(1, sizeof(t_ls))))
    {
        closedir(dirp);
        lstat_error(current);
        return(1);
    }
    dir->dirp = dirp;
    dir->dirn = current;
    return (look_in_dir(dir, flags));
}

void    dirclose(DIR *dirp)
{
    (void)dirp;
    return;
}

int    launcher(char **av, int flags, int ac, int ismain)
{
    t_list  *dir_list_static = NULL;
    t_list **dir_list = &dir_list_static;
    int     check;

    check = check_for_directories(av, dir_list, ac, ismain);
    if (check == -1)
    {
        ft_lstclear(dir_list, (void*) &closedir_struct);
        perror("ft_ls: ");
        return (1);
    }
    if (flags & flag_value('r'))
    {
        if(ft_lstiterrfree_with_flag(*dir_list, (void *)look_in_dir, flags))
        {
            perror("ft_ls: ");
            return (1);
        }
    }
    else
    {
        if (ft_lstiterfree_with_flag(*dir_list, (void *)look_in_dir, flags))
        {
            perror("ft_ls: ");
            return (1);
        }
    }
    //ft_lstclear(dir_list, (void*)dirclose);
    return (0);
}

int main(int ac, char **av)
{
    int flags;
    char **av_clean;
    int len;

    av_clean = NULL;
    flags = flags_checker(&av[1], ac);
    //ft_printf("%s", flags);
    len = directory_checker(&av[1], ac - 1, &av_clean);
    if (len == 0)
    {
        free_strp(av_clean, len);
        if (current(flags))
        {
            perror("ft_ls: ");
            return (1);
        }
        return (0);
    }
    flags += 32;
    if (launcher(av_clean, flags, len, 1))
    {
        perror("ft_ls:");
        return (1);
    }
    //lookup(av[1]);
    return (0);
}
