/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/19 15:10:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;
	// t_char	*lst;

	// t_token	*tokens;
	// t_node	*s_cmd;
	if (argc != 1 || *argv == NULL)
		return (2);
	while (1)
	{
		line = readline("$ ");  // Pass NULL to readline to use the default prompt
		if (!line)
			break ;
		if (ft_strncmp("exit", line, 4) == 0)
			return (0);
		else
		{
			if (check_quotes(line) == 0)
			{
				// printf("quotes are good\n");
				// tokens = tokenize(line);
				// print_tokens(tokens);
				// parser(&tokens, &s_cmd);
				// print_nodes(s_cmd);
				// lst = str_to_charlst(line);
				// print_c(lst);
				shell_init(&shell, line, envp);
				// env(shell.env);
				print_nodes(shell.s_cmd);
				execute(&shell);
				// clean_nodes(&s_cmd);
				clean_nodes(&(shell.s_cmd));
			}
			else
				printf("quotes Error\n");
			free(line);
		}
			// parsing(line);
	}
	return 0;
}
