/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 13:41:01 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shell_init(t_shell *shell, char **env)
{
	shell->env = ft_get_env(env);
	shell->exit_code = 0;
}

void	shell_setup(t_shell *shell, char *line)
{
	shell->path = get_path(shell);
	shell->tokens = tokenize(line);
	set_hd_expanded(&(shell->tokens));
	expand_all(shell);
	shell->s_cmd = NULL;
	if (shell->tokens == NULL)
		printf("can't print tokens because it null\n");
	else
		print_tokens(shell->tokens);
	parser(&(shell->tokens), &(shell->s_cmd));
}

void	set_hd_expanded(t_token **tokens)
{
	t_token	*index;

	index = *tokens;
	while (index)
	{
		if (index->type == HEREDOC)
		{
			if (include_quotes(index->next->content) == 1)
				index->hd_expanded = 1;
		}
		index = index->next;
	}

}

int	include_quotes(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
