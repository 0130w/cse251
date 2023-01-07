#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "io.h"

/* Function Definition */

char *InputEventDescription(char *prompt,char *pointer)
{
    char buffer[50];
    bool flag = false;

    do
    {
        printf("%s",prompt);

        fgets(buffer,sizeof(buffer),stdin);

        if(strlen(buffer) > 0)
        {
            buffer[strlen(buffer) - 1] = 0;
            flag = true;
        }

    } while (!flag);

    strncpy(pointer,buffer,sizeof(buffer));
}

time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;

    do
    {
        printf("%s",prompt);

        fgets(buffer,sizeof(buffer),stdin);

        if(strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = 0;

        //printf("%s",buffer);
        //printf("%d/%d/%d  ",date.tm_mon,date.tm_yday,date.tm_year);
        result = strptime(buffer,"%m/%d/%Y",&date);
        /* the value of tm_mon is 0 to 11*/
        //printf("%d/%d/%d  ",date.tm_mon,date.tm_mday,date.tm_year);
        //printf("%s\n",buffer);

    } while (result == NULL);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = 0;  /* wtf */
    
    //printf("%ld",mktime(&date));

    return mktime(&date);
}

time_t InputTime(char *prompt,time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s",prompt);

        fgets(buffer,sizeof(buffer),stdin);

        if(strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = 0;
        
        result = strptime(buffer,"%I:%M%p",&time);

    } while (result == NULL);
    
    return mktime(&time);

}

int InputMainMenuOption(char *prompt)
{
    char buffer[100];
    int value;

    do
    {
        printf("%s",prompt);

        fgets(buffer,sizeof(buffer),stdin);
        if(strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = 0;
        
        sscanf(buffer,"%d",&value);

        if(!(value >= 0 && value <= 4))
            printf("You input invalid value!\n");

    } while (!(value >= 0 && value <= 4));
    
    return value;
    
}

void DisplayMainMenu()
{
    printf("1 - Insert a new event\n");
    printf("2 - Display all events\n");
    printf("3 - Now?\n");
    printf("4 - Delete expired\n");
    printf("0 - Exit\n");
}

Ev *InsertNewEvent(int *numOfEvents)
{
    /* Allocate for memory space */
    Ev *p = (Ev *)malloc(sizeof(Ev));
    /* Judge whether success or not */
    if(p == NULL)
    {
        printf("Allocate failed!\n");
        return NULL;
    }

    ++(*numOfEvents);

    /* Information Input*/
    InputEventDescription("What is the event: ",p->event.des);
    p->event.date = InputDate("Event Date: ");
    p->event.start = InputTime("Start time: ",p->event.date);
    //printf("start:%ld\n",p->event.start);
    p->event.end = InputTime("End Time: ",p->event.date);
    //printf("start:%ld\n",p->event.start);
    //printf("start:%ld\n",p->event.end);

    p->next = NULL;
    
    /* Return pointer */
    return p;
}

void OutputDate(struct tm *date)
{
    printf("%d/%d/%d  ",date->tm_mon + 1,date->tm_mday,date->tm_year + 1900); /* the value of tm_mon is from 0 to 11*/
}

void OutputTime(struct tm *time)
{
    if(time->tm_hour > 12)
    {
        if(time->tm_min < 10)
        printf("%d:0%dpm  ",time->tm_hour%12,time->tm_min);
        else
        printf("%d:%dpm  ",time->tm_hour%12,time->tm_min);
    }
    else if (time->tm_hour == 12)
    {
        if(time->tm_min < 10)
        printf("%d:0%dpm  ",time->tm_hour,time->tm_min);
        else
        printf("%d:%dpm  ",time->tm_hour,time->tm_min);
    }
    else
    {
        if(time->tm_min < 10)
        printf("%d:0%dam  ",time->tm_hour,time->tm_min);
        else
        printf("%d:%dam  ",time->tm_hour,time->tm_min);
    }
}

void DisplayAllEvents(Ev *head)
{
    struct tm *date = (struct tm *)malloc(sizeof(struct tm));
    struct tm *start =(struct tm *)malloc(sizeof(struct tm));
    struct tm *end = (struct tm *)malloc(sizeof(struct tm));
    Ev *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        //printf("date is : %ld\n",temp->event.date);
        //printf("start: %ld,end: %ld",temp->event.start,temp->event.end);
        date = localtime_r(&(temp->event.date),date);
        start = localtime_r(&(temp->event.start),start);
        end = localtime_r(&(temp->event.end),end);
        /* Print Date*/
        OutputDate(date);
        /* Print Start Time*/
        OutputTime(start);
        /* Print End Time*/
        OutputTime(end);
        /* Print Event Description*/
        printf("%s\n",temp->event.des);
    }

    free(date);
    free(start);
    free(end);

}

void DisplayNow(Ev *head)
{
    struct tm *date = (struct tm *)malloc(sizeof(struct tm));
    struct tm *start =(struct tm *)malloc(sizeof(struct tm));
    struct tm *end = (struct tm *)malloc(sizeof(struct tm));
    time_t now;
    //printf("now = %ld\n",time(&now));
    Ev *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        //printf("start = %ld\n",temp->event.start);
        //printf("end = %ld\n",temp->event.end);

        if(temp->event.start <=  time(&now) && temp->event.end >= time(&now))
        {
            date = localtime_r(&(temp->event.date),date);
            start = localtime_r(&(temp->event.start),start);
            end = localtime_r(&(temp->event.end),end);
            /* Print Date*/
            OutputDate(date);
            /* Print Start Time*/
            OutputTime(start);
            /* Print End Time*/
            OutputTime(end);
            /* Print Event Description*/
            printf("%s\n",temp->event.des);
        }
        else
        {
            continue;
        }
    }

    free(date);
    free(start);
    free(end);
}

void DeleteExpiredEvent(Ev *head)
{
    struct tm *date = (struct tm *)malloc(sizeof(struct tm));
    struct tm *start =(struct tm *)malloc(sizeof(struct tm));
    struct tm *end = (struct tm *)malloc(sizeof(struct tm));
    time_t now;
    //printf("now = %ld\n",time(&now));
    Ev *temp = head;
    Ev *front = head;

    while(temp->next != NULL)
    {
        front = temp;
        temp = temp->next;
        //printf("start = %ld\n",temp->event.start);
        //printf("end = %ld\n",temp->event.end);

        if(temp->event.end < time(&now))
        {
            date = localtime_r(&(temp->event.date),date);
            start = localtime_r(&(temp->event.start),start);
            end = localtime_r(&(temp->event.end),end);
            /* Print Date*/
            OutputDate(date);
            /* Print Start Time*/
            OutputTime(start);
            /* Print End Time*/
            OutputTime(end);
            /* Print Event Description*/
            printf("%s\n",temp->event.des);
            /* Delete Event */
            front->next = temp->next;
        }
        else
        {
            continue;
        }
    }

    free(date);
    free(start);
    free(end);
}