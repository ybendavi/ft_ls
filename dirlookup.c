#include "ft_ls.h"

int lookup_allocs(struct dirent *dp, t_ls *dir_struct, t_de **element)
{
        size_t path_size;
        char    *path;

        path_size = ft_strlen(dp->d_name) + ft_strlen(dir_struct->dirn) + 2;
        if (!(path = ft_calloc(sizeof(char), path_size)))
            return (1);
        if (!(*element = ft_calloc(1, sizeof(t_de))))
        {
            free(path);
            return(1);
        }
        if (!((*element)->sblstat = ft_calloc(1, sizeof(struct stat))))
        {
            free(path);
            free(*element);
            return (1);
        }
        ft_strlcpy(path, dir_struct->dirn, path_size + 1);
        ft_strlcat(path, "/", path_size + 1);
        ft_strlcat(path, dp->d_name, path_size + 1);
        if (lstat(path, (*element)->sblstat) == -1)
        {
            lstat_error(path);
            free(path);
            free((*element)->sblstat);
            free(*element);
            return (2);
        }
        free(path);
        (*element)->dp = dp;
        return (0);
}

int lookup(t_ls *dir_struct, struct dirent *dp, t_list **dircontent_list, int flags)
{ 
   t_de    *element;
   int      res;

   element = NULL;
    if (dp)
    {
        res = lookup_allocs(dp, dir_struct, &element);
        if (res == 1)
            return (1);
        //free(element->sblstat);
        //free(element);
        //printf("%s\n", dp->d_name);
        if (res != 2)
        {
            if (sort_and_add(element, dircontent_list, flags))
                return(1);
        }
        if(lookup(dir_struct, readdir(dir_struct->dirp), dircontent_list, flags))
            return (1);
    }
    return(0);
}