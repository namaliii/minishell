/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:34:24 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/30 19:58:04 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*env_last(t_env *lst)
{
	t_env	*index;

	index = lst;
	if (lst == NULL)
		return (NULL);
	while (index->next != NULL)
		index = index->next;
	return (index);
}

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*index;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		index = env_last(*lst);
		index->next = new;
		new->prev = index;
	}
}

t_env	*env_new(char **content, int export)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	node->export = export;
	return (node);
}
