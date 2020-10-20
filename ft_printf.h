/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:18:17 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/20 13:02:25 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "srcs/lib/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
	int	num;
	int	point;
	int	has_precission;
	size_t	precission;
	int	has_width;
	size_t	width;
}	t_flags;
int	ft_is_flag(char *str);
int	ft_print_str(va_list args, int writed, t_flags **flags);
const char	*ft_check_num(const char *str, t_flags *flags);
const char	*ft_check_sym(const char *str,va_list args, t_flags *flags);
char	*ft_spaces(char *string, t_flags *flags);
char	*ft_spaces_str(char *string, t_flags *flags);
void	ft_putmui_fd(unsigned int n, int fd);
char	*ft_precision(char *string, t_flags *flags);
char	*ft_precision_str(char *string, t_flags *flags);
void	ft_spacer(void *str, int n);
void	ft_spacerc(void *str, int n);
char	*ft_spacerz(char *str, int n, t_flags *flags);
char	*ft_spacerz_str(char *str, int n, t_flags *flags);
int	ft_print_int(va_list args, int writed, t_flags **flags);
int 	ft_print_unsigned_int(va_list args, int writed, t_flags **flags);
int	ft_print_char(va_list args, int writed, t_flags **flags);
int	ft_print_pointer(va_list args, int writed, t_flags **flags);
int	ft_print_simbol(const char *str, int writed, t_flags **flags);
int	ft_print_hex(const char *str, va_list args, int writed, t_flags **flags);
int	ft_minus(char c, char *str, int writed, t_flags *flags);
char	*ft_ul_to_hex(unsigned long n);
char	*ft_ui_to_hex(unsigned int n);
char	*ft_str_up(char *str);
char	*ft_str_dup(const char *s1);
char	*ft_strjoin_free(char *str1, char *str2, int i);

#endif
