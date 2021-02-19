#define MAX 30

char ipstring[MAX]={'\0'},ipsym;
int ip=0,save;

void S();
void A();
void ERROR();
void ADVANCE();

void S()
{
	if(ipsym == 'c')
	{
		ADVANCE();
		A();
		if(ipsym == 'd')
		{
			ADVANCE();
		}
		else
		{
			ERROR();
		}
	}
	else
	{
		ERROR();
	}
}

void A()
{
	save = ip;
	if(ipsym == 'a')
	{
		ADVANCE();
		if(ipsym == 'b')
		{
			ADVANCE();
			return;
		}
	}

	ip = save;
	ipsym = ipstring[ip];
	if(ipsym == 'a')
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
	S();
	if(ipsym=='\0')
	printf("The given string %s is syntactically valid::\n",ipstring);
	else
	printf("The given string %s is syntactically not valid::\n",ipstring);
	getch();
}
