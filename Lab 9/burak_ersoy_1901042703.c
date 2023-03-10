#include <stdio.h>
#include <string.h>

typedef struct {
	float x1,y1,x2,y2,x3,y3,m;
}line;

typedef struct {
	float midterm, final, homework;
}grades;

typedef struct {
	char name[30];
	int id;
	grades g;
}students;

typedef struct {
	char name[30];
	char platforms[100][100];
	float score;
}games;

void part1(){
	//creating the struct variable
	line line1;
	//reading inputs
	printf("x1: ");
	scanf("%f", &line1.x1);
	printf("y1: ");
	scanf("%f", &line1.y1);
	printf("x2: ");
	scanf("%f", &line1.x2);
	printf("y2: ");
	scanf("%f", &line1.y2);
	printf("x3: ");
	scanf("%f", &line1.x3);
	//calculating and assigning m and y3 according to the geometric formula (equation of the line with 2 points)
	line1.m = (line1.y2 - line1.y1) / (line1.x2 - line1.x1);
	line1.y3 = line1.m * (line1.x3 - line1.x1) + line1.y1;
	//printing the results
	printf("y3 = %f\n", line1.y3);
	printf("m  = %f\n", line1.m);
	return;
}

void part2(){
	//crerating a struct array (up to 100 students)
	students s[100];
	int i, n, id, flag=0, sum_of_midterm = 0, sum_of_homework = 0, sum_of_final = 0;
	
	printf("Number of the students: ");
	scanf("%d", &n);
	
	//reading each student's info in a loop
	for (i=0; i<n; i++){
		printf("\nName: ");
		fflush(stdin); // clearing the inputs which cause trouble with scanf
		scanf("%[^\n]%*c", s[i].name); // %[^\n]%*c means 'read every character until you see a new line character' which means until user press enter.
		printf("ID: ");
		scanf("%d", &s[i].id);
		//reading grades and assignin them to the struct's grade's related variable. also keep them in a sum variable to calculate the average
		printf("Midterm: ");
		scanf("%f", &s[i].g.midterm);
		sum_of_midterm += s[i].g.midterm; 
		printf("Homework: ");
		scanf("%f", &s[i].g.homework);
		sum_of_homework += s[i].g.homework;
		printf("Final: ");
		scanf("%f", &s[i].g.final);
		sum_of_final += s[i].g.final;
	}
	
	// a new struct to keep averages
	grades average;
	average.midterm  = sum_of_midterm  / i ;
	average.homework = sum_of_homework / i ;
	average.final    = sum_of_final    / i ;
	
	// printing the averages
	printf("\nAverage of the midterms: %f\n", average.midterm);
	printf("Average of the homeworks: %f\n", average.homework);
	printf("Average of the finals: %f\n", average.final);
	
	// student search through id number
	printf("\nEnter an ID number: ");
	scanf("%d",&id);
	
	// checking every students id number. if the student is found the flag will be 1. if not the flag will stay 0 (it was assigned 0 at the beginning).
	for (i=0; i<n; i++){
		// if the id matches, print the information of the student
		if (s[i].id == id){
			printf("Name: %s\n", s[i].name);
			printf("Id: %d\n", s[i].id);
			printf("Midterm: %f\n", s[i].g.midterm);
			printf("Homework: %f\n", s[i].g.homework);
			printf("Final: %f\n", s[i].g.final);
			flag = 1;
			break;
		}
	}
	// if the flag is not 1, it means that the if block above never worked, in other words the student couldnt found
	if (flag != 1)
		printf("No students found.\n");
	return;
}

void part3(){
	// creating the struct array (up to 100 structs)
	games g[100];
	// declaring a string array to keep every unique platform name. no dublicated platform name will be in this array.
	char platforms[100][100];
	int i, j, k, n, p, platform_count = 0, flag = 0;
	float sum_of_score = 0;
	
	printf("Number of the games: ");
	scanf("%d", &n);
	
	// reading each game's info in a loop
	for(i=0; i<n; i++){
		printf("\nName: ");
		fflush(stdin); // cleaning the keyboard inputs
		scanf("%[^\n]%*c", g[i].name);
		
	    printf("Number of the platforms: ");
	    scanf("%d", &p);
		
		// reading each platform's names
		for (j=0; j<p; j++){
			printf("%d. Platform: ", j+1);
			scanf("%s",g[i].platforms[j]);
			
			//checking if the readed platform name is in the 'platforms array'. If it is, change the flag to understand
			for (k=0; k<platform_count; k++)
				if(strcmp(platforms[k], g[i].platforms[j]) == 0)
					flag = 1;
			//if flag is not 1, it means that the last written platform is a new platform and should be added to the array		
			if (flag!= 1){
				strcpy(platforms[platform_count], g[i].platforms[j]);
				//keeping the number of the unique arrays to use in loops
				platform_count++;
			}
		}
		printf("Score: ");
		scanf("%f", &g[i].score);
		//keeping the sum of the scores to calculate average
		sum_of_score += g[i].score;
   }
	//printing average
	printf("\n\nAverage of the scores: %f", sum_of_score / n );
	
	//for each unique platform, printing the games
	for (i=0; i<platform_count; i++){
		printf("\n%s games: \n", platforms[i]);
		//checking every game...
		for (j=0; j<n; j++)
		    //... to see if one of its platforms match with the one we currintly looking for
			for (k=0; k<100; k++)
			    // if we find a match, we print it
				if(strcmp(g[j].platforms[k], platforms[i]) == 0)
					printf("%s\n", g[j].name);
	}
}

int main()
{
	printf("---------- PART 1 ----------\n");
	part1();
	
	printf("\n\n---------- PART 2 ----------\n");
	part2();
	
	printf("\n\n---------- PART 3 ----------\n");
	part3();
	
	return 0;
}
