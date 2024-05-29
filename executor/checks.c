/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:18:55 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/29 18:03:32 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	path_check(t_shell *shell, char *full_path, char *cmd)
{
	if (full_path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found", 2);
		ft_putstr_fd("\n", 2);
		shell->exit_code = 127;
		exit(127);
	}
}

void	exec_check(t_shell *shell, char *path, char **cmd, char **envp)
{
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": command not found", 2);
		ft_putstr_fd("\n", 2);
		shell->exit_code = 126;
		exit(126);
	}
}

void	pipe_check(t_shell *shell, int *fd_pipe)
{
	if (pipe(fd_pipe) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror("pipe error");
		ft_putstr_fd("\n", 2);
		shell->exit_code = 1;
		exit(1);
	}
}

void	fork_check(t_shell *shell, int pid)
{
	if (pid < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror("fork error");
		ft_putstr_fd("\n", 2);
		shell->exit_code = 1;
		exit(1);
	}
}

int	check_red_correct(t_shell *shell)
{
	t_token	*index;

	index = shell->tokens;
	while (index)
	{
		if (index->type > WORD && index->type < PIPE)
		{
			if (!index->next || index->next->type != WORD)
				return (1);
		}
		else if (index->type == PIPE)
		{
			if (!index->next)
				return (1);
		}
		index = index->next;
	}
	return (0);
}
