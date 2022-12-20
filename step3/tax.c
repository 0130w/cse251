#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 *This is a simple program to compute people's tax
 * */

int main()
{
	/*declare the variables I need*/
	double income;/*User's annual income*/
	int choice;/*the choice of filing status*/	
	int dependents;/*the number of dependents*/
	double stddeduction;/*the standard deduction*/
	int childrennum;//the number of children
	double totdeduction;//the totaldeduction
	double taxincome;//the taxable income
	double tax;//the tax you should pay for
	/*the main function of this program*/
	printf("Enter your annual income:\n");
	scanf("%lf",&income);
	if(income<0)
	{
		printf("you entered a invalid number.\n");
		exit(1);
	}
	if(income<9350)
	{
		printf("0.00\n");
		exit(0);
	}
	printf("What is your filing status?\n");
	printf("1) single\n");
	printf("2) married filing jointly\n");
	printf("3) married filing separately\n");
	printf("Please enter a number:\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			dependents=1;
			stddeduction=5700;
			break;
		case 2:
			stddeduction=11400;
			printf("How many children do you have?");
			scanf("%d",&childrennum);
			dependents= childrennum+2;
			break;
		case 3:
			dependents=1;
			stddeduction=5700;
			break;
	}
	totdeduction = dependents * 3650 + stddeduction;
	printf("%.2f\n",totdeduction);
	taxincome=income-totdeduction;
	if(taxincome<0)
	{
		printf("0.00");
		exit(0);
	}
	if(taxincome<=16750)
	{
		tax=taxincome*0.1;
		printf("%.2f",tax);
		exit(0);
	}
	if(taxincome<=68000)
	{
		tax=(taxincome-16750)*0.15+1675;
		printf("%.2f",tax);
		exit(0);
	}
	if(taxincome<=137300)
	{
		tax=(taxincome-68000)*0.25+9362.5;	
		printf("%.2f",tax);
		exit(0);
	}
	tax=(taxincome-137300)*0.28+26687.5;
	printf("%.2f",tax);
	return 0;
}
