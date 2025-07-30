#include "ft_ls.h"

int	ft_lstiter_with_flag(t_list *lst, int (*f)(void *, int), int flag)
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
		if (ft_lstiter_with_flag(lst->next, f, flag))
			return (1);
	}
	return (0);
}

int	ft_lstiterr_with_flag(t_list *lst, int (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
        if (ft_lstiterr_with_flag(lst->next, f, flag))
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
	return (0);
}