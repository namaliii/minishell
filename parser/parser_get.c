/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:48:19 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:52:51 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * get_list_length will count how many nodes are in t_token list
*/

int	get_list_length(t_token *cmd)
{
	t_token	*index;
	int		size;

	size = 0;
	if (!cmd)
		return (0);
	index = cmd;
	while (index)
	{
		size++;
		index = index->next;
	}
	return (size);
}
/**
 * get_cmd each time we encounter a command 
 * we take it into our cmd list 
 * list , so we re separating commands from files 
 * of course the node will be moved from index to cmd
*/

void	get_cmd(t_token **index, t_token **cmd)
{
	t_token	*word;

	word = *index;
	*index = (*index)->next;
	if (*index)
		(*index)->prev = NULL;
	word->prev = NULL;
	word->next = NULL;
	token_add_back(cmd, word);
}
/**
 * get_file each time we encounter a redirection 
 * we take it and the token after it into our files
 * list , so we re separating commands from files 
 * of course the node will be moved from index to files
*/

void	get_file(t_token **index, t_token **files)
{
	t_token	*token;
	t_token	*next_is_file;

	token = *index;
	next_is_file = token->next;
	*index = (*index)->next;
	(*index)->prev = NULL;
	(*index) = (*index)->next;
	if (*index)
		(*index)->prev = NULL;
	token->next = NULL;
	token_add_back(files, token);
	next_is_file->prev = NULL;
	next_is_file->next = NULL;
	token_add_back(files, next_is_file);
}

int	is_pipe(t_token *index)
{
	if (!index)
		return (0);
	if (index->type == PIPE)
		return (1);
	return (0);
}
