#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "transistors.h"

void DisplayTransistor(Tran tran)
{
    printf("Number: %s\n", tran.number);
    switch(tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;

    case PNP:
        printf("Type: PNP\n");
        break;
    }

    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);

    printf("\n");
}

void InputString(char *str, int max)
{
	char buffer[100];

	printf("%s","Input String Name: ");

	/* Get a line of up to 100 characters */
	fgets(buffer,sizeof(buffer),stdin);

	while(buffer[0] == '\n')
		fgets(buffer,sizeof(buffer),stdin);
	
	/* Remove any \n we may have input */
	if(strlen(buffer) > 0)
		buffer[strlen(buffer) - 1] = 0;

	/* Copy up to max characters to our string */
	strncpy(str,buffer,max);
	str[max - 1] = 0;
}

double InputPositiveValue(char *prompt)
{
	char buffer[100];
	double value = 0;

	do
	{
		printf("%s",prompt);

		fgets(buffer,sizeof(buffer),stdin);

		if(strlen(buffer) > 0)
			buffer[strlen(buffer) - 1] = 0;

		sscanf(buffer,"%lf",&value);

	}while(value<=0);

	return value;
}

int InputTransistorType(char *prompt)
{
	char buffer[100];

	do
	{
		printf("%s",prompt);

		fgets(buffer,sizeof(buffer),stdin);

		if(strlen(buffer) > 0)
			buffer[strlen(buffer) - 1] = 0;

		if(strcmp(buffer,"NPN") == 0)
			return NPN;
		else if(strcmp(buffer,"PNP") == 0)
			return PNP;

	}while(true);
}

int InputTransistorCaseType(char *prompt)
{
	char buffer[100];

	do
	{
		printf("%s",prompt);

		fgets(buffer,sizeof(buffer),stdin);

		if(strlen(buffer) > 0)
			buffer[strlen(buffer) -1] = 0;

		if(strcmp(buffer,"TO18") == 0)
			return TO18;
		if(strcmp(buffer,"TO92A") == 0)
			return TO92A;
		if(strcmp(buffer,"TO92C") == 0)
			return TO92C;
		if(strcmp(buffer,"TO220") == 0)
			return TO220;
		if(strcmp(buffer,"TO39") == 0)
			return TO39;
		
	}while(true);
}


Tran InputTransistor()
{
	Tran t1;

	InputString(t1.number,sizeof(t1.number));
	t1.type = InputTransistorType("Input type: ");
    	t1.caseStyle = InputTransistorCaseType("Input Case Style: ");
	t1.pmax = InputPositiveValue("Input pMax: ");
	t1.icmax = InputPositiveValue("Input icMax: ");
	printf("\n");
	return t1;
}
