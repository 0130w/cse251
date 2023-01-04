#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
/*
 *This is a simple program to compute the resonant frequency of an RLC circuit
 * */

double L,C;//Inductance in millihenrys and capacitance in microfarads
double omega,freq;//resonance frequency in radians per second and resonance frequency in hertz
bool valid = true;// Until we know otherwise
int main()
{
	printf("Input Inductance (microhenrys) :");
	scanf("%lf",&L);
	if(L<0)
	{
		printf("You moron, you entered a negative inductance!\n");
		valid=false;
	}
	else if(L==0)
	{
		printf("You are really dumb,you entered zero.\n");
		valid=false;
	}
	else
		printf("Okay, I guess that's reasonable\n");
	
	
	printf("Input Capacitance (microfarads)");
	scanf("%lf",&C);
	if(C<0)
		printf("You moron, you entered a negative inductance!\n");
	else if(C==0)
	{
		printf("You are really dumb,you entered zero.\n");
		C=1;
	}
	else
		printf("Okay, I guess that's reasonable\n"),C=1;
	if(valid)
	{
		omega=1.0/sqrt((L/1000)*(C/1e6));
		freq=omega/(2*M_PI);
		printf("Resonant Frequency is %.3lf",freq);
		if(freq>=20 && freq<=2e4)
			printf("This frequency is one I can hear!");
	}
}
