/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:20 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 17:51:57 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_env **env, char *str)
{
	env_delete(env, str);
}

void	env_delete(t_env **env, char *var)
{
	t_env	*index;
	t_env	*node;

	if (!env || !*env || !var || var[0] == '\0')
		return ;
	index = *env;
	while (index)
	{
		if (ft_strncmp(index->content[0], var, ft_strlen(var)) == 0)
		{
			node = index;
			index = index->next;
			if (node->prev)
				(node->prev)->next = index;
			else
				*env = (*env)->next;
			if (index)
				index->prev = node->prev;
			node->prev = NULL;
			node->next = NULL;
			env_free(&node);
		}
		else
			index = index->next;
	}
}

void	env_free(t_env **node)
{
	int	i;

	if (!node || !*node)
		return ;
	i = 0;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	while ((*node)->content[i])
	{
		free((*node)->content[i]);
		i++;
	}
	free((*node)->content);
	free(*node);
}
