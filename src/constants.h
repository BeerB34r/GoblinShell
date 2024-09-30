#ifndef CONSTANTS_H
# define CONSTANTS_H

#define BLANK " \t"

const char  *Reserved_words[] = { "!",
                                "{",
                                "}",
                                "case",
                                "do",
                                "done",
                                "elif",
                                "else",
                                "esac",
                                "fi",
                                "for",
                                "if",
                                "in",
                                "then",
                                "until",
                                "while",
                                "time",
                                NULL };
// "time" is fucking weird, don't think too hard about it

const char	*Special_Built_ins[] = {	"break",
										"colon",
										"continue",
										"dot",
										"eval",
										"exec",
										"exit",
										"export",
										"readonly",
										"return",
										"set",
										"shift",
										"times",
										"trap",
										"unset",
										NULL };

const char	*Operators[] = {	"&", //start of control operators
								"&&",
								"(",
								")",
								";",
								";;",
								";&",
								"\n", //newline token spotted!
								"|",
								"||", //end of control operators
								"<", //start of redirection operators
								">",
								">|",
								"<<",
								">>",
								"<&",
								">&",
								"<<-",
								"<>", //end of redirection operators
								NULL };


const char	*Token_types[] = {	"Rudimentary",
								"Token",
								"Word",
								"ReservedWord",
								"Special Built-in",
								"Operator",
								"IO number",
								"IO location",
								"Name",
								"Assignment name",
								"Newline",
								NULL };

#endif
