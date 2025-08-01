#include "ft_ls.h"

int	ft_lstiterfree_with_flag(t_list *lst, int (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
		if (lst->content)
		{
			if ((*f)(lst->content, flag))
			{
				ft_lstclear(&(lst->next), (void*)closedir_struct);
				free(lst);
				return (1);
			}
		}
		if (ft_lstiterfree_with_flag(lst->next, f, flag))
		{
			free(lst);
			return (1);
		}
	}
	free(lst);
	return (0);
}

void	ft_lstiter_with_flag(t_list *lst, int (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
		if (lst->content)
			(*f)(lst->content, flag);
		ft_lstiter_with_flag(lst->next, f, flag);
	}
}

void	ft_lstiterr_with_flag(t_list *lst, int (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
		ft_lstiterr_with_flag(lst->next, f, flag);
		if (lst->content)
			(*f)(lst->content, flag);
	}
}

int	ft_lstiterrfree_with_flag(t_list *lst, int (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
        if (ft_lstiterrfree_with_flag(lst->next, f, flag))
		{
			closedir_struct(lst->content);
			free(lst);
			return (1);
		}
		if (lst->content)
		{
			if ((*f)(lst->content, flag))
			{
				free(lst);
				return (1);
			}
		}
	}
	free(lst);
	return (0);
}

char    to_lower_map(int i, int c)
{
    (void)i;
    return (ft_tolower(c));
}

int     striter(char *str, char (*f)(int, int))
{
    int    i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            str[i] = (*f)(i, str[i]);
            i++;
        }
    }
    return (0);
}