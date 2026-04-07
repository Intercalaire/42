
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		i = ft_lstlast(*lst);
		i->next = &*new;
	}
}
