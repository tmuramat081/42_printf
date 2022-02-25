/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:57:34 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/23 23:45:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*add_zero(char *src, size_t len)
{
	char	*buff;
	char	*dst;

	buff = calloc(len + 1, sizeof(char));
	if (!buff)
		return (NULL);
	ft_memset(buff, '0', len);
	dst = ft_strjoin(buff, src);
	free(buff);
	free(src);
	return (dst);
}

/* If the precision is longer than digits, add '0' characters. */
void	apply_precision(unsigned long long value,
			t_print *output, t_finfo input)
{
	ssize_t	number_len;

	if (input.precision == 0 && value == 0)
	{
		free(output->number);
		output->number = NULL;
		return ;
	}
	number_len = ft_strlen_s(output->number);
	if (number_len < input.precision)
	{
		output->number = add_zero(output->number, input.precision - number_len);
		if (!output->number)
		{
			output->status = ERROR;
			return ;
		}
	}
}

/* Make the 'padding' part, which is provived by field width(space or 0). */
void	set_padding(t_print *output, t_finfo input)
{
	int		number_len;
	int		sign_len;
	int		padding_len;

	if (input.width == EMPTY || input.width == 0)
		return ;
	number_len = ft_strlen_s(output->number);
	sign_len = ft_strlen_s(output->sign);
	padding_len = input.width - number_len - sign_len;
	if (0 < padding_len)
	{
		output->padding = calloc(padding_len + 1, sizeof(char));
		if (!output->padding)
		{
			output->status = ERROR;
			return ;
		}
		if (input.zero == true)
			ft_memset(output->padding, '0', padding_len);
		else
			ft_memset(output->padding, ' ', padding_len);
	}
}

/* Make the 'sign' part, which conteins signs(+, -, 0x, etc.). */
void	set_sign(t_print *output, t_finfo input)
{
	if (input.specifier == P || input.sharp == true)
	{
		if (input.specifier == XL)
			output->sign = ft_strdup("0X");
		else
			output->sign = ft_strdup("0x");
	}
	if (output->status == NEGATIVE)
		output->sign = ft_strdup("-");
	else if (output->status == POSITIVE)
	{
		if (input.plus == true)
			output->sign = ft_strdup("+");
		else if (input.space == true)
			output->sign = ft_strdup(" ");
	}
}

/* Make the 'number' part, which is actual numbers. */
void	set_number(unsigned long long value, int base,
			t_print *output, t_finfo input)
{
	output->number = malloc((sizeof (char) * 16 + 1));
	if (!output->number)
	{
		output->status = ERROR;
		return ;
	}
	ft_itoa_base(value, output->number, base);
	if (input.precision != EMPTY)
		apply_precision(value, output, input);
}
