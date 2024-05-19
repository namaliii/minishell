// void	delete_expanded_node(t_token **node)
// {
// 	t_token	*prev;

// 	if (!node || !*node)
// 		return ;
// 	prev = (*node)->prev;
// 	if (prev)
// 	{
// 		prev->next = (*node)->next;
// 		(*node)->prev = NULL;
// 		(*node)->next = NULL;
// 		free((*node)->content);
// 		free((*node));
// 		(*node) = prev->next;
// 		if (*node)
// 			(*node)->prev = prev;
// 	}
// 	else
// 	{
// 		prev = (*node);
// 		(*node) = (*node)->next;
// 		if (*node)
// 			(*node)->prev = NULL;
// 		prev->next = NULL;
// 		free(prev->content);
// 		free(prev);
// 	}
// 	if (*node == NULL)
// 		printf("all nodes deleted\n");
// }