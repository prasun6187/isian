//Given an input vector find the corresponding normalized vector. [Length of a normalized vector = 1].
#include<stdio.h>
#include<math.h>
#define max 100
int main(void)
{
    double vec[max], sum = 0;
    int n, i;
    printf("Enter the dimension of the vector: ");
    scanf("%i", &n);
    printf("Enter the elements of the vector: \n");
    for (i = 0; i < n; i ++)
    {
        scanf("%lf", &vec[i]);
        sum += vec[i] * vec[i];
    }
    sum = sqrt (sum);
    printf("The normalised vector is : ");
    for(i = 0; i < n; i++)
    {
        printf("%0.2lf  ", vec[i] / sum);
    }
    printf("\n");
}
