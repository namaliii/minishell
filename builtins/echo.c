/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:00:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/30 19:29:35 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	n_flag(char *cmd)
{
	int	i;

	if (cmd[0] != '-')
		return (0);
	i = 1;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(char **cmd)
{
	int	start_idx;
	int	nflag;

	start_idx = 1;
	nflag = 0;
	while (cmd[start_idx] && n_flag(cmd[start_idx]))
	{
		nflag = 1;
		start_idx++;
	}
	while (cmd[start_idx] != NULL)
	{
		printf("%s", cmd[start_idx]);
		if (cmd[start_idx + 1] != NULL)
			printf(" ");
		start_idx++;
	}
	if (!nflag)
		printf("\n");
	return (EXIT_SUCCESS);
}
