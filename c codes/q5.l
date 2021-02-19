%{
	#include <stdio.h>
%}
START \/\*
END \*\/
%%
\/\/(.*)	{/*Do nothing if you encounter a comment line*/}
{START}.*{END}	{/* start pattern and end pattern may have many chars in between*/}
%%
int main()
{
	yyin=fopen("inp.c","r");
	yyout=fopen("out.c","w");
	yylex();
	printf("Program ended");
}
