/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/06/01 16:03:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	if (argc != 1 || *argv == NULL)
		return (2);
	shell_init(&shell, envp);
	while (1)
	{
		setup_signals();
		line = readline("$ ");
		if (!line)
			break ;
		if (check_quotes(line) == 1)
			printf("quotes error!\n");
		else
			shell_routine(&shell, line);
		add_history(line);
		free(line);
	}
	clean_shell(&shell);
	return (0);
}

void	shell_routine(t_shell *shell, char *line)
{
	if (shell_setup(shell, line) == 0)
	{
		execute(shell);
		clean_nodes(&(shell->s_cmd));
		clean_path(shell);
	}
}
