#include <time.h>
#include<stdio.h>


void my_function()
{
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);


    if(number % 2 == 0)
        printf("%d is even.\n", number);
    else
        printf("%d is odd.\n", number);


}


int main()
{
    double start = clock();

   //my_function();
    int number,i;

    printf("Enter an integer: ");
    scanf("%d", &number);

	double middle = clock();

    if(number % 2 == 0)
        printf("%d is even.\n", number);
    else
        printf("%d is odd.\n", number);

    //for(i=0; i<100000; i++)


    double finish = clock();

    printf("Time for inputting: %f seconds\n", (double)(middle - start) / CLOCKS_PER_SEC);
    printf("Time for processing: %f seconds\n", (double)(finish - middle) / CLOCKS_PER_SEC);
	printf("Time for full: %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);


    return 0;
}
