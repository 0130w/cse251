#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/*  Name : zzq
    Date : 2023.1.5
*/

/* Function Declaration*/

double InputValue(char *prompt);
int InputPositiveNum(char *prompt);
double function(double value);
double Compute(double lowerBound,double upperBound,int num);

/* Main Function*/

int main()
{
    double lowerBound, upperBound; /*the lower bound and the upper bound of the integration*/
    int num;
    double integration; /*Answer*/

    do
    {
        lowerBound = InputValue("Input Lower Bound: ");
        upperBound = InputValue("Input Upper Bound: ");
        num = InputPositiveNum("Input Number of Partitions: ");

        if( (upperBound-lowerBound) >= 0)
            break;
        printf("Input Invaild value!\n");
        
    } while(true);

    integration = Compute(lowerBound,upperBound,num);

    printf("%d: %.9lf\n",num,integration);

}

/* Function Definition*/

double InputValue(char *prompt)
{
    char buffer[100];
    double value;

    printf("%s",prompt);

    fgets(buffer,sizeof(buffer),stdin);

    if(strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = 0;

    sscanf(buffer,"%lf",&value);

    return value;
}

int InputPositiveNum(char *prompt)
{
    char buffer[100];
    int num;

    printf("%s",prompt);
    do
    {
        fgets(buffer,sizeof(buffer),stdin);

        if(strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = 0;

        sscanf(buffer,"%d",&num);

    } while (num<=0);

    return num;

}

double function(double value)
{
    return sin(M_PI * value)/(M_PI * value);
}

double Compute(double lowerBound,double upperBound,int num)
{
    double sum = 0; /* the value of the integration*/
    double delta;

    delta = (double)((upperBound-lowerBound)/num);

    for(int i=1;i<=num;++i)
    {
        sum += function(lowerBound + (i - 0.5)*delta) * delta;
    }

    return sum;
}