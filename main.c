#include "ft_ls.h"

char* flags_checker(char **av, char *flags)
{
    int i;
    int j;
    ft_bzero(flags, 6);
    if (av)
    {
        for (i = 1; av[i]; i++)
        {
            if (av[i][0] && av[i][0] == '-')
            {
                if (ft_strlen(av[i]) == 1)
                {
                    free(flags);
                    ft_printf("invalid option -- \'-'\n");
                    exit(2);
                }
                for (j = 1; av[i][j]; j++)
                {
                    if (ft_strchr(FLAGS, av[i][j]))
                    {
                        if (!ft_strchr(flags, av[i][j]))
                            ft_strlcat(flags, &av[i][j], 1);
                    }
                    else
                        exit(2);
                }
            }
        }
    }
    return (flags);
}

int open_dirs_args(char **av, t_list **dirs)
{
    int i;
    int res;
    int j;
    DIR *dirp;

    res = 1;
    if (av)
    {
        for (i=1; av[i]; i++)
        {
            if (av[i][0] && av[i][0] != '-')
            {
                if ((dirp = opendir(av[i])) == NULL)
                    perror(av[i]);
                else
                {
                    ft_lstadd_back(dirs, ft_lstnew(dirp));
                    res = 0;
                }
            }
            else
                j++;
        }
    }
    res = j == i ? 3 : res;
    return (res);
}

void    launcher(char **av, char *flags)
{
    t_list **dir_list;
    int     ret;

    (void)flags;
    dir_list = ft_calloc(sizeof(t_list*), 1);
    ret = open_dirs_args(av, dir_list);
    switch (ret)
    {
        case 0:
            ft_lstiter(*dir_list, (void*)&look_in_dir);
            break;
    }
    ft_lstclear(dir_list, (void*)closedir);
    free(dir_list);

}

int main(int ac, char **av)
{
    char flags[6];
    
    (void)ac;
    flags_checker(av, flags);
    //ft_printf("%s", flags);

    launcher(av, flags);
    //lookup(av[1]);
    return (0);
}
