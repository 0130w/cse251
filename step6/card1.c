#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/* 
 * Name : zzq
 * Program to draw playing cards
 */

/*Function declaration*/

int compare(int a,int b);
void PrintResult(int card1,int suit1,int card2,int suit2);
void PrintCard(int card,int suit);

/*Main function*/

int main()
{
    int suit1,suit2;
    int card1,card2;
    
    /* 
     . This seeds the random number 
     . generator with the current time 
     */
    srand(time(NULL));
    
    /* Create a random card and suit */
    /* This will compute a random number from 0 to 3 */
    suit1 = rand() % 4;
    suit2 = rand() % 4;
    /* This will compute a random number from 1 to 13 */
    card1 = rand() % 13 + 1;
    card2 = rand() % 13 + 1;

    PrintResult(suit1,card1,suit2,card2);

}

/*Function Defintion*/
int compare(int a,int b)
{
	if(a > b)
	{
		return 1;
	}
	else if(a < b)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

void PrintResult(int card1,int suit1,int card2,int suit2)
{
	if(card1 == 1)
		card1 = 14;
	if(card2 == 1)
		card2 = 14;
	switch(compare(card1,card2))
	{
		case 1:
			printf("Player1 wins\n");
			break;
		case 2:
			printf("Player2 wins\n");
			break;
		default:
			switch(compare(suit1,suit2))
			{
				case 1:
					printf("Player1 wins\n");
					break;
				case 2:
					printf("Player2 wins\n");
					break;
				default:
					printf("This is a tie\n");
					break;
			}
			break;
	}
}

void PrintCard(int card,int suit)
{
	
    switch(card)
    {
    case 1:
        printf("Ace");
        break;
        
    case 11:
        printf("Jack");
        break;
        
    case 12:
        printf("Queen");
        break;
        
    case 13:
        printf("King");
        break;
        
    default:
        printf("%d", card);
        break;
    }
    
    printf(" of ");
    
    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;
        
    case 1:
        printf("Diamonds");
        break;
        
    case 2:
        printf("Spades");
        break;
        
    case 3:
        printf("Clubs");
        break;
    }
}
