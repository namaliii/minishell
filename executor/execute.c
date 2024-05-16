/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:52 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 13:50:14 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute(t_shell *shell)
{
	t_node	*index;
	int		pid;
	char	*full_path;

	index = shell->s_cmd;
	while (index)
	{
		pid = fork();
		fork_check(shell, pid);
		if (pid == 0)
		{
			full_path = check_cmd_path(index->cmd[0], shell->path);
			if (full_path)
				execve(full_path, index->cmd, NULL);
			else
				printf("command not found\n");
		}
		wait(NULL);
		index = index->next;
	}
}
	// char        *full_path;

