#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  < zzq >
 * Description : Simple transistor description example program
*/



int main()
{

	Tran *trans;

	int question;

	int numTrans = 0;

	printf("transistors!\n");
    
	/* Allocate space for one transistor*/
	trans = malloc(sizeof(Tran));
	numTrans = 1;

	/* Input the transistors */
	do
	{
		trans[numTrans - 1] = InputTransistor();
		printf("Would you like to enter another transistor (Y/N)\n");
		question = InputQuestion();
		printf("\n");
		if(question == 0)
			break;
		++numTrans;
		trans = realloc(trans,sizeof(Tran) * (numTrans));

	}while(true);

	/* Output the transistors */
	for(int i=0;i<numTrans;++i)
		DisplayTransistor(trans[i]);

	/* Free the memory */
	free(trans);

}

int InputQuestion()
{
	char buffer[10];

	do
	{
		fgets(buffer,sizeof(buffer),stdin);

		if(strlen(buffer) > 0)
			buffer[strlen(buffer) - 1] = 0;
		if(strcmp(buffer,"N") == 0)
			return 0;
		if(strcmp(buffer,"Y") == 0)
			return 1;
	}while(true);
}
