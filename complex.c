//Take two complex numbers as input (to be stored into structures) from keyboard.
//Add them by calling a function. Print the sum from main. Use the concept of typedef in the programming style.

#include<stdio.h>

typedef struct cx
{
	float real;
	float imag;
}
complex;
complex input[2];
complex sum(complex x[2]);
int main(void)
{
    int i = 0;
	do
	{
	    printf("real part: ");
	    scanf("%f", &input[i].real);
	    printf("imaginary part: ");
	    scanf("%f", &input[i].imag);
	    i ++;
	}
	while (i < 2);
	printf("Sum Real part : %f\n", sum(input).real);
	printf("Sum Imaginary part : %f\n", sum(input).imag);
}
complex sum(complex x[2])
{
    complex y;
    y.real = x[0].real + x[1].real;
    y.imag = x[0].imag + x[1].imag;
    return y;
}
