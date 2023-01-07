#ifndef IO_H
#define IO_H
#define __USE_XOPEN

#include <time.h>

#define MaxNumOfEvents 100

/* Structure */

typedef struct Scheduler
{
    char des[50]; /* The event description */
    time_t date;
    time_t start;
    time_t end;
} Scheduler;

typedef struct NewEvent
{
    Scheduler event;
    struct NewEvent *next;
}Ev;

/* Function Declaration*/
void OutputDate(struct tm *date);
void OutputTime(struct tm *time);
char *InputEventDescription(char *prompt,char *pointer);
time_t InputDate(char *prompt);
time_t InputTime(char *prompt,time_t date);
int InputMainMenuOption(char *prompt);
void DisplayMainMenu();
Ev *InsertNewEvent(int *numOfEvents);
void DisplayAllEvents(Ev *head);
void DisplayNow(Ev *head);
void DeleteExpiredEvent(Ev *head);

#endif