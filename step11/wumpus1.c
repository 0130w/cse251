#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*
 * Name :  <zzq>
 * 
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */

#define Empty 0
#define Wumpus 1
#define End 2
#define CaveSize 20
#define ArraySize (CaveSize+2)
#define Left 0
#define Right 1
/* Add any function prototypes here */

void CreateWorld(int *cave,int **wumpusRoom);
int *GetEmptyRoom(int *cave);
void DisplayWorld(int *cave,int *agent,int agentDirection);
int DifferenceByDirection(int dir);
bool DisplayStatus(int *cave,int *agent);

int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int *wumpusRoom;
    int agentDirection;    
    /* Seed the random number generator */
    srand(time(NULL));
    
    CreateWorld(cave,&wumpusRoom);

    agentRoom = GetEmptyRoom(cave);

    agentDirection = rand() % 2;

    /*The Game Loop*/
    while(true)
    {
	if(DisplayStatus(cave,agentRoom))
		break;

	DisplayWorld(cave,agentRoom,agentDirection);

	char command[20];

	/*Get the command*/
	printf("Command: ");
	scanf("%20s",command);

	if(strcmp(command,"quit") == 0)
	{
		break;
	}
	else if(strcmp(command,"turn") == 0)
	{
		agentDirection = !agentDirection;
	}
	else if(strcmp(command,"move") == 0)
	{
		int direction = DifferenceByDirection(agentDirection);
		if(*(agentRoom+ direction) != End)
			agentRoom += direction;
	}
	else if(strcmp(command,"fire") == 0)
	{
		switch(agentDirection)
		{
			case Left:
				for(int *temp = agentRoom;*temp != End && temp >= agentRoom -3; --temp)
					*temp = Empty;
				break;
			case Right:
				for(int *temp = agentRoom;*temp != End && temp <= agentRoom +3; ++temp)
					*temp = Empty;
				break;
		}
		
		if(*wumpusRoom == Empty)
		{
			printf("You win\n");
			return 0;
		}

	}
	else
	{
		printf("I don't know what are you talking about\n");
	}
    }
}

void CreateWorld(int *cave,int **wumpusRoom)
{
	for(int i = 0; i<ArraySize;++i)
	{
		cave[i] = Empty;
	}
	
	cave[0] = End;
	cave[ArraySize - 1] = End;

	*wumpusRoom = GetEmptyRoom(cave);
	**wumpusRoom = Wumpus;
}

int *GetEmptyRoom(int *cave)
{
	int room;

	do
	{
		room = rand() % ArraySize;
	}while(cave[room] != Empty);

	return &cave[room];
}

void DisplayWorld(int *cave,int *agent,int agentDirection)
{
	int *room;
	
	for(room = cave+1; *room != End;++room)
	{
		if(room == agent)
		{
			switch(agentDirection)
			{
				case Left:
					printf("<A ");
					break;
				case Right:
					printf("A> ");
					break;
			}
			continue;
		}

		switch(*room)
		{
			case Wumpus:
				printf("-w- ");
				break;
			default:
				printf(". ");
				break;
		}
	}

	printf("\n");
}

int DifferenceByDirection(int dir)
{
	if(dir == Left)
		return -1;
	else
		return 1;
}

bool DisplayStatus(int *cave,int *agent)
{
	if(*agent == Wumpus)
	{
		printf("You have been eaten by the Wumpus\n");
		return true;
	}
	if(*(agent - 1) == Wumpus || *(agent + 1) == Wumpus)
	{
		printf("I smell a Wumpus\n");
	}
	return false;
}
