/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:15:07 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 18:01:57 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_child(t_shell *shell, t_node *index, int *fd_pipe)
{
	char	*full_path;

	default_child_signals();
	if (index->next != NULL)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[1]);
	}
	if (index->files)
		open_redirect_files(shell, index);
	if (index->cmd[0] && is_builtin(shell, index->cmd[0]) == 0)
	{
		full_path = check_cmd_path(index->cmd[0], shell->path);
		path_check(shell, full_path, index->cmd[0]);
	}
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
