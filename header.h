/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:40:51 by manki             #+#    #+#             */
/*   Updated: 2018/05/12 16:32:57 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int					ft_add(int a, int b);
int					ft_sub(int a, int b);
int					ft_mul(int a, int b);
int					ft_div(int a, int b);
int					ft_mod(int a, int b);

typedef int			(*t_fun)(int, int);

typedef struct		s_opp
{
	char			*c;
	t_fun			ff;
}					t_opp;

typedef struct		s_pile
{
	char			*elmt;
	struct s_pile	*previous;
}					t_pile;

int					ft_strcmp(char s1[], char s2[]);
int					ft_verif_operant(char *c, t_opp *tab);
void				ft_pile_stack(t_pile **pile, char *str);
char				*ft_pile_unstack(t_pile **p);
t_pile				*ft_new_pile(char *str);

char				**ft_strsplit(char const *s,char c);
char				*ft_itoa(int n);

#endif
