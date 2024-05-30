/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:52 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/30 17:18:53 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_loop(t_shell *shell, t_node **index, int *tmpin, int *tmpout)
{
	int		pid;

	while (*index)
	{
		ignore_signals();
		create_pipe(shell, *index);
		pid = fork();
		fork_check(shell, pid);
		if (pid == 0)
		{
			close(*tmpin);
			close(*tmpout);
			execute_child(shell, *index, shell->fd_pipe);
		}
		else
			execute_parent(index, shell->fd_pipe);
	}
}

void	execute(t_shell *shell)
{
	t_node	*index;
	int		status;
	int		tmpin;
	int		tmpout;

	tmpout = dup(STDOUT_FILENO);
	tmpin = dup(STDIN_FILENO);
	index = shell->s_cmd;
	heredoc(shell);
	if (index && index->next == NULL && is_builtin(shell, index->cmd[0]) == 1)
	{
		if (index->files)
			open_redirect_files(shell, index);
		execute_builtins(index, shell);
		restore_std(&tmpin, &tmpout);
	}
	else
	{
		exec_loop(shell, &index, &tmpin, &tmpout);
		restore_std(&tmpin, &tmpout);
		ft_wait_all(&status);
		shell->exit_code = WEXITSTATUS(status);
	}
}

		// while (wait(&status) > 0)
		// 	continue ;
		// waitpid(pid, &status, 0);
		// waitpid(pid, &status, 0);
