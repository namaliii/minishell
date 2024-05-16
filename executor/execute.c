/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:52 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 13:26:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute(t_shell *shell)
{
	// t_node	*cmds_cpy;
	// int		tmpin;
	// int		tmpout;
	char        *full_path;
	// tmpout = dup(1);
	// tmpin = dup(0);
	// cmds_cpy = shell->lst;
	// if (!cmds_cpy->next)
	// 	exec_single_cmd(shell);
	// // else
	// // 	exec_pipeline(shell, envp, tmpin, tmpout);
	full_path = check_cmd_path(shell->s_cmd->cmd[0], shell->path);
	if (full_path)
		printf("command found %s\n",full_path);
	else
		printf("command not found\n");
}
