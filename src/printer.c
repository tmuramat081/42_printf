/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:13:34 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/23 23:32:02 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	free_output(t_print *output)
{
	free(output->number);
	output->number = NULL;
	free(output->sign);
	output->sign = NULL;
	free(output->padding);
	output->padding = NULL;
}

int	print_field(char *str1, char *str2, char *str3)
{
	int	ret;

	ret = ft_putstr_cnt(str1);
	ret += ft_putstr_cnt(str2);
	ret += ft_putstr_cnt(str3);
	return (ret);
}

/* Put functions in right order. To left-align, print 'padding' firstly. */
int	setup_field(t_print *output, t_finfo input)
{
	int	ret;

	if (output->status == ERROR)
	{
		free_output(output);
		return (-1);
	}
	if (input.hyphen == true)
		ret = print_field(output->sign, output->number, output->padding);
	else
	{
		if (input.zero == false)
			ret = print_field(output->padding, output->sign, output->number);
		else
			ret = print_field(output->sign, output->padding, output->number);
	}
	free_output(output);
	return (ret);
}
