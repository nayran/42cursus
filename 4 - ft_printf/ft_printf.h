/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:07:12 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/19 16:39:30 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#	include <stdio.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdarg.h>
#	include <limits.h>

#	define CASOS		"cspdiuxX%"
#	define FLAGS		"0123456789-.*"
#	define NUMEROS		"0123456789"
#	define LOWER_BASE	"0123456789abcdef"
#	define UPPER_BASE	"0123456789ABCDEF"

typedef struct	s_flags
{
	int	menos;
	int	comprimento;
	int	bool_ponto;
	int	ponto;
	int	zero;
	int	tipo;
	int	bool_intmin;
}				t_flags;

int				ft_printf(const char *s, ...);

int				ft_trata_casos(char c, va_list args, t_flags flags);
int				ft_caso_c(char c, t_flags flags);
int				ft_caso_s(char *s, t_flags flags);
int				ft_caso_d(int d, t_flags flags);
int				ft_caso_x(int x, t_flags flags, char caso);
int				ft_caso_p(unsigned long int p, t_flags flags);
int				ft_caso_u(int u, t_flags flags);
int				ft_caso_pct(t_flags flags);

t_flags			ft_start_struct(void);
t_flags			ft_trata_flags(const char *s, va_list args, t_flags flags);
t_flags			ft_trata_comprimento(va_list args, t_flags flags);
int				ft_flags_compr(t_flags flags, size_t len, int n);

void			ft_putchar(char c);
int				ft_putstr(char *s, t_flags fl);
int				ft_putstr_spec(char *s, t_flags flags, int d);
int				ft_putstr_spec_x(char *s, t_flags flags);
int				ft_putstr_spec_u(char *s, t_flags flags);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_uitoa_base(uintmax_t u, const char *base);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *string);

#	endif
