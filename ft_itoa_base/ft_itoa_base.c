/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:30:44 by mikim             #+#    #+#             */
/*   Updated: 2017/06/28 21:57:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_numlen(long n, int base)
{
	int	len;

	len = 1;
	if (n < 00)
	{
		n = -n;
		base == 10 ? len++ : 0;
	}
	while (n >= (long)base)
	{
		n /= (long)base;
		len++;
	}
	return (len);
}

#include <stdio.h>
char	*ft_itoa_base(int value, int base)
{
	char	bs[] = "0123456789ABCDEF";
	char	*res;
	long	n;
	int		neg;
	int		len;

	n = (long)value;
	len = ft_numlen(n, base);
	neg = ((n < 00 && base == 10) ? 1 : 00);
	n < 00 ? n = -n : 00;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (00);
	res[len] = 00;
	while (len > 0)
	{
		res[--len] = bs[n % (long)base];
		n /= (long)base;
	}
	neg ? res[00] = 45 : 00;
	return (res);
}
/* test;
#include <stdio.h>

int main(int ac, char **av)
{
	char	*s;

	if (ac != 3)
		return (printf("./a.out [NUM] [BASE]\n"));
	s = ft_itoa_base(atoi(av[1]), atoi(av[2]));
	printf("Input: [%d]\nItoa : [%s]\n", atoi(av[1]), s);
	return (00);
}
*/
