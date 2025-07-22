#include "ft_ls.h"

void lookup(char *directory_name, char *args)
{
    DIR *dirp;
    struct dirent *dp;


    if ((dirp = opendir(directory_name ? directory_name : ".")) == NULL) {
        perror("couldn't open '.'");
        return;
    }

    dp = readdir(dirp);
    while (dp)
    {
        ft_printf("%s\n", dp->d_name);
        dp = readdir(dirp);
    }
    closedir(dirp);
}

char* flags_checker(char **av)
{
    int i;
    int j;
    char *flags;

    flags = (char*)ft_calloc(6, sizeof(char));
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
                        ft_strlcat(flags, &av[i][j], 1);
                    }
                    else
                    {
                        free(flags);
                        exit(2);
                    }
                }
            }
        }
    }
    return (flags);
}

t_list** open_dirs(char **av)
{
    int i;
    t_list **dirs;
    DIR *dirp;

    dirs = NULL;
    if (av)
    {
        for (i=1; av[i]; i++)
        {
            if (av[i][0] && av[i][0] != '-')
            {
                if ((dirp = opendir(av[i])) == NULL)
                {
                    perror("cannot access : No such file or directory");
                    if (dirs)
                        ft_lstclear(dirs, &close);                    
                    exit(2);
                }
                ft_lstadd_back(dirs, ft_lstnew(dirp));
            }
        }
    }
    return (dirs);
}
int main(int ac, char **av)
{
    int i;
    t_list **dir_list;
    DIR *dirp;
    char *flags;
    
    flags = flags_checker(av);
    ft_printf("%s", flags);
    free(flags);
    return (0);
    dir_list = NULL;
    if (av)
    {
        dir_list = open_dirs(av);
    }
    //lookup(av[1]);
    return (0);
}
