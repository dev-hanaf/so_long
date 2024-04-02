/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 02:30:08 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# define NC "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

# define FLAGS "diucspxX%"

typedef struct s_val
{
	char		*prs;
	int			plus;
	int			minus;
	int			zero;
	int			number;
	int			space;
	int			hash;
	int			precision;
	int			width;
	int			after_width;
	int			start_index;
	int			end_index;
}				t_val;

typedef struct s_format_args
{
	char		f;
	int			*count;
	int			index;
	const char	*str;
}				t_format_args;

void			ft_format(va_list ap, char f, t_format_args *args);
int				ft_check_flags(char f);
void			ft_reset_t_val(t_val *flag);
t_val			ft_bonus(char f, int mode);
int				ft_mandatory_flags(char f);
void			ft_my_while(va_list ap, int *i, const char *str,
					t_format_args *args);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
size_t			ft_strlen_printf(const char *str);
int				ft_putnbr(int num);
int				ft_putnbr_u(unsigned int n);
int				ft_putstr(char *s);
void			ft_putaddresse_helper(unsigned long long num, int *count);
int				ft_putaddresse(unsigned long long num);
int				ft_puthexa(unsigned int num, char f);
int				count_val_flags(t_val *flag);
char			*ft_parser(const char *str, int start, int end);
int				counter_number(int num);
int				counter_number_u(unsigned int num);
int				counter_number_x(unsigned int num, t_val *flag);
int				counter_number_p(unsigned long long num);
int				ft_minus(int num, int width);
int				ft_minus_u(unsigned int num, int width);
int				ft_minus_s(char *arg, int width);
int				ft_minus_x(unsigned int num, int width, t_val *flag);
int				ft_minus_xx(unsigned int num, int width, t_val *flag);
int				ft_minus_p(unsigned long long num, int width);
int				ft_width(char *prs);
int				ft_get_precision(char *prs);
int				ft_precision(int num, t_val *flag);
int				ft_precision_u(unsigned int num, t_val *flag);
int				ft_precision_x(unsigned int num, t_val *flag);
int				ft_precision_xx(unsigned int num, t_val *flag);
int				ft_precision_s(char *arg, int precision, int width);
int				ft_precision_p(unsigned long long num, t_val *flag);
int				ft_precision_of_minus(int num, t_val *flag);
int				ft_precision_of_minus_u(unsigned int num, t_val *flag);
int				ft_precision_of_minus_x(unsigned int num, t_val *flag);
int				ft_precision_of_minus_xx(unsigned int num, t_val *flag);
int				ft_precision_of_minus_s(char *arg, int precision, int width);
int				ft_precision_of_minus_p(unsigned long long num, t_val *flag);
int				ft_zero(int num, int width);
int				ft_zero_u(unsigned int num, int width);
int				ft_zero_x(unsigned int num, int width, t_val *flag);
int				ft_zero_xx(unsigned int num, int width, t_val *flag);
int				ft_zero_p(unsigned long long num, int width);
int				rond_point(t_val *flag, const char *str, int num);
int				rond_point_c(t_val *flag, const char *str, char c);
int				rond_point_u(t_val *flag, const char *str, unsigned int num);
int				rond_point_x(t_val *flag, const char *str, unsigned int num);
int				rond_point_xx(t_val *flag, const char *str, unsigned int num);
int				rond_point_s(t_val *flag, const char *str, char *arg);
int				rond_point_p(t_val *flag, const char *str,
					unsigned long long num);
int				rond_point_precentage(t_val *flag, const char *str, char c);
void			handle_width_precentage(char c, int is_zero, t_val *flag,
					int *count);
void			first_condition_part_precentage(char c, int is_zero,
					t_val *flag, int *count);
void			handle_width_c(char c, int is_zero, t_val *flag, int *count);
void			first_condition_part_c(char c, int is_zero, t_val *flag,
					int *count);
int				add_spaces(int num, int width);
void			ft_print_plus(int num, int *count, t_val *flag);
void			ft_print_plus_minus(int num, int *count, t_val *flag);
void			ft_print_space(int num, int *count, t_val *flag);
int				check_zero_is_flag(char *prs);
int				add_spaces_u(unsigned int num, int width);
void			ft_print_plus_u(unsigned int num, int *count, t_val *flag);
void			ft_print_plus_minus_u(int *count, t_val *flag);
void			ft_print_space_u(int *count, t_val *flag);
int				add_spaces_x(unsigned int num, int width, t_val *flag);
void			ft_print_plus_x(unsigned int num, int *count, t_val *flag);
void			ft_print_plus_minus_x(int *count, t_val *flag);
void			ft_print_space_x(int *count, t_val *flag);
int				add_spaces_xx(unsigned int num, int width, t_val *flag);
void			ft_print_plus_X(unsigned int num, int *count, t_val *flag);
void			ft_print_plus_minus_xx(int *count, t_val *flag);
void			ft_print_space_xx(int *count, t_val *flag);
int				add_spaces_s(char *arg, int width);
int				check_zero_is_flag_s(char *prs);
void			ft_print_plus_p(unsigned long long num, int *count,
					t_val *flag);
void			ft_print_plus_minus_p(int *count, t_val *flag);
void			ft_print_space_p(int *count, t_val *flag);
int				add_spaces_p(unsigned long long num, int width);

#endif