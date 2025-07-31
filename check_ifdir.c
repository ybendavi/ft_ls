#include "ft_ls.h"


int    check_for_directories(char **av, t_list **dirs, int ac, int ismain)
{
    int     ret;
    DIR     *dirp;
    int     i;
    t_ls    *dir;
    t_list  *new_elem;


    ret = 1;
    i = 0;
    if (av)
    {
        while (i < ac)
        {
            ret = 0;
            if ((!((dirp = opendir(av[i])) == NULL)) || (!dirp && ismain))
            {
                //printf("%s\n", av[i]);
                if (!(dir = ft_calloc(1, sizeof(t_ls))))
                {
                    free_strp(av, ac);
                    return(-1);
                }
                dir->dirp = dirp;
                dir->dirn = av[i];
                if (!(new_elem = ft_lstnew(dir)))
                {
                    free_strp(av, ac);
                    return(-1);
                }
                ft_lstadd_back(dirs, new_elem);
            }
            else
                free(av[i]);
            i++;
        }
        free(av);
    }
    return (ret);
}

int  directory_checker(char **av, int ac, char ***buff)
{
    int count;
    int i;
    int j;

    i = 0;
    count = ac;
    if (!av)
        return (0);
    while (i < ac)
    {
        if (*av && *av[i])
        {
            if (*av[i] == '-')
                count--;
        }
        i++;
    }
    if (!(*buff = ft_calloc(count, sizeof(char*))))
        return (-1);
    i = 0;
    j = 0;
    while (j < count && *av[i])
    {
        if (*av && *av[i])
        {
            if (*av[i] != '-')
            {
                *buff[j] = ft_strdup(av[i]);
                j++;
            }
        }
        i++;
    }
    return (count);
}