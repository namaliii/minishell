/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:07:13 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/21 15:53:23 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*token_last(t_token *lst)
{
	t_token	*index;

	index = lst;
	if (lst == NULL)
		return (NULL);
	while (index->next != NULL)
		index = index->next;
	return (index);
}

void	token_add_back(t_token **lst, t_token *new)
{
	t_token	*index;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		index = token_last(*lst);
		index->next = new;
		new->prev = index;
	}

}

t_token	*token_new(char *content, t_token_type type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->hd_expanded = 0;
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
