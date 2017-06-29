/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:09:14 by mikim             #+#    #+#             */
/*   Updated: 2017/06/28 21:33:21 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int n)
{
	char base[] = "0123456789abcdef";

	if (n > 15)
	{
		write(1, &base[(n / 16) % 16], 1);
		write(1, &base[n % 16], 1);
	}
	else if (n < 16)
	{
		write(1, "0", 1);
		write(1, &base[n % 16], 1);
	}
}

void	print_ascii(int n)
{
	if (31 < n && n < 127)
		write(1, &n, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*tab;
	size_t			i;
	size_t			j;
	size_t			k;

	i = 0;
	tab = (unsigned char*)addr;
	while (i < size)
	{
		j = -1;
		while (++j < 16)
		{
			(i + j < size) ? print_hex(tab[i + j]) : write(1, "  ", 2);
			(j != 0 && j % 2 == 1) ? write(1, " ", 1) : 0;
		}
		k = -1;
		while (++k < 16 && i < size)
			print_ascii(tab[i++]);
		write(1, "\n", 1);
	}
}
/*	test;
int		main()
{
	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	int tab2[10] = {10, 123, 34153, 313466, 659785, 13415, 12194, 399456};

	print_memory(tab, sizeof(tab));
	write(1, "\n\n", 2);
	print_memory(tab2, sizeof(tab2));
	return(0);
}
*/
