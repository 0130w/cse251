#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "io.h"

/*  CSE251
*   Name: zzq
*   Date: 2023/1/5
*/

/* Function Declaration */

/* Main Function */

int main()
{
    int mainMenuOption;
    int numOfEvents = 0;
    Ev *head,*tail;
    head = (Ev *)malloc(sizeof(Ev));
    tail = head;

    do
    {
        DisplayMainMenu();
        mainMenuOption = InputMainMenuOption("Please select an option: ");
        switch (mainMenuOption)
        {
            case 1:
                {
                    Ev *p = InsertNewEvent(&numOfEvents);

                    if(p == NULL) /* Allocate failed */
                        exit(-1);
                    
                    if(numOfEvents == 1)
                    {
                        head->next = p;
                        tail = p;
                    }
                    else
                    {
                        tail->next = p;
                        tail = tail->next;
                    }
                }
                break;
            case 2:
                DisplayAllEvents(head);
                break;
            case 3:
                DisplayNow(head);
                break;
            case 4:
                DeleteExpiredEvent(head);
                break;
            default:
                return 0;
        }

    } while (true);

}


/* Function Definition */

