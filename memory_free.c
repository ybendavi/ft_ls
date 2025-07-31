#include "ft_ls.h"

void    free_dircontent_list(t_de *element)
{
    if (element->sblstat)
        free(element->sblstat);
}

void    free_twostr(char *str, char *str0)
{
    if (str)
        free(str);
    if (str0)
        free(str0);
}

void    memory_waste(char *str)
{
    (void)str;
}

void    closedir_struct(t_ls *dir)
{
    if (dir)
    {
        if (dir->dirp != NULL)
            closedir(dir->dirp);
        if (dir->dirn != NULL)
            free(dir->dirn);
        free(dir);
    }
}

void    free_de(t_de *element)
{
        free(element->sblstat);
        free(element);
}

void    free_strp(char **strs, int i)
{
    int j;

    j = 0;
    while (j < i && strs)
    {
        if (strs[j])
            free(strs[j]);
        j++;
    }
    if (strs)
        free(strs);
}