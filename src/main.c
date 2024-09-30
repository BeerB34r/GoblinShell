#include "function_definitions.h"
#include "data_definitions.h"
#include "constants.h"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	// TODO insert rudimentary environment initialisation
	// TODO insert gobshrc execution somewhere

	ft_putstr("You have begun a GoblinShell session\n");
	gobsh_interactive();
	ft_putstr("You have ended a GoblinShell session\n");
}

void	gobsh_prompt()
{
	// TODO change this to use the environment or gobshrc
	ft_putstr("Milord? ");
}

int	gobsh_interactive()
{
	t_token *input;

	while (1)
	{
		gobsh_prompt();
		input = gobsh_userinput(0);
		gobsh_displaytokens(input);
	}
	return (0);
}

// mode 0 == user input, 1 == file input
// TODO make this use environment to determine specific types of tokens
t_token	*gobsh_userinput(int mode)
{
	t_token	*head;
	t_token	*current;
	char	c;
	int		status;
	int		delim;

	head = gobsh_newtoken(NULL);
	current = head;
	status = 1;
	while (status > 0)
	{
		status = read(0, &c, 1);
		delim = gobsh_delimittoken(c, current); // TODO add proper delimiting condition & function (WIP)
		if (delim)
		{
			if (mode == 0 && c == '\n')
				break ;
			if (delim != 3)
				current = current->next;
			continue ;
		}
		current->literal = ft_acatchar(current->literal, c);
		if (mode == 0 && c == '\n')
			break ;
	}
	return (head);
}

t_token	*gobsh_newtoken(t_token *current)
{
	t_token *out;

	out = (t_token *)malloc(sizeof(t_token));
	out->type = Rudimentary;
	out->literal = NULL;
	if (current)
		current->next = out;
	return (out);
}

int	gobsh_delimittoken(char c, t_token *current)
{
	char	str[4] = {0};

	str[0] = c;
	// operator handling
	if (current->type == Operator)
	{
		if (gobsh_ispartialoperator(current->literal, c)) 
			return (0);
		else
		{
			current = gobsh_newtoken(current);
			current->literal = ft_acatchar(current->literal, c);
			return (1);
		}
	}
	// new operator delimit
	if (ft_strscontain(str, Operators) != -1)
	{
		if (!current->literal)
		{
			current->type = Operator;
			return (0);
		}
		current = gobsh_newtoken(current);
		current->type = Operator;
		current->literal = ft_acatchar(current->literal, c);
		return (2);
	}
	// TODO finish comment handler
	if (c == '#')
	{
		current = gobsh_newtoken(current);
		//consume the rest of the line, unless EOF comes before EOL, give newline to current token
	}
	// TODO make BLANK delimit handle quotation (IE, handle quotation)
	if (ft_strcontain(BLANK, c) != -1)
	{
		if (!current->literal)
			return (3);
		current = gobsh_newtoken(current);
		return(2);
	}
	return (0);
}

void	gobsh_tokentypechecker(t_token *current)
{
	if (ft_strscontain(current->literal, Reserved_words) != -1)
		current->type = ReservedWord;
	else if (ft_strscontain(current->literal, Special_Built_ins) != -1)
		current->type = Special_built_in;
	else if (ft_strscontain(current->literal, Operators) != -1)
		current->type = Operator;
	else
		current->type = Word;
}

int		gobsh_ispartialoperator(const char *str, char c)
{
	char	partial[4];
	int		i;

	i = ft_strcpy(str, partial);
	if (i == 3)
		return (0);
	partial[i++] = c;
	partial[i] = 0;
	return (ft_strscontain(partial, Operators) != -1);
}

void	gobsh_displaytokens(t_token *head)
{
	t_token	*current;

	current = head;
	while (current)
	{
		ft_putstr("[\"");
		ft_putstr(Token_types[current->type]);
		ft_putstr("\",\"");
		ft_putstr(current->literal);
		ft_putstr("\"]\n");
		current = current->next;
	}
}
