/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:52 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/26 15:50:45 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	execute_child_sg(t_shell *shell, t_node *index)
// {
// 	char	*full_path;

// 	default_child_signals();
// 	if (index->cmd[0])
// 	{
// 		full_path = check_cmd_path(index->cmd[0], shell->path);
// 		path_check(shell, full_path, index->cmd[0]);
// 	}
// 	if (index->files)
// 		open_redirect_files(shell, index);
// 	if (index->cmd[0])
// 		exec_check(shell, full_path, index->cmd, NULL);
// 	else
// 		exit(0);
// }

void	execute_child(t_shell *shell, t_node *index, int *fd_pipe)
{
	char	*full_path;

	default_child_signals();
	if (index->cmd[0] && is_builtin(shell, index->cmd[0]) == 0)
	{
		full_path = check_cmd_path(index->cmd[0], shell->path);
		path_check(shell, full_path, index->cmd[0]);
	}
	if (index->next != NULL)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[1]);
	}
	if (index->files)
		open_redirect_files(shell, index);
	if (index->cmd[0] && is_builtin(shell, index->cmd[0]) == 0)
		exec_check(shell, full_path, index->cmd, exec_env(shell));
	else if (index->cmd[0] && is_builtin(shell, index->cmd[0]) == 1)
		execute_builtins(index, shell);
	exit(0);
}

void	execute_parent(t_node **index, int *fd_pipe)
{
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

void	create_pipe(t_shell *shell, t_node *index)
{
	if (index->next != NULL)
	{
		pipe(shell->fd_pipe);
		pipe_check(shell, shell->fd_pipe);
	}
}

void	ft_wait_all(int *status)
{
	int	gpid;

	gpid = wait(status);
	while (gpid > 0)
		gpid = wait(status);
}

void	execute(t_shell *shell)
{
	t_node	*index;
	int		pid;
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
		while (index)
		{
			ignore_signals();
			create_pipe(shell, index);
			pid = fork();
			fork_check(shell, pid);
			if (pid == 0)
				execute_child(shell, index, shell->fd_pipe);
			else
				execute_parent(&index, shell->fd_pipe);
		}
		restore_std(&tmpin, &tmpout);
		ft_wait_all(&status);
		// while (wait(&status) > 0)
		// 	continue ;
		// waitpid(pid, &status, 0);
		// waitpid(pid, &status, 0);

		shell->exit_code = WEXITSTATUS(status);
	}
}
