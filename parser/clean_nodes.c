/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:36:07 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/06/01 15:18:39 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_nodes(t_node **node)
{
	t_node	*index;

	if (!node || !*node)
		return ;
	while (*node)
	{
		index = *node;
		*node = (*node)->next;
		index->next = NULL;
		index->prev = NULL;
		clean_array(index->cmd);
		clean_files(&(index->files));
		free(index);
	}
}

void	clean_array(char **str)
{
	int	i;

	if (!str || !*str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	clean_files(t_token **files)
{
	t_token	*index;

	if (!files || !*files)
		return ;
	while (*files)
	{
		index = *files;
		*files = (*files)->next;
		if (*files)
			(*files)->prev = NULL;
		free(index->content);
		index->next = NULL;
		index->prev = NULL;
		free(index);
	}
}

void	clean_shell(t_shell *shell)
{
	if (shell->builtins)
		clean_array(shell->builtins);
	if (shell->env)
		clean_env(shell);
	rl_clear_history();
}
