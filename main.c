/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:57 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 12:00:21 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "checks/checks.h"
#include "lexer/lexer.h"
#include "lists/lists.h"


int	main(void)
{
	char	*line;
	t_token	*tokens;
	// t_node	*s_cmd;
	while (1)
	{
		line = readline("$ ");  // Pass NULL to readline to use the default prompt
		if (line == NULL)
			printf("error taking the input\n");
		else
		{
			if (check_quotes(line) == 0)
			{
				printf("quotes are good\n");
				tokens = tokenize(line);
				
				// parser(&tokens, &s_cmd);
				// print_nodes(s_cmd);
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