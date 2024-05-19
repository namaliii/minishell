/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:48:08 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/18 17:19:26 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	nlength(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*return_min(void)
{
	char	*ptr;
	int		n;
	int		nlen;

	n = 214748364;
	nlen = nlength(n);
	ptr = malloc(nlength(n) + 3);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '-';
	ptr[nlen + 2] = '\0';
	ptr[nlen + 1] = '8';
	while (nlen > 0)
	{
		ptr[nlen] = (n % 10) + '0';
		n = n / 10;
		nlen--;
	}
	return (ptr);
}

static int	ifneg(int *neg, int *size)
{
	*neg = 1;
	*size = *size + 1;
	return (-1);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		size;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (return_min());
	size = nlength(n);
	if (n < 0)
		n = n * ifneg(&neg, &size);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[size] = '\0';
	if (n == 0)
		s[0] = '0';
	if (neg == 1)
		s[0] = '-';
	while (n)
	{
		size--;
		s[size] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

// int main(void)
// {
// 	int a = 0;
// 	char *b = ft_itoa(a);
// 	printf("|%s|\n",b);
// 	//printf("\n\ndis ist %lu\n\n",sizeof(b));
// 	return (0);
// }