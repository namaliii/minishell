/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:54:59 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:53:26 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * t_cmd-each time we encounter a '|' or end of list in our 
 * t_token list that hold the tokens , we need to convert all 
 * gathered commands ,args and file redirections into our struct
 * t_node that holds the command and args 
 *  so t_cmd will create a node and putt the data into it and get
 * ready to receieve new data after the pipe or stop if its the end
*/

void	t_cmd(t_node **s_cmd, t_token **index, t_token **files, t_token **cmd)
{
	char	**command;
	t_token	*i;
	t_node	*new_cmd;

	i = *index;
	if (*index)
	{
		*index = (*index)->next;
		i->prev = NULL;
		i->next = NULL;
		free(i->content);
		free(i);
	}
	command = list_to_char(cmd);
	new_cmd = node_new(command, *files);
	node_add_back(s_cmd, new_cmd);
	new_cmd = NULL;
	*files = NULL;
}
/**
 * list_to_char- will take a t-token list that contain commands
 * and will convert it into char **array that will hold the commands
 * each element of the list will be freed in the process
 * Return: char ** array that holds the commands
*/

char	**list_to_char(t_token **cmd)
{
	char	**command;
	int		size;
	t_token	*index;

	size = get_list_length(*cmd) + 1;
	command = malloc(sizeof(char *) * size);
	if (!command)
		return (NULL);
	size = 0;
	while (*cmd)
	{
		index = *cmd;
		*cmd = (*cmd)->next;
		command[size] = index->content;
		size++;
		index->content = NULL;
		index->next = NULL;
		index->prev = NULL;
		free(index);
	}
	command[size] = NULL;
	return (command);
}
