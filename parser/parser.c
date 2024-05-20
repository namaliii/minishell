/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:14:26 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/20 14:56:38 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * parser- will take a list of tokens and a list empty nodes 
 * and will convert the tokens into full commands with redirections
 * @tokens: is a list of tokens geenrated from the lexer
 * @s_cmd: will represent the list that contain each command
 * after getting splited by | 
*/

void	parser(t_token **tokens, t_node **s_cmd)
{
	t_token	*files;
	t_token	*cmd;
	t_token	*index;

	cmd = NULL;
	files = NULL;
	index = *tokens;
	while (index)
	{
		if (index->type > WORD && index->type < PIPE)
		{
			get_file(&index, &files);
		}
		else if (index->type == WORD)
		{
			get_cmd(&index, &cmd);
		}
		if (index == NULL || index->type == PIPE)
		{
			t_cmd(s_cmd, &index, &files, &cmd);
			cmd = NULL;
			files = NULL;
		}
	}
}
