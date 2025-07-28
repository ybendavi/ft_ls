#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <string.h>

#define FLAGS "lRart"

void    sort_and_add(char *to_sort, t_list **content);
void    lookup(DIR *dirp, struct dirent *dp, t_list **dircontent_list);
void    look_in_dir(DIR *dirp);

#endif