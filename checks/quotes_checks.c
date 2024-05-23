/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:21:35 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/23 22:04:51 by anamieta         ###   ########.fr       */
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

// int	check_quotes(char *input)
// {
// 	if (check_double_quotes(input) == 1)
// 		return (1);
// 	if (check_single_quotes(input) == 1)
// 		return (1);
// 	return (0);
// }

// int	check_single_quotes(char *input)
// {
// 	int	i;
// 	int	nb_quotes;

// 	i = 0;
// 	nb_quotes = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '\'')
// 			nb_quotes++;
// 		i++;
// 	}
// 	if (nb_quotes == 0 || nb_quotes % 2 == 0)
// 		return (0);
// 	else
// 		return (1);
// }

// int	check_double_quotes(char *input)
// {
// 	int	i;
// 	int	nb_quotes;

// 	i = 0;
// 	nb_quotes = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '"')
// 			nb_quotes++;
// 		i++;
// 	}
// 	if (nb_quotes == 0 || nb_quotes % 2 == 0)
// 		return (0);
// 	else
// 		return (1);
// }
