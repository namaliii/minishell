/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:33:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 12:58:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	constr = (char *)ft_calloc((lens1 + lens2 + 1), sizeof(char));
	if (constr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		constr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		constr[i] = s2[j];
		i++;
		j++;
	}
	return (constr);
}
