#include "ft_ls.h"

int ft_strlen_limited(char *str)
{
    int i;
    int limit;

    limit = ARG_MAX * 8;
    if (str)
    {
        for (i = 0; str[i]; i++)
        {
            if (i >= limit)
                break;
        }
    }
    return (i);
}