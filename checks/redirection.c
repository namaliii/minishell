/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:15:42 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 16:28:26 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection_correct(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("1 str[i] == %c\n", str[i]);
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && (str[i] == '<' || str[i] == '>'))
		{
			i++;
			printf("2 str[i] == %c\n", str[i]);
			if (str[i] != '\0' && str[i] == str[i - 1])
			{
				i++;
				printf("3 str[i] == %c\n", str[i]);
				while (str[i] && ft_isspace(str[i]))
					i++;
				if (!str[i] || !((ft_isalnum(str[i]) == 1) || str[i] == ' ' || str[i] == '_'))
				{
					printf("Returning error\n");
					return (1);
				}
				i++;
			}
			else
			{
				while (str[i] && ft_isspace(str[i]))
					i++;
				if (!str[i] || !((ft_isalnum(str[i]) == 1) || str[i] == ' ' || str[i] == '_'))
				{
					printf("Returning error\n");
					return (1);
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}
