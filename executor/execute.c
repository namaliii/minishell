/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:52 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 18:17:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_child(t_shell *shell, t_node *index, int *fd_pipe)
{
	char	*full_path;

	full_path = check_cmd_path(index->cmd[0], shell->path);
	path_check(shell, full_path, index->cmd[0]);
	if (index->next != NULL)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[1]);
	}
	execve(full_path, index->cmd, NULL);

}

void	execute_parent(t_node **index, int *fd_pipe)
{
	wait(NULL);
	if ((*index)->next == NULL)
		close(STDIN_FILENO);
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], STDIN_FILENO);
		close(fd_pipe[0]);
	}
	*index = (*index)->next;
}

void	restore_std(int *tmpin, int *tmpout)
{
	dup2(*tmpin, STDIN_FILENO);
	close(*tmpin);
	dup2(*tmpout, STDOUT_FILENO);
	close(*tmpout);
}

void	execute(t_shell *shell)
{
	t_node	*index;
	int		fd_pipe[2];
	int		pid;
	int		status;
	int		tmpin;
	int		tmpout;

	tmpout = dup(STDOUT_FILENO);
	tmpin = dup(STDIN_FILENO);
	index = shell->s_cmd;
	while (index)
	{
		if (index->next != NULL)
		{
			pipe(fd_pipe);
			pipe_check(shell, fd_pipe);
		}
		pid = fork();
		fork_check(shell, pid);
		if (pid == 0)
			execute_child(shell, index, fd_pipe);
		else
		{
			execute_parent(&index, fd_pipe);
		}
	}
	restore_std(&tmpin, &tmpout);
	waitpid(pid, &status, 0);
	shell->exit_code = WEXITSTATUS(status);
}

