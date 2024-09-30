#ifndef FUNCTION_DEFINITIONS_H
# define FUNCTION_DEFINITIONS_H

#include "data_definitions.h"

// Gobsh core functions
void	gobsh_prompt();
int		gobsh_interactive();
t_token	*gobsh_userinput();
t_token	*gobsh_newtoken(t_token *current);
void	gobsh_displaytokens(t_token *head);
void	gobsh_tokentypechecker(t_token *current);
int		gobsh_delimittoken(char c, t_token *current);
int		gobsh_ispartialoperator(const char *str, char c);

// String functions (yes ik im reinventing the wheel, shoot me)
void	ft_putstr(const char *str);
char	*ft_readline(void);
char	*ft_acatchar(char *src, char c);
int		ft_strlen(char *str);
int		ft_strcmp(const char *a, const char *b);
int		ft_strscontain(const char *needle, const char **haystack);
int		ft_strcontain(const char *str, char c);
int		ft_strcpy(const char *src, char *dest);

#endif
