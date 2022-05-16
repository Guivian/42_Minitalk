/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:19:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/12 20:46:25 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printf_iteri(const char *format, va_list *args, int counter, int i);
int	ft_printf_formatspecifier(const char *format, va_list *args, int i);
int	ft_printf_c(char c);
int	ft_printf_s(char *s);
int	ft_printf_p(unsigned long int p);
int	ft_printf_di(int di);
int	ft_printf_u(unsigned int u);
int	ft_printf_x(unsigned int x);
int	ft_printf_mx(unsigned int mx);

#endif
