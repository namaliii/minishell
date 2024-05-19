/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/19 18:17:36 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shell_init(t_shell *shell, char *line, char **env)
{
	shell->env = ft_get_env(env);
	shell->path = get_path(shell);
	shell->tokens = tokenize(line);
	shell->exit_code = 0;
	expand_all(shell);
	shell->s_cmd = NULL;
	if (shell->tokens == NULL)
		printf("can't print tokens because it null\n");
	else
		print_tokens(shell->tokens);
	parser(&(shell->tokens), &(shell->s_cmd));
}
