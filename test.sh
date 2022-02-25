#!/bin/bash
gcc -w -fsanitize=address test.c libftprintf.a -I./include -D FT_PRINTF -o ft_printf.out
gcc -w test.c libftprintf.a -I./include -D PRINTF -o printf.out
./ft_printf.out > A
./printf.out > B
colordiff --text -y A B
rm A B ./ft_printf.out ./printf.out
make clean