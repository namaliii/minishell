/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:21:35 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 11:47:45 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "checks.h"

/**
 * will check quotes and return 1 in case of not closed quotes 
*/

int	check_quotes(char *input)
{
	if (check_double_quotes(input) == 1)
		return (1);
	if (check_single_quotes(input) == 1)
		return (1);
	return (0);
}

int	check_single_quotes(char *input)
{
	int	i;
	int	nb_quotes;

	i = 0;
	nb_quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			nb_quotes++;
		i++;
	}
	if (nb_quotes == 0 || nb_quotes % 2 == 0)
		return (0);
	else
		return (1);
}

int	check_double_quotes(char *input)
{
	int	i;
	int	nb_quotes;

	i = 0;
	nb_quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
			nb_quotes++;
		i++;
	}
	if (nb_quotes == 0 || nb_quotes % 2 == 0)
		return (0);
	else
		return (1);
}


