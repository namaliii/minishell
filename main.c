/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 13:38:21 by mfaoussi         ###   ########.fr       */
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
		if (ft_strncmp("exit", line, 4) == 0)
			return (0);
		else
		{
			if (check_quotes(line) == 0)
			{
				shell_setup(&shell, line);
				execute(&shell);
				clean_nodes(&(shell.s_cmd));
				clean_path(&shell);
			}
			else
				printf("quotes Error\n");
			free(line);
		}
	}
	return (0);
}

