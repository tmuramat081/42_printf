/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:41:29 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/22 22:41:29 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	switch_conv_function(va_list *ap, t_finfo input)
{
	int	ret_len;
	int	(*convert_func[END])(va_list*, t_finfo);

	convert_func[C] = convert_into_character;
	convert_func[S] = convert_into_string;
	convert_func[DI] = convert_into_decimal;
	convert_func[U] = convert_into_decimal;
	convert_func[P] = convert_into_address;
	convert_func[XS] = convert_into_hexadecimal;
	convert_func[XL] = convert_into_hexadecimal;
	if (input.specifier == NONE)
		return (0);
	else if (input.specifier == PER_CT)
		ret_len = ft_putchar_cnt('%');
	else
		ret_len = convert_func[input.specifier](ap, input);
	return (ret_len);
}

/*If the syntax is wrong, print it as a character string. */
int	input_format_info(const char *fmt, va_list *ap, t_finfo *input, size_t *i)
{
	int		tmp_i;
	char	*str_err;
	int		ret_len;

	tmp_i = *i - 1;
	ret_len = 0;
	parse_flags(fmt, input, i);
	parse_width(fmt, input, ap, i);
	parse_precision(fmt, input, ap, i);
	parse_specifier(fmt, input, i);
	if (input->specifier == NONE)
	{
		str_err = ft_substr(fmt, tmp_i, *i - tmp_i + 1);
		ret_len = ft_putstr_cnt(str_err);
		free(str_err);
	}
	return (ret_len);
}

/* Initialize the valiables (all flags, field width, precision, specifier). */
t_finfo	init_format_info(void)
{
	t_finfo	input;

	ft_memset(&input, 0, sizeof(t_finfo));
	input.width = EMPTY;
	input.precision = EMPTY;
	return (input);
}

int	input_format(const char *fmt, va_list *ap)
{
	size_t	i;
	int		ret_len;
	t_finfo	input;

	i = 0;
	ret_len = 0;
	while (fmt[i] != '\0')
	{
		input = init_format_info();
		if (fmt[i] != '%')
			ret_len += ft_putchar_cnt(fmt[i]);
		else
		{
			i += 1;
			if (fmt[i] == '\0')
				return (ret_len);
			ret_len += input_format_info(fmt, ap, &input, &i);
			ret_len += switch_conv_function(ap, input);
		}
		i++;
	}
	return (ret_len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret_len;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	ret_len = input_format(fmt, &ap);
	va_end (ap);
	return (ret_len);
}
