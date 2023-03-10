#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//struct for dynamic array
typedef struct {
	char country[15];
	char capital[15];
	int population;
	bool driving_side;
} countries;

//struct for linked list
struct c_ll {
	char country[15];
	char capital[15];
	int population;
	bool driving_side;
	struct c_ll *next;
};


int main() {
	countries *myCountries;
	myCountries = (countries*)malloc(sizeof(countries));
	int choice, input_counter=0, i=0, side, line_counter=0, ll_counter=0;
	FILE *f;
	struct c_ll* head;

	// menu in an infinite loop
	while (1) {
		printf("1: Enter new record\n2: Write to the file\n3: Read from the file\n4: Print the linked list\n5: Exit\n\nYour Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1 : {
			    // reallocate the memory every time (index keeps the number of records)
				myCountries = (countries*) realloc (myCountries, (input_counter+1)*sizeof(countries));  

				// reading and saving info to the dynamic array
				printf("Country name: ");
				scanf("%s", myCountries[input_counter].country);
				printf("Capital: ");
				scanf("%s", myCountries[input_counter].capital);
				printf("Population of %s: ", myCountries[input_counter].country);
				scanf("%d", &myCountries[input_counter].population);
				printf("Do people in %s drive on the right side? (Yes:1, No:0) : ", myCountries[input_counter].country);
				scanf("%d", &side);
				myCountries[input_counter].driving_side = side ? 1 : 0;
				// increase the counter
				input_counter++; 
				break;
			}

			case 2 : {
				// create and open the file in writing mode
				f = fopen("cse108.txt", "w");
				// raise an error if the file couldn't created or opened
				if (f == NULL) {
					printf("Could not open file.");
					break;
				}
				// number of the lines that written to the file. we are reseting it every time user want to write to the file ++
				// because if we already wrote to the file before, we will overwrite it and therefore starting from 0. 
				line_counter = 0;
				// we use a loop which runs 'input_counter' times
				for (i=0; i<input_counter; i++) {
					// using fprint to print to the file
					fprintf(f, "%s %s %d ", myCountries[i].country, myCountries[i].capital, myCountries[i].population);
					// Writing right or left according to the driving_side's value. True means right and false means left
					fprintf(f, myCountries[i].driving_side ? "Right" : "Left");
					// next line character (to not write all entries in only one line
					fprintf(f, "\n");
					// incrementing line counter
					line_counter++;
				}
				// printing a message to the screen to inform user
				printf("Written to the file succesfully.\n");
				// closing the file
				fclose(f);
				break;
			}

			case 3 : {
				// setting head as null. we are doing this operation in case3 because we will overwrite if we already read file before
				head = NULL;
				// also assigning the number of nodes in linked list as 0
				ll_counter = 0;
				// reopening the file (in reading mode this time)
				f = fopen("cse108.txt", "r");
				// same control block as in case 2
				if (f == NULL) {
					printf("Could not open file.");
					break;
				}
				// if the file has been opened succesfully but there is no line, we raise an error
				if (line_counter == 0){
					printf("There is no data in the file.");
					break;
				}
				// to read the .txt file, there are several functions. in this file fscanf has been used
				// buffer will keep a single line, driving_side will keep the 'right' or 'left' text
				char buffer[200], *driving_side;
				// since we now how many lines have been written to the file, we use that info in our loop 
				// this for loop might cause an error if you change the file manually (since the number of lines might change, and the program won't know it)
	            struct c_ll *new_node;
				for(i=0; i<line_counter; i++) {
				    new_node = (struct c_ll*) malloc (sizeof(struct c_ll));
					// reading until a new line character and saving it in the 'buffer'. until a new line means we have read a single line
					fscanf(f, "%[^\n]\n", buffer);
					// we are using strtok to split the buffer (we know that each info is splitted with a white space)
					char *token = strtok(buffer, " ");
					// copying the strings to the linked list's element
					strcpy(new_node->country, token);
					token = strtok(NULL, " ");
					strcpy(new_node->capital, token);
					token = strtok(NULL, " ");
					// we use atoi function to convert string to int
					new_node->population = atoi(token);
					token = strtok(NULL, " ");
					// we save true or false according to the 'right' or 'left' value
					if(strcmp("Right",token)==0)
						new_node->driving_side = true;
					else
						new_node->driving_side = false;	
					// assigning next node as null
					new_node -> next = NULL;
					
					// if this is the first node, it will be head itself
					if(head==NULL)
					    head = new_node;
					    
					// if it is not, we are finding the last node in a while loop and assigning the new_node as the last node's next
					else{
						struct c_ll *last_item = head;
						while (last_item -> next != NULL)
						   last_item = last_item -> next;
						last_item -> next = new_node;
					}					
					// incrementing the number of nodes in linked list
					ll_counter++;
				}	
				// printing a message to the screen
				printf("File has been read succesfully.\n");
				// closing the file
				fclose(f);
				break;
			}

			case 4 : {
			    // we raise an error if there is no element in the list.
			    if (ll_counter==0){
			    	printf("There is no data in the linked list.");
			    	break;
				}
				struct c_ll * iter2 = head;
			    // this loop will work until the end of the list
				while(iter2!=NULL){
					// printing the data
					printf("Country: %10s\tCapital: %10s\tPopulation: %d\t\tDriving Side: ", iter2->country,iter2->capital,iter2->population);
					// printing left or right according to the true / false value
					printf(iter2->driving_side ? "Right\n" : "Left\n");
					// jumping to the next element of the list
					iter2 = iter2->next;
				}
				break;
			}

			case 5 : {
				// jump to the exit block
				goto exit;
				break;
			}
			
			default : {
			    printf("Invalid input!\n");				
				break;
			}
			
		}
		printf("\n\n");	
	}
exit:
	printf("Terminating...");
	return 0;
}
