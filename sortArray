/*
 * This lab is to prompt the user for input of a array size and each of array 
 * element, then sort the array with increasing value. 
 *
 * by Sheng Wang
 */
#include <stdio.h>
#include <stdlib.h>

/* Sort the array with increasing value. */
void sort (float *arr,int s);

int main()
{
	/* Declear the index and size variable. */
	int i, s, r;

	/* Prompt the user for the array size. */
	printf("Please enter the array size: \n");
	scanf("%d",&s);

	/* Check if the size is a positive integer. If not, the program terminates. */
	if (s <= 0) {
		printf("[Terminated]Invalid input. Entered input is not a positive number.\n");
		exit(-1);
	}

	/* Create an array dynamically. */
	float* arr = malloc(s * sizeof(float));

	/* Prompt the user for each element in the array. */
	printf("Please enter the numbers in the array: \n");
	for (i = 0; i < s; i++) {
		r = scanf("%f",&arr[i]);			
			/* Check if the element is a number. If not, the program terminates. */
		        if (r <= 0) {       
				printf ("[Terminated]Invalid input. Entered input is not a number.\n");
            			exit(-1);
        		}
	} 

	/* Print the array before sorted. */
	printf("\nThe array before sorted is: \n");
	for (i = 0; i < s; i++) {
		printf("%g ",arr[i]);
	}  

  	/* Sort the array by calling the function. */
	sort (arr, s);

	/* Print the array after sorted. */
	printf("\nSorted array with increasing value: \n");
	for (i = 0; i < s; i++) {
		printf("%g ",arr[i]);
	}    

	/* Free the memory block. */
	free(arr);
	printf("\nThe memory block for this array has been freed. \n");

	return 0;
	}

/**
 * Sort the given array with increasing value
 * 
 * @param the array pointer and the array size
 */
void sort (float *arr, int s) {
	/* Declear the two index variables. */
	int i, j;
	float temp;
	for (i = 0; i < s; i++) {
		for (j = i + 1; j < s; j++) {
			/* Compare the two element. Swap if the previous one is bigger than the later one  */
            		if (*(arr + i) > *(arr + j)) {
                		temp = *(arr + i);
                		*(arr + i) = *(arr + j);
                		*(arr + j) = temp;
            		}
        	}
   	 }    
}
