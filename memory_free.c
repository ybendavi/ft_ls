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
        free(dir);
    }
}

void    free_de(t_de *element)
{
        free(element->sblstat);
        free(element);
}