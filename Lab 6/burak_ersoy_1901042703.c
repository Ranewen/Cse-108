#include <stdio.h>

void averageFinder();
void intervew(const char *, const char *, char *);

int main(){
	float result;
	
    const char s1[] = "abcdefg";
    const char s2[] = "1234";
    char s3[12] = {"\0"};
    
	averageFinder();
    intervew(s1, s2, s3);
    
    printf("String1 : %s\nString2 : %s\nIntervew : %s\n", s1, s2, s3);

    return 0;
}

void averageFinder(){
	printf("Average Finder \n\n");
	int matrix[4][9];
	int matrix2[3][5];
	float counter = 0.0;
	float total = 0.0;
	
	printf("\nMatrix 1 :\n");
	for(int i = 0; i <4; i++){
		for(int j=0; j<9; j++){
			counter++;
			matrix[i][j] = (2 * counter * counter - 3);
			printf("%d \t",matrix[i][j]);
		}
		printf("\n");
	}
	
	counter = 0;
	for(int i = 0; i <4; i++){
		for(int j =	0; j<9; j++){
			if(!((i + j) % 2)){
				counter++;
				total += matrix[i][j];
			}
		}
	}
	
	printf("\nMatrix 1 Result = %.1f \n", total/counter);
	
	counter = 0;
	printf("\nMatrix 2 :\n");
	for(int i = 0; i <3; i++){
		for(int j=0; j<5; j++){
			counter++;
			matrix2[i][j] = (2 * counter * counter - 3);
			printf("%d \t",matrix2[i][j]);
		}
		printf("\n");
	}
	
	counter = 0;
	total = 0;
	for(int i = 0; i <3; i++){
		for(int j =	0; j<5; j++){
			if(!((i + j) % 2)){
				counter++;
				total += matrix2[i][j];
			}
		}
	}
	printf("\nMatrix 2 Result = %.1f\n", total/counter);
}

void intervew(const char *s1, const char *s2, char *s3)
{
    printf("\nString Intervew\n\n");
    int i = 0, j = 0;

    while (s1[j] != '\0' && s2[j] != '\0')
    {
        s3[i] = s1[j];
        s3[i + 1] = s2[j];
        i += 2;
        j++;
    }
    if (s1[j] == '\0' && s2[j] != '\0')
    {
        while (s2[j] != '\0')
        {
            s3[i] = s2[j];
            i++;
            j++;
        }
    }
    else if (s1[j] != '\0' && s2[j] == '\0')
    {
        while (s1[j] != '\0')
        {
            s3[i] = s1[j];
            i++;
            j++;
        }
    }
}
