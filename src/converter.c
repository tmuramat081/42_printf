/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:41:42 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 23:30:14 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	convert_into_char_and_print(va_list *ap, t_finfo input)
{
	unsigned char	input_c;
	size_t			padding_len;
	int				ret_len;

	input_c = (unsigned char)va_arg(*ap, int);
	if (1 < input.width)
		padding_len = input.width - 1;
	else
		padding_len = 0;
	ret_len = 0;
	if (input.hyphen)
	{
		ret_len += ft_putchar_cnt(input_c);
		while (padding_len--)
			ret_len += ft_putchar_cnt(' ');
	}
	else
	{
		while (padding_len--)
			ret_len += ft_putchar_cnt(' ');
		ret_len += ft_putchar_cnt(input_c);
	}
	return (ret_len);
}

int	convert_into_string(va_list *ap, t_finfo input)
{
	t_print	output;
	char	*input_str;

	ft_memset(&output, 0, sizeof(t_print));
	input_str = va_arg(*ap, char *);
	if (!input_str)
		output.number = ft_strdup ("(null)");
	else
		output.number = ft_strdup(input_str);
	if (input.precision != EMPTY
		&& input.precision < ft_strlen_s(output.number))
		output.number[input.precision] = '\0';
	set_padding(&output, input);
	return (setup_field(&output, input));
}

int	convert_into_decimal(va_list *ap, t_finfo input)
{
	t_print				output;
	unsigned long long	value;

	ft_memset(&output, 0, sizeof(t_print));
	if (input.specifier == U)
		value = va_arg(*ap, unsigned int);
	else
	{
		value = va_arg(*ap, int);
		if (0 > (signed long long)value)
			output.status = NEGATIVE;
	}
	set_number(value, 10, &output, input);
	set_sign(&output, input);
	set_padding(&output, input);
	return (setup_field(&output, input));
}

int	convert_into_address(va_list *ap, t_finfo input)
{
	t_print		output;
	uintptr_t	value;

	ft_memset(&output, 0, sizeof(t_print));
	value = va_arg(*ap, uintptr_t);
	if (!value)
		output.number = ft_strdup("0x0");
	else
	{
		set_number(value, 16, &output, input);
		set_sign(&output, input);
	}
	set_padding(&output, input);
	return (setup_field(&output, input));
}

int	convert_into_hexadecimal(va_list *ap, t_finfo input)
{
	t_print				output;
	unsigned long long	value;

	ft_memset(&output, 0, sizeof(t_print));
	value = va_arg(*ap, unsigned int);
	set_number(value, 16, &output, input);
	if (input.specifier == XL)
		str_toupper(output.number);
	if (value)
		set_sign(&output, input);
	set_padding(&output, input);
	return (setup_field(&output, input));
}
