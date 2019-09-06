/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:01:56 by algautie          #+#    #+#             */
/*   Updated: 2019/09/06 12:13:27 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../sources/libft/libft.h"

# define MAX_RANGE 2147483647

enum				e_flag
{
	NONE,
	H,
	HH,
	L,
	LL,
	BIG_L,
};

typedef struct		s_pf
{
	char			conversion;
	enum e_flag		flag;
	int				width;
	int				precision;
	int				len;
	size_t			i;
	size_t			conv_pos;
	va_list			args;
	const char		*format;
	char			*cpy;
	int				error;
	int				fd;
	int				preflag_plus;
	int				preflag_minus;
	int				preflag_hash;
	int				preflag_zero;
	int				preflag_space;
}					t_pf;

int					ft_printf(const char *format, ...);
t_pf				*init_struct(t_pf *pf, const char *format);
void				print_text(t_pf *pf);
void				get_stuff(t_pf *pf);
void				parse(t_pf *pf);
void				reinit_struct(t_pf *pf);
void				print_stuff(t_pf *pf);
void				conv_c(t_pf *pf);
void				conv_s(t_pf *pf);
void				conv_d(t_pf *pf);
void				conv_o(t_pf *pf);
void				conv_x(t_pf *pf);
void				conv_u(t_pf *pf);
void				conv_p(t_pf *pf);
void				conv_f(t_pf *pf);
void				conv_percent(t_pf *pf);
long long			round_nbr(t_pf *pf, char *str, long double nbr,\
					long long int_part);
char				*get_fractional_part(t_pf *pf, long double nbr);

#endif
