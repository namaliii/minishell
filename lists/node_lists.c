/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:58:03 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:51:26 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*node_last(t_node *lst)
{
	t_node	*index;

	index = lst;
	if (lst == NULL)
		return (NULL);
	while (index->next != NULL)
		index = index->next;
	return (index);
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*index;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		index = node_last(*lst);
		index->next = new;
		new->prev = index;
		new->next = NULL;
	}
}

t_node	*node_new(char **cmd, t_token *files)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->cmd = cmd;
	node->files = files;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
