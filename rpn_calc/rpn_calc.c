/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:27:38 by mikim             #+#    #+#             */
/*   Updated: 2017/06/28 21:16:20 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	check_space(char *s, int *i)
{
	int j;

	j = *i;
	while (s[j] == ' ')
		j++;
	*i = j;
}

void	skip_num(char *s, int *i)
{
	int j;

	j = *i;
	while (s[j] >= '0' && s[j] <= '9')
		j++;
	*i = j;
}

int		opt(int a, char op, int b)
{
	int	res;
	
	res = 0;
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	if (op == '*')
		return (a * b);
	return (00);
}

int		rpn_calc(char *s)
{
	int	tab[10000];
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		check_space(s, &i);
		if ((s[i] >= '0' && s[i] <= '9') ||	((s[i] == '+' || s[i] == '-') &&
			(s[i + 1] >= '0' && s[i + 1] <= '9')))
		{
			tab[j++] = atoi(&s[i++]);
			skip_num(s, &i);
		}
		if (((s[i] == '-' || s[i] == '+') && (s[i + 1] == ' ' ||
			s[i + 1] == '\0')) || s[i] == '/' || s[i] == '*' || s[i] == '%')
		{
			if (j < 1 || ((s[i] == '%' || s[i] == '/') && tab[j - 1] == 0))
				return (printf("Error\n"));
			tab[j - 2] = opt(tab[j - 2], s[i], tab[j - 1]);
			j--;
		}
	}
	if (j != 1)
		return (printf("Error\n"));
	return (printf("%d\n", tab[0]));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Error\n"));
	rpn_calc(av[1]);
	return (00);
}
