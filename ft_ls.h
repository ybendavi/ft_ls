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
    char            *dirn;
}			t_ls;

typedef struct s_de
{
	struct dirent   *dp;
    struct stat     *sblstat;
}			t_de;

int     launcher(char **av, int flags, int ac, int ismain);
int     sort_and_add(t_de *element, t_list **content, int flags);
int     lookup(t_ls *dir_struct, struct dirent *dp, t_list **dircontent_list, int flags);
int     check_for_directories(char **av, t_list **dirs, int ac, int ismain);
int     directory_checker(char **av, int ac, char ***buff);
int     look_in_dir(t_ls *dir_struct, int flags);
int     flags_checker(char **av, int ac);
int     flag_value(char flag);
void	ft_lstiter_with_flag(t_list *lst, int (*f)(void *, int), int flag);
void	ft_lstiterr_with_flag(t_list *lst, int (*f)(void *, int), int flag);
int     ft_lstiterfree_with_flag(t_list *lst, int (*f)(void *, int), int flag);
int     ft_lstiterrfree_with_flag(t_list *lst, int (*f)(void *, int), int flag);
int     striter(char *str, char (*f)(int, int));
char    to_lower_map(int i, int c);
void    get_infos(char *path, struct stat *sblstat);
void    lstat_error(char *filename);
// Memory handler
void    free_dircontent_list(t_de *element);
void    free_twostr(char *str, char *str0);
void    memory_waste(char *str);
void    closedir_struct(t_ls *dir);
void    free_de(t_de *element);
void    free_strp(char **strs, int i);


#endif