#include <stdio.h>
#include <time.h>

/* This function checks if the int array is palindrome. */
int check_pallindrome(int arr[], int n) {   
   int i, j, flag = 0;
   for(i = 0, j=n-1; i< n/2, j>=n/2; i++, j--) {
      if(arr[i]!=arr[j]) {
         flag = 1;
         break;
      }
   }
   if (flag == 1)
   return 0;
   else
   return 1;
}


int main(int argc, char const *argv[]) {
	int size,i;
  	printf("Size of Array: ");
   	scanf("%d",&size);
   	int arr[size];
   	
   	while(size<50){  /* If the size is less than 50,  loop begins */
	  	
		  printf("Please Enter Numbers: \n");
		for(i=0;i<size;i++)  /* Int array create */
   		{
       scanf("%d",&arr[i]);
  		 }	
  		 
  		int n = sizeof(arr)/sizeof(arr[0]);
   
   		if(check_pallindrome(arr, n)) {
      	printf("Your input is a palindrome\n");
      	break;
   		}
   		else
      	printf("Your input is not a palindrome\n");
      	break;
}
   
	int arr2[20];
	for (i = 0; i <= 20 ;i++) {
    arr2[i] = (rand() % 100);
    printf("%4d", arr2[i]);
	}
return 0;
}
