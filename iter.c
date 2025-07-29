#include "ft_ls.h"

void	ft_lstiter_with_flag(t_list *lst, void (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
		if (lst->content)
			(*f)(lst->content, flag);
		ft_lstiter_with_flag(lst->next, f, flag);
	}
}

void	ft_lstiterr_with_flag(t_list *lst, void (*f)(void *, int), int flag)
{
	if (lst != NULL)
	{
        ft_lstiterr_with_flag(lst->next, f, flag);
		if (lst->content)
			(*f)(lst->content, flag);
	}
}