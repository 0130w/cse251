#include <stdio.h>
#include <string.h>

/*
 * Name : <zzq>
 * Program to experiment with strings
 */

/*
 * Function Declaration
 */

int StringLength(char *str);
void PrintLength(char *str);
void Reverse(char *str);
int NumberOfSpaces(char *str);
/*
 * Main function
 */

int main()
{
	char mySentence[80];
	int len;

	printf("Enter a sentence: ");
    	fgets(mySentence, 80, stdin);
	len = strlen(mySentence);
	mySentence[len-1] = 0;
	printf("The entered sentence is: %s\n", mySentence);
	
	Reverse(mySentence);
	PrintLength(mySentence);
	printf("The number of spaces of the sentence %s is %d\n",mySentence,NumberOfSpaces(mySentence));
}

/*
 * Function Defintion
 */
int NumberOfSpaces(char *str)
{
	int numSpaces = 0;
	for(int i=0; str[i] != 0; ++i)
	{
		if(str[i] == ' ')
			++numSpaces;
	}
	return numSpaces;
}
void Reverse(char *str)
{
	int front = 0;
	int back = strlen(str) - 1;
	char temp;

	while(front < back)
	{
		temp = str[front];
		str[front] = str[back];
		str[back] = temp;
		++front;
		--back;
	}
}
void PrintLength(char *str)
{
	printf("The string %s is %lu characters long\n",str,strlen(str));
}

int StringLength (char *str)
{
	int numChars = 0;	
	while(str[numChars] != 0)
		++numChars;
	return numChars;
}
