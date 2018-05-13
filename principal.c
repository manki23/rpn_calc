/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:41:21 by manki             #+#    #+#             */
/*   Updated: 2018/05/12 17:52:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_opp	g_opptab[] =
{
	{"+", &ft_add},
	{"-", &ft_sub},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod}
};

static int		ft_error(int error)
{
	printf("Error\n");
	return (error);
}

static int		ft_verif(char str[])
{
	int		i;
	int		code;

	code = 3;
	if (ft_verif_operant(str, g_opptab) && str[1] == '\0')
		code = 2;
	i = -1;
	if (str[0] == '-')
		i = 0;
	while (code != 2 && code != 0 && str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			code = 1;
		else
			code = 0;
	}
	return (code);
}

static char		*ft_calcul(t_pile **pile, char *str)
{
	int		a;
	int		b;
	int		i;

	if (!ft_strcmp(pile[0]->elmt, "End") || !ft_strcmp(pile[0]->previous->elmt, "End"))
		return ("Error");
	b = atoi(ft_pile_unstack(pile));
	a = atoi(ft_pile_unstack(pile));
	i = -1;
	while (g_opptab + ++i)
	{
		if (!ft_strcmp(str, (g_opptab + i)->c))
		{
			if ((str[0] == '/' || str[0] == '%') && b == 0)
				return ("Error");
			return (ft_itoa((g_opptab + i)->ff(a, b)));
		}
	}
	return ("Error");
}

int		main(int ac, char *av[])
{
	int		i;
	char	*result;
	int		code;
	char	**tab;
	t_pile	*pile;

	ac--;
	av++;
	if (ac == 1)
	{
		if (!(tab = ft_strsplit(av[0], ' ')) ||
				!(pile = ft_new_pile("End")))
			return (ft_error(-2));
		i = -1;
		while (tab && tab[++i])
		{
			if (!(code = ft_verif(tab[i])))
				return (ft_error(-3));
			if (code == 1)
				ft_pile_stack(&pile, tab[i]);
			else if (code == 2)
			{
				result = ft_calcul(&pile, tab[i]);
				ft_pile_stack(&pile, result);
			}
		}
		if (pile->previous && !ft_strcmp(pile->previous->elmt, "End"))
			printf("%s\n", ft_pile_unstack(&pile));
		else
			return (ft_error(-4));
		return (0);
	}
	else
		return (ft_error(-1));
}
