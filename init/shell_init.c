/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/19 11:51:16 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shell_init(t_shell *shell, char *line, char **env)
{
	// char	*s;
	// char	test[] = "$$$USER$USER$USERUSERUSERUSER-of-life pid = $$ exit=$?";
	shell->env = ft_get_env(env);
	shell->path = get_path(shell);
	shell->tokens = tokenize(line);
	shell->exit_code = 0;
	// printf("before expansion\n");
	// print_tokens(shell->tokens);
	expand_all(shell);
	// printf("** after expansion **\n");
	// print_tokens(shell->tokens);
	// s = expand(test, shell);
	// printf("%s : expanded to : %s\n",test, s);
	// print_tokens(shell->tokens);
	// expand_all(shell->tokens, shell);
	// printf("after expansion\n");
	// print_tokens(shell->tokens);
	/// handle quotes & expand
	shell->s_cmd = NULL;
	parser(&(shell->tokens), &(shell->s_cmd));
	print_nodes(shell->s_cmd);
}
