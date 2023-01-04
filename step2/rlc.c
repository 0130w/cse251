#include<stdio.h>
#include<math.h>

/*
 *This is a simple program to compute the resonant frequency of an RLC circuit
 * */

double L,C;//Inductance in millihenrys and capacitance in microfarads
double omega,freq;//resonance frequency in radians per second and resonance frequency in hertz

int main()
{
	printf("Input Inductance (millihenrys) :");
	scanf("%lf",&L);

	printf("Input Capacitance (microfarads) :");
	scanf("%lf",&C);

	omega=1/sqrt(L/1e6*C/1e3);
	freq=omega/(2*M_PI);
	printf("Resonant Frequency is %.3lf",freq);

}
