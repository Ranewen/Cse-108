#include <stdio.h>
#include<stdlib.h>

void expression0 (int x, int *result){
	// assinging the "result" as it said in the expression
	*result = x*x + 5;
	return;
}

void expression1 (int x, int *result){
	// assinging the "result" as it said in the expression
	*result = 2*x + 1;
	return;
}

void expression2 (int x, int *result){
	// assinging the "result" as it said in the expression
	*result = x*x;
	return;
}

void sum (void (*f)(int, int *), int *sum, int n){
	int i, singleValue;
	int total = 0;
	
	//from 0 to n, finding the value of each item (for example 2x+1 is being calculated for each integer between 0 and n)
	for (i=0; i<=n; i++){
		(*f)(i, &singleValue); //calling the function, it will return the output as "singleValue"
		total += singleValue; // add the "singleValue" to "total"
	}
	*sum = total; // finally assing the sum 
}

//this function finds three different result. Each for a single expression.
void calculation (int *sumArray, int n){
	
	// saving the 0th element of the array, finding the result of expression0, assinging the result to the 0th element of the array
	int k = sumArray[0];
	(*sum) (expression0, &k, n); //using the "expression0" function as the argument of the "sum" function
	sumArray[0] = k;
	
	// do the same thing for expression1 (it's result will be kept in 1st element of the array)
	k = sumArray[1];
	(*sum) (expression1, &k, n);
	sumArray[1] = k;
	
	// do the same thing for expression2 (it's result will be kept in 2nd element of the array)
	k = sumArray[2];
	(*sum) (expression2, &k, n);
	sumArray[2] = k;
}

// function for part2
void createArray(int (*array)[10]){
	int i, j;
	// we use nested loops to reach the elements of a 2d array
	for (i=0; i<10; i++)
		for (j=0; j<10; j++)
			array[i][j] = (rand() % 90) + 10; // we create a random number and assing it
}
int main()  
{
	// part 1
    int n;
    printf("Part 1\n\nn: ");
    scanf("%d", &n);
    int results [3];
    calculation (results, n); //calling the function, the results will be written to "results" array.
    printf("Sum of expression0: %d\n", results[0]);
    printf("Sum of expression1: %d\n", results[1]);
    printf("Sum of expression2: %d\n", results[2]);
    
    printf("\n\n=======================\n\n");
    
    // part 2
    int i,j;
	int myArray [10][10];
	createArray(myArray); //filling the array
	//printing the array
	printf("Part 2\n\nMatrix:\n\n");
	for (i=0;i<10;i++){
		for (j=0; j<10; j++)
			printf("%d ", myArray[i][j]); 
		printf("\n");
	}
	
	// an endless loop to ask user to enter inputs
	while(1){
		printf("\nWhich element of the matrix do you want to reach?\ni: ");
		scanf("%d",&i);
		printf("j: ");
		scanf("%d", &j);
		// if the inputs exceed the array's size, print an error message and break the loop
		if(i<0 || i>9 || j<0 || j>9){
			printf("Invalid input. Terminating...");
			break;
		}
		// if not, print the related element
		else
			printf("%d. row %d. column of the matrix is %d\n\n", i, j, myArray[i][j]);
	}
    return 0;
}
