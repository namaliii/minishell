/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:00:10 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 19:30:50 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(t_shell *shell, char *cmd)
{
	int		i;

	i = 0;
	if (!cmd || cmd[0] == '\0')
		return (0);
	while (shell->builtins[i])
	{
		if (ft_strncmp(shell->builtins[i], cmd, ft_strlen(cmd)) == 0)
		{
			if (ft_strlen(shell->builtins[i]) == ft_strlen(cmd))
				return (1);
		}
		i++;
	}
	return (0);
}

void	execute_builtins(t_node *index, t_shell *shell)
{
	if (ft_strncmp("env", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		env(shell->env);
	else if (ft_strncmp("echo", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		echo(index->cmd);
	else if (ft_strncmp("export", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		export(shell, index);
	else if (ft_strncmp("pwd", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		pwd();
	else if (ft_strncmp("unset", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		unset(&(shell->env), index);
	else if (ft_strncmp("cd", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		cd(shell, index);
	else if (ft_strncmp("exit", index->cmd[0], ft_strlen(index->cmd[0])) == 0)
		ft_exit(shell, index);
}
