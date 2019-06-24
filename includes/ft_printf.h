#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../sources/libft/libft.h"

typedef struct		s_pf
{
	char			conversion;
	char			flag[2];
	int				field_width;
	int				precision;
	int				len;
	size_t			i;
	size_t			conv_pos;
	va_list			args;
	const char		*format;
	char			*cpy;
	int				fd;
}					t_pf;

t_pf				*init_struct(t_pf *pf, const char *format);
void				print_text(t_pf *pf);

#endif
