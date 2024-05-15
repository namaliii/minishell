/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 13:06:16 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	t_token	*tokens;
	t_node	*s_cmd;
	while (1)
	{
		line = readline("$ ");  // Pass NULL to readline to use the default prompt
		if (ft_strncmp("exit", line, 4) == 0)
			return (0);
		else
		{
			if (check_quotes(line) == 0)
			{
				printf("quotes are good\n");
				tokens = tokenize(line);
				// print_tokens(tokens);
				parser(&tokens, &s_cmd);
				print_nodes(s_cmd);
				// clean_nodes(&s_cmd);
			}
			else
				printf("quotes Error\n");
			free(line);
		}
			// parsing(line);
	}
	return 0;
}