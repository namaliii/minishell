/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 18:51:10 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shell_init(t_shell *shell, char *line, char **env)
{
	shell->tokens = tokenize(line);
	shell->env = ft_get_env(env);
	/// handle quotes & expand
	shell->s_cmd = NULL;
	parser(&(shell->tokens), &(shell->s_cmd));
	shell->path = get_path(shell);
}
