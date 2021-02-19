%{
	#include <stdio.h>
%}
DIGIT [0-9]
%%
-{DIGIT}+	{printf("Entered digit is negative\n"); exit(0);}
\+?{DIGIT}+	{printf("Entered digit is positive\n"); exit(0);}
-{DIGIT}*\.{DIGIT}+	{printf("Entered digit is neg fraction\n");exit(0);}
\+?{DIGIT}*\.{DIGIT}+	{printf("Entered digit is pos fraction\n");exit(0);}
%%

