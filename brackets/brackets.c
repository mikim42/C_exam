/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:26:25 by mikim             #+#    #+#             */
/*   Updated: 2017/06/28 21:25:47 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_valid(char a, char b)
{
	if (a == ']' && b == '[')
		return (1);
	if (a == '}' && b == '{')
		return (1);
	if (a == ')' && b == '(')
		return (1);
	return (0);
}

int		brackets(char *s)
{
	char	tab[10000];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
			tab[j++] = s[i];
		else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
			if (!check_valid(s[i], tab[--j]))
				return (write(1, "Error\n", 6));
	}
	if (j == 0)
		return (write(1, "OK\n", 3));
	return (write(1, "Error\n", 6));
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		return (write(1, "\n", 1));
	while (av[i])
		brackets(av[i++]);
	return (00);
}
