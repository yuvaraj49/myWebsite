#define MAX 30

char ipstring[MAX]={'\0'},ipsym;
int ip=0;

void E();
void EPRIME();
void T();
void TPRIME();
void F();
void ERROR();
void ADVANCE();

void E()
{
	T();
	EPRIME();
}

void EPRIME()
{
	if(ipsym == '+')
	{
		ADVANCE();
		T();
		EPRIME();
	}
}

void T()
{
	F();
	TPRIME();
}

void TPRIME()
{
	if(ipsym == '*')
	{
		ADVANCE();
		F();
		TPRIME();
	}
}

void F()
{
	if(ipsym == '(')
	{
		ADVANCE();
		E();

		if(ipsym == ')')
		{
			ADVANCE();
		}

		else
		{
			ERROR();
		}
	}

	else if(ipsym == 'i')
	{
		ADVANCE();
	}

	else
	{
		ERROR();
	}
}

void ADVANCE()
{
	ip++;
	ipsym=ipstring[ip];
}

void ERROR()
{
	printf("The given string %s is syntactically not valid::\n",ipstring);
	getch();
	exit(-1);
}
void main()
{
	clrscr();
	printf("Enter the input string::\n");
	gets(ipstring);
	ipsym=ipstring[0];
	E();
	if(ipsym=='\0')
	printf("The given string %s is syntactically valid::\n",ipstring);
	else
	printf("The given string %s is syntactically not valid::\n",ipstring);
	getch();
}
