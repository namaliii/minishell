/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:21:35 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 17:06:40 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * will check quotes and return 1 in case of not closed quotes
*/

int	check_quotes(char *input)
{
	if (has_open_quotes(input) == true)
		return (1);
	return (0);
}

bool	has_open_quotes(char *str)
{
	int		i;
	bool	inside_single_quotes;
	bool	inside_double_quotes;

	i = 0;
	inside_single_quotes = false;
	inside_double_quotes = false;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (!inside_double_quotes)
				inside_single_quotes = !inside_single_quotes;
		}
		else if (str[i] == '"')
		{
			if (!inside_single_quotes)
				inside_double_quotes = !inside_double_quotes;
		}
		i++;
	}
	return (inside_single_quotes || inside_double_quotes);
}
