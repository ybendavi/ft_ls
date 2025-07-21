#include <stdio.h>
#include "libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>


void lookup(char *directory_name)
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


int main(int ac, char **av)
{
    int i;

    lookup(av[1]);
    return (0);
}
