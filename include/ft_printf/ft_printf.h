/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssenas-y <ssenas-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:24:38 by ssenas-y          #+#    #+#             */
/*   Updated: 2023/10/23 14:22:17 by ssenas-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <errno.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putph(va_list args, char c, int *check);
int	ft_putptr_s(void *ptr, int *check);
int	ft_putnbr_uns(unsigned int nbr, int *check);
int	ft_puthex_ls(unsigned int nbr, int *check);
int	ft_puthex_ptr(unsigned long long nbr, int *check);
int	ft_puthex_ups(unsigned int nbr, int *check);
int	ft_putstr_s(char *str, int *check);
int	ft_putchar_s(char c, int *check);
int	ft_putnbr_s(long nbr, int *check);

#endif
