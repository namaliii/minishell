/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 16:48:37 by mfaoussi         ###   ########.fr       */
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
			// if (check_quotes(line) == 0 && redirection_correct(line) == 0)
			if (check_quotes(line) == 1)
				printf("quotes error!\n");
			else
				shell_routine(&shell, line);
			// else if (redirection_correct(line) == 1)
			// 	printf("minishell: syntax error near unexpected token\n");
			add_history(line);
			free(line);
		}
	}
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

			// {
			// 	shell_setup(&shell, line);
			// 	execute(&shell);
			// 	clean_nodes(&(shell.s_cmd));
			// 	clean_path(&shell);
			// }