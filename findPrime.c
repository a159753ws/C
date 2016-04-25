/*
 * This lab is to prompt the user for input of a positive integer greater 
 * than 1 and less than 200, called x, then generate and print all prime 
 * numbers between 2 and x, also count the number of twin prime pairs found 
 * amongst those primes.
 *
 * by Sheng Wang
 */
#include <stdio.h>

int main()
{
    int x;  	    /* Declear the input variable. */
    int i,j,k;      /* Declear the loop counters. */	
    int index = 1;  /* Declear the array index. */
    int count = 0;  /* Declear the twin primes counter. */
    int arr[200];   /* Initialize the array with length of 200. */
    arr[0]=2;	    /* Initialize first element in array as 2. */

    /* Prompt the user for input of a positive integer. */
    printf("Please input a positive integer between 2 and 199: ");  
    scanf("%d",&x);

    /* 
     * Check to see if the input is valid. Use a while loop to constantly 
     * prompt the user for input of a positive integer until the input is 
     * valid.
     */
    while (x <= 1 || x >= 200) {
        printf("Invalid, the input should be greater than 1 and less than 200.");
        printf("Please input a positive integer between 2 and 199: ");
        scanf("%d",&x);
    }

    /* 
     * Print the header of the result.
     */
    printf("Primes from 2 to %d are:\n",x);

    /* 
     * Check if the input is 2. If it is 2, then simple print 2. If input 
     * is not 2, firstly print 2, then use a nest for loop to check every 
     * integer between 2 and the input.
     */
    if (x == 2) {
        printf("%d ",arr[0]);
    } else {
        printf("%d ",arr[0]);
	/*
	 * To check if a integer is a prime, let this integer divided by 
	 * every integer between 2 and it to get a reminder. If there exists a 
	 * remind is 0, then it is not a prime. Otherwise it is a prime and put 
	 * this integer into the array.
	 */
        for (i = 3; i <= x; i++) {
            for (j = 2; j <= i-1; j++) {
                if (i % j ==0) {
                    break;  /* End this loop. */
                }
            }
            if (j == i) {
                arr[index] = i;  /* Put the prime into the array. */
                printf("%d ",arr[index]);  /* Print the prime. */
                index++;
            }
        }
    }


    /* 
     * Use a for loop to count the number of twin prime pairs. 
     */
    for (k = 1; k<index; k++) {
        if (arr[k] == arr[k-1] + 2) {
            count++;
        }
    }

    /* 
     * Print the number of twin prime pairs. 
     */
    printf("\nAmongst these there are %d twin primes.\n", count);

    return 0;
}
