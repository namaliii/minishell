/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 13:09:45 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shell_init(t_shell *shell, char *line, char **env)
{
	shell->tokens = tokenize(line);
	shell->env = ft_get_env(env);
	/// handle quotes & expand
	parser(&(shell->tokens), &(shell->s_cmd));
	shell->path = get_path(shell);
}

// char	*handle_quotes_expand(t_shell *shell, t_token *tokens)
// {
// 	int		i;
// 	t_token	*token_cpy;
// 	char	*inside;
// 	int		single_quotes;
// 	int		double_quotes;

// 	i = 0;
// 	token_cpy = tokens;
// 	inside = NULL;
// 	while (token_cpy)
// 	{
// 		while (token_cpy->content[i])
// 		{
// 			if (token_cpy->content[i] == '\"')
// 				double_quotes++;
// 			else if (token_cpy->content[i] == '\'')
// 				single_quotes++;
// 			while (single_quotes)
// 			if (double_quotes % 2 == 0)
// 		}
// 		token_cpy = token_cpy->next;
// 	}
// }
