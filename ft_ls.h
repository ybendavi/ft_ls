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

typedef struct s_ls
{
	DIR             *dirp;
    char            *flags;
}			t_ls;

void    sort_and_add(char *to_sort, t_list **content);
void    lookup(DIR *dirp, struct dirent *dp, t_list **dircontent_list);
void    look_in_dir(DIR *dirp, int flags);
int     flags_checker(char **av, int ac);
int     flag_value(char flag);
void	ft_lstiter_with_flag(t_list *lst, void (*f)(void *, int), int flag);
void	ft_lstiterr_with_flag(t_list *lst, void (*f)(void *, int), int flag);


#endif