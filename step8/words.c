#include <stdio.h>

/* 
 * Name : <zzq>
 * Program to experiment with character arrays
 */

#define MaxWord 20
 
int main ()
{
    char c;
    char str[MaxWord+1];
    int len = 0;
    int totlen = 0;
    int totword = 0;
    double avgWordLength;
    char longestWord[MaxWord + 1];
    int longestLen = 0;

    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do 
    {
        c=getchar();
	if(c != ' ' && c != '.' && len < MaxWord)
	{
		/*This is a character of a word*/
		str[len] = c;
		++len;
	}
	else
	{
		/*The word is done*/
		if(len == 0)
			continue;
		if(len > longestLen)
		{
			for(int i=0;i<len;++i)
			{
				longestWord[i] = str[i];
			}
			longestLen = len;
			longestWord[longestLen] = 0;
		}
		totlen += len;
	       	++totword;	
		str[len] = 0;
		printf("%s\n",str);
		len = 0;
	}
    } while (c != '.');
    avgWordLength = (double) totlen / totword ;
    printf("The average length of these words is %.2f\n", avgWordLength);
    printf("The longest word is %s\n",longestWord);
}
