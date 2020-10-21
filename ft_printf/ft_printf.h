#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEBUG 1

# include <unistd.h>
# include <stdarg.h>

# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_SPACE	4
# define FLAG_OCTO	8
# define FLAG_ZERO	16

typedef struct {
	short int	flags;
	short int	is_width;
	int			width;
	short int	is_precision;
	int			precision;
	int			length;
	char		specifier;
	char		character;
}				t_s_data;

int				ft_printf(const char *format, ...);

#endif