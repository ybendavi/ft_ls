#include "ft_ls.h"

void    lstat_error(char *filename)
{
    write(2, "ft_ls: cannot access '", 22);
    write(2, filename, ft_strlen(filename));
    write(2, "': ", 3);
    perror(filename);
}

int    directory_error(char *dirn)
{
    if (errno == EACCES || errno == ENOENT)
    {
        write(2, "ft_ls: cannot open directory '", 30);
        write(2, dirn, ft_strlen(dirn));
        write(2, "': ", 3);
        perror("");
        return (2);
    }
    if (errno == ENOMEM)
        return (1);
    return (0);
}