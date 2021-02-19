%{
	#include <stdio.h>
	int op=0,id=0,flag=0;
	int vars=0;
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
{LETTER}({LETTER}|{DIGIT})*	{printf("\nIdentifier = ");id++; ECHO;}
[+|-|*|/|=]	{printf("\nOperator = ");op++; ECHO;}
"("	{vars++;}
")"	{vars--;}
";"	{flag=1;}
%%
int main()
{
	printf("Enter an expression : ");
	yylex();
	if((op+1)==id && vars==0 && flag==0)
	{
		printf("Valid expression");
	}
	else
	{
		printf("Invalid");
	}
	return 0;
}
