
/* Entry of ACTION part in LR parsing table	*/
typedef struct
{
	char action_type;
	int state;
}action_entry;

int stack[100],top=-1;
char ibuffer[100];
char grammar[3][6]={"S->CC","C->cC","C->d"};

int indexof(char c, char t[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		if(t[i] == c)
		return i;
	}
	return -1;
}

void main()
{
	/*	ACTION part of LR parsing table		*/
	action_entry action_part[7][3]={{{'s',3},{'s',4},{'\0',-1}},
				    {{'\0',-1},{'\0',-1},{'a',-2}},
				    {{'s',3},{'s',4},{'\0',-1}},
				    {{'s',3},{'s',4},{'\0',-1}},
				    {{'r',3},{'r',3},{'r',3}},
				    {{'\0',-1},{'\0',-1},{'r',1}},
				    {{'r',2},{'r',2},{'r',2}}};

	/*	GOTO part of LR parsing table		*/
	int goto_part[7][2]={{1,2},
				 {-1,-1},
				 {-1,5},
				 {-1,6},
				 {-1,-1},
				 {-1,-1},
				 {-1,-1}} ;


	action_entry ptentry;
	int tos,ip=0,count,cindex,state;
	char cur_symbol;
	char terminals[10]="cd$";
	char nonterminals[10]="SC";
	char production[10];

	printf("Enter the input string::\n");
	gets(ibuffer);

	/* Set initial configuration for LR Parser */
	strcat(ibuffer,"$");
	stack[++top] = 0;


	/* LR Parsing Program	*/
	while(1)
	{
		/* Get the top of stack	*/
		tos = stack[top];

		/* Get the current input symbol	*/
		cur_symbol = ibuffer[ip];

		cindex = indexof(cur_symbol,terminals,strlen(terminals));

		/*Consult action part of parsing table for this state and current input symbol	*/
		ptentry = action_part[tos][cindex];

		/*Handling shift action	*/
		if(ptentry.action_type == 's')
		{
			/* push input symbol into stack */
			stack[++top] = cur_symbol;

			/* push state into stack */
			stack[++top] = ptentry.state;

			/* Increment the input pointer	*/
			ip++;
		}

		/* Handling reduce action */
		else if(ptentry.action_type == 'r')
		{
			strcpy(production,grammar[ptentry.state-1]);
			count = strlen(production)-3;

			/* pop the handle */
			while(count > 0 )
			{
				top--;
				top--;
				count--;
			}

			/*Push the Non terminal */
			stack[++top] = production[0];

			cindex = indexof(production[0],nonterminals,strlen(nonterminals));
			/*Push the state covering the non terminal */
			state = goto_part[stack[top-1]][cindex];
			stack[++top] = state;
		}


		/* Accept action	*/
		else if(ptentry.action_type == 'a')
		{
			printf("The stream of tokens %s is syntactically valid::\n");
			exit(0);
		}

		/* Error action	*/
		else
		{
			printf("There is a syntactical error in the token stream %s::\n");
			exit(-1);
		}
	}
}
