#include "ft_ls.h"

int     flag_value(char flag)
{
    int  add;   
    switch(flag)
        {
            case 'l':
                add = 16;
                break;
            case 'R':
                add = 8;
                break;
            case 'a':
                add = 4;
                break;
            case 'r':
                add = 2;
                break;
            case 't':
                add = 1;
                break;
            default:
                add = 0;
        }
    return (add);
}

void calculate_flags(char *flags, int *flag)
{
    int     add;

    add = 0;
    if (*flags)
    {
        switch(*flags)
        {
            case 'l':
                add = 16;
                break;
            case 'R':
                add = 8;
                break;
            case 'a':
                add = 4;
                break;
            case 'r':
                add = 2;
                break;
            case 't':
                add = 1;
                break;
            default:
            {
                ft_printf("invalid option -- \'%c'\n%s\n", *flags, flags);
                exit(2);
            }
        }
        add = flag_value(*flags);
        if (add == 0)
        {
            ft_printf("invalid option -- \'%c'\n%s\n", *flags, flags);
            exit(2);
        }
        if (!(*flag & add))
        {
            *flag += add;
            calculate_flags(&flags[1], flag);
        }
    }
}


int flags_checker(char **av, int ac)
{
    char    *arg;
    int flag;
    int i;

    i = 1;
    flag = 0;
    arg = *av;
    while (i < ac)
    {
        if (*arg && *arg == '-')
            calculate_flags(&arg[1], &flag);
        arg++;
        i++;
    }
    return (flag);
}