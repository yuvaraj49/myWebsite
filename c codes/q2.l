%{
	#include <stdio.h>
	int chars=0;
	int spaces=0;
	int words=0;
%}
%%
\n		{words++;}
[\t ' ']	{spaces++;words++;}
[a-zA-Z0-9]	{chars++;}
%%
int main()
{	
	yyin=fopen("data.txt","r");
	yylex();
	printf("spaces : %d\n",spaces);
	printf("words : %d\n",words);
	printf("chars : %d\n",chars);
	return 0;
}
