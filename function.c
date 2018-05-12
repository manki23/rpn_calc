/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:58:36 by manki             #+#    #+#             */
/*   Updated: 2018/05/12 17:39:26 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp(char s1[], char s2[])
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_verif_operant(char *c, t_opp *tab)
{
	int		verif;
	int		i;

	verif = 0;
	i = -1;
	while (!verif && tab[++i].c)
		if (!ft_strcmp(c, tab[i].c))
			verif = 1;
	return (verif);
}

void	ft_pile_stack(t_pile **pile, char *str)
{
	t_pile		*tmp;


	tmp = (t_pile *)malloc(sizeof(t_pile));
	if (tmp)
	{
		tmp->elmt = str;
		tmp->previous = *pile;
		*pile = tmp;
	}
}

char	*ft_pile_unstack(t_pile **p)
{
	char	*e;
	t_pile	*tmp;

	if (*p)
	{
		tmp = (*p)->previous;
		e = (*p)->elmt;
		*p = NULL;
		*p = tmp;
		return (e);
	}
	return (NULL);
}

t_pile		*ft_new_pile(char *str)
{
	t_pile		*fresh;

	if (!(fresh = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	fresh->elmt = str;
	fresh->previous = NULL;
	return (fresh);
}
