/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:01:56 by algautie          #+#    #+#             */
/*   Updated: 2019/06/26 10:43:43 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../sources/libft/libft.h"

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
	int				fd;
	int				flag_plus;
	int				flag_minus;
	int				flag_hash;
	int				flag_zero;
}					t_pf;

# define F_PLUS 1
# define F_MINUS 2
# define F_HASH 4
# define F_ZERO 8

# define MAX_RANGE 2147483647

t_pf				*init_struct(t_pf *pf, const char *format);
void				print_text(t_pf *pf);
void				get_stuff(t_pf *pf);
void				parse(t_pf *pf);

#endif
