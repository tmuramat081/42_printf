/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:32:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/24 02:00:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

# define EMPTY -1

# define POSITIVE 0
# define NEGATIVE 1
# define ERROR 2

/* Support for cspdiuxX. */
typedef enum e_spec {
	NONE,
	C,
	S,
	DI,
	U,
	P,
	XS,
	XL,
	PER_CT,
	END
}	t_spec;

typedef struct s_finfo {
	bool	hyphen;
	bool	plus;
	bool	zero;
	bool	sharp;
	bool	space;
	int		width;
	int		precision;
	t_spec	specifier;
}	t_finfo;

/* For example ' -42',  1. number '42',  2. sign '-', 3. padding ' '  */
typedef struct s_print {
	char	*number;
	char	*sign;
	char	*padding;
	int		status;
}	t_print;

/**********ft_print.c**********/
int		ft_printf(const char *s, ...);
t_finfo	init_format_info(void);
int		input_format(const char *fmt, va_list *ap);
int		switch_conv_function(va_list *ap, t_finfo input);
/**********parcer.c**********/
int		input_format_info(const char *fmt, va_list *ap, t_finfo *input,
			 size_t *i);
void	parse_flags(const char *fmt, t_finfo *input, size_t *i);
void	parse_width(const char *fmt, t_finfo *input, va_list *ap, size_t *i);
void	parse_precision(const char *fmt, t_finfo *input, va_list *ap,
			size_t *i);
void	parse_specifier(const char *fmt, t_finfo *input, size_t *i);
/**********converter.c**********/
int		convert_into_character(va_list *ap, t_finfo input);
int		convert_into_string(va_list *ap, t_finfo input);
int		convert_into_decimal(va_list *ap, t_finfo input);
int		convert_into_address(va_list *ap, t_finfo input);
int		convert_into_hexadecimal(va_list *ap, t_finfo input);
/**********composer.c**********/
void	set_number(unsigned long long value, int base, t_print *output,
			t_finfo input);
void	set_sign(t_print *output, t_finfo input);
void	set_padding(t_print *output, t_finfo input);
void	apply_precision(unsigned long long value, t_print *output,
			t_finfo input);
char	*add_zero(char *src, size_t len);
/**********printer.c**********/
void	free_output(t_print *output);
int		setup_field(t_print *output, t_finfo input);
int		print_field(char *str1, char *str2, char *str3);
/**********utils**********/
char	*ft_itoa_base(unsigned long long value, char *buff, int base);
int		ft_putstr_cnt(char *str);
int		ft_putchar_cnt(int c);
void	str_toupper(char *str);
ssize_t	ft_strlen_s(const char *s);

#endif