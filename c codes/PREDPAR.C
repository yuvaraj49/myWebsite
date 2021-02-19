char stck[20],ibuff[30];
int top=-1,ip=0;

void printLine()
{
	int i=0;
	printf("\n\t\t");
	for(i=0;i<40;i++)
	printf("-");
	printf("\n");
}
void printStack()
{
	int i=0;
	printf("\n\t\t");
	for(i=0;i<=top;i++)
	{
		printf("%c",stck[i]);
	}
	printf("\t\t");
}

void printInputBuffer()
{
	int i=0;
	for(i=0;i<ip;i++)
	printf(" ");
	for(i=ip;i<strlen(ibuff);i++)
	{
		printf("%c",ibuff[i]);
	}
	printf("\t\t");
}

void printOutput(char P[])
{
	printf("%s",P);
}

int getIndex(char arr[],char c)
{
	int i=0;
	while(i<strlen(arr))
	{
		if(arr[i]==c)
		return i;
		i++;
	}
	return -1;
}

void main()
{
	char NT[5]="EATBF";
	char T[6]="i+*()$";
	char P[8][10]={"E->TA",
		       "A->+TA",
		       "A->e",
		       "T->FB",
		       "B->*FB",
		       "B->e",
		       "F->(E)",
		       "F->i"};

	char PT[5][6]={{0,-1,-1,0,-1,-1},
		       {-1,1,-1,-1,2,2},
		       {3,-1,-1,3,-1,-1},
		       {-1,5,4,-1,5,5},
		       {7,-1,-1,6,-1,-1}};
	int ptentry,i;
	clrscr();
	stck[++top]='$';
	stck[++top]='E';
	printf("Enter the string to be parsed:(Type $ at the end)\n");
	gets(ibuff);
	ip=0;
	printLine();
	printf("\t\t\tTHE GIVEN GRAMMAR\n");
	printLine();
	for(i=0;i<8;i++)
	printf("\t\t%s\n",P[i]);
	printf("\n");
	printf("\n");
	printf("\t\tMoves of the Parser are:\n");
	printLine();
	printf("\t\tSTACK\t\tINPUT\t\tOUTPUT\n");
	printLine();
	printStack();
	printInputBuffer();

	while(1)
	{
		if(stck[top]== '$' && ibuff[ip]=='$')
		{
			printf("\n\n\t\tGiven string is syntactically valid::\n");
			exit(0);
		}

		else if(stck[top]==ibuff[ip])
		{
			top--;
			ip++;
			printStack();
			printInputBuffer();
		}

		else if(stck[top] >= 'A' && stck[top]<= 'Z')
		{
			ptentry = PT[getIndex(NT,stck[top])][getIndex(T,ibuff[ip])];
			if(ptentry==-1)
			{
				printStack();
				printInputBuffer();
				printOutput("ERROR");
				printf("\n\n\t\tGiven string is syntactically invalid:\n");
				exit(0);
			}

			else
			{
				top--;
				for(i=strlen(P[ptentry])-1;i>=3;i--)
				{
					if(P[ptentry][i]!='e')
					{
						stck[++top]=P[ptentry][i];
					}
				}
				printStack();
				printInputBuffer();
				printOutput(P[ptentry]);
			}
		}
		else
		{
			printf("\n\n\t\tGiven string is syntactically invalid:\n");
			exit(-1);
		}
	}
}