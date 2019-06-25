#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../sources/libft/libft.h"

typedef struct		s_pf
{
	char			conversion;
	int				flags;
	int				width;
	int				precision;
	int				len;
	size_t			i;
	size_t			conv_pos;
	va_list			args;
	const char		*format;
	char			*cpy;
	int				fd;
}					t_pf;

# define F_PLUS 1
# define F_MINUS 2
# define F_HASH 4
# define F_ZERO 8

t_pf				*init_struct(t_pf *pf, const char *format);
void				print_text(t_pf *pf);

#endif
