#include "ft_ls.h"

void    lstat_error(char *filename)
{
    write(2, "ft_ls: cannot access '", 22);
    write(2, filename, ft_strlen(filename));
    write(2, "': ", 3);
    perror(filename);
}