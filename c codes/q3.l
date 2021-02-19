%{
	#include <stdio.h>
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
{LETTER}({LETTER}|{DIGIT})*	{printf("Variable valid");}
.				printf("Variable invalid");
%%
