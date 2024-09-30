#ifndef DATA_DEFINITIONS_H
# define DATA_DEFINITIONS_H

#include <stddef.h>

typedef enum	e_token_type
{
	Rudimentary,
	Token,
	Word,
	ReservedWord,
	Special_built_in,
	Operator,
	IO_number,
	IO_location,
	Name,
	Assignment_name,
}	t_token_type; // Many tokens are omitted from this enum due to their specificity. This may change

typedef struct	s_token
{
	t_token_type	type;
	char	*literal;
	struct s_token	*next;
}	t_token;

typedef struct	s_dict
{
	char	*key;
	int		val;
	struct s_dict	*next;
}	t_dict;
#endif
