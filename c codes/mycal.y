%{
	#include <stdio.h>
	int flag=0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')' 
%%
AE : E {printf("Value = %d\n",$$);};
E : E'+'E	{$$=$1+$3;}
  | E'-'E	{$$=$1-$3;}
  | E'*'E	{$$=$1*$3;}
  | E'/'E	{$$=$1/$3;}
  | E'%'E	{$$=$1%$3;}
  | '('E')'	{$$=$2;}
  | NUMBER 	{$$=$1;};

%%
int main()
{
	printf("Enter data : ");
	yyparse();
	if(flag==0)
	{
		printf("Expression valid\n");
	}
}
void yyerror()
{
	printf("Invalid exprn");
	flag=1;
}
