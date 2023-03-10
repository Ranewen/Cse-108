#include <stdio.h>
#include <math.h>
#define PI 3.14

int rectangle_area(int length, int breadth){
	return length * breadth;
}

int rectangle_perimeter(int length, int breadth){
	return 2*(length+breadth);
}

void rectangle_calculator(){
	int length, breadth, area,perimeter;
 
   	printf("\nEnter the Length of Rectangle : ");
	scanf("%d", &length);
 
   	printf("\nEnter the Breadth of Rectangle : ");
   	scanf("%d", &breadth);
 
   	area = rectangle_area(length,breadth);
   
   	perimeter = rectangle_perimeter(length,breadth);

   	printf("\nArea of Rectangle : %d", area);
   	printf("\nPerimeter of Rectangle : %d", perimeter);
   
   return;
}

float triangle_area(int a, int b, int c){
	float s;
	s = (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

float triangle_perimeter(int a, int b, int c){
	return a+b+c;
}

void triangle_calculator(){
	float a, b, c, Perimeter, s, Area;
  
  	printf("\nPlease Enter three sides of triangle\n");
  	scanf("%f%f%f",&a,&b,&c);
   
  	Perimeter = triangle_perimeter(a,b,c);
  	
  	Area = triangle_area(a,b,c);
   
 	printf("\n Perimeter of Triangle = %.2f\n", Perimeter);
 	printf("\n Area of triangle = %.2f\n",Area);
 	
 	return;
}

double circle_area(double radius){
	return radius * radius * PI;
}

double circle_perimeter(double radius){
	return 2 * PI * radius;
}

void circle_calculator(){
	double radius;
    printf("\nPlease enter the radius of the circle:\n");
    scanf("%lf",&radius);
    printf("\nThe area of the circle = %.2lf\n", circle_area(radius));
    printf("\nThe perimeter of the circle = %.2lf\n", circle_perimeter(radius));
    
    return;
}

float calculate_kelvin(float F){
	float K;
	K = ((5.0 / 9.0) * (F - 32.0)) + 273.15;
	return K;
}

void fahrenheit_to_kelvin(){
	float input,output;
	printf("\nPlease enter the temperature in Fahrenheit:\n");
	scanf("%f", &input);
	output = calculate_kelvin(input);
	printf("\nResult = %f\n", output);
}

float calculate_fahrenheit(float K){
	float F;
	F = (9.0 / 5.0 ) * (K - 273.15) + 32.0;
	return F;
}

void kelvin_to_fahrenheit(){
	float input,output;
	printf("\nPlease enter the temperature in Kelvin:\n");
	scanf("%f", &input);
	output = calculate_fahrenheit(input);
	printf("\nResult = %f\n", output);
}

int multiple_int(int a, int b){
	return a*b;
}

int sum_int(int a, int b){
	return a+b;
}

void integer_number(){
	int selection,number1,number2;
	
	printf("Enter the calculation type; \n ");
	printf("1. Addition \n ");
	printf("2. Multiplication \n ");
	printf("--------------------------- \n ");
    scanf("%d",&selection);
    printf("Enter the numbers \nnumber1: ");
    scanf("%d",&number1);
    printf("number2: ");
    scanf("%d",&number2);
    
    if(selection == 1){
    	printf("Result = %d\n", sum_int(number1,number2));
	}
	else if(selection == 2){
		printf("Result = %d\n", multiple_int(number1,number2));
	}
	else {
		printf("Please enter correct input");
	}
	return;
}

int sum_i(int i1, int i2){
	return i1+i2;
}

int sum_r(int r1, int r2){
    return r1+r2;
}

int multiple_i(int r1, int r2, int i1, int i2){
	return (r1*i2)+(r2*i1);
}

int multiple_r(int r1, int r2, int i1, int i2){
    return (r1*r2)+((i1*i2)*-1);
}

void complex_number(){
	int selection,r1, r2, i1, i2;
    int _sum_r,_sum_i, multi_r, multi_i;
    
	printf("Enter the calculation type \n ");
	printf("1. Addition \n ");
	printf("2. Multiplication \n ");
	printf("-------------------------- \n ");
    scanf("%d",&selection);
    
    printf("Please enter the first complex number (real part first):\n");
    scanf("%d %d",&r1,&i1);
    printf("Please enter the second complex number (real part first):\n");
    scanf("%d %d",&r2,&i2);
    
    if(selection == 1){
    	_sum_r = sum_r(r1,r2);
    	_sum_i = sum_i(i1,i2);
    	printf("Sum of the numbers = %d + (%di)\n",_sum_r,_sum_i);
	}
	else if(selection == 2){
		multi_r = multiple_r(r1,r2,i1,i2);
    	multi_i = multiple_i(r1,r2,i1,i2);
    	
    	printf("Multiplication of the numbers = %d + (%di)\n",multi_r,multi_i);
	}
	else {
		printf("Please enter correct input");
	}
	return;
}

void standart_calculator(){
	int selection;
    printf("Enter the number type \n ");
	printf("1. Integer \n ");
	printf("2. Complex \n ");
	printf("--------------------- \n ");
    scanf("%d",&selection);
    
    if(selection == 1){
    	integer_number();
	}
	else if(selection == 2){
		complex_number();
	}
    return;
}

void area_perimeter_calculator(){
    int selection;
    printf("Enter the shape type \n ");
	printf("1. Rectangle \n ");
	printf("2. Triangle \n ");
	printf("3. Circle \n ");
	printf("--------------------- \n ");
    scanf("%d",&selection);
    
    if(selection == 1){
    	rectangle_calculator();
	}
	else if(selection == 2){
		triangle_calculator();
	}
	else if(selection == 3){
		circle_calculator();
	}
	else{
		printf("Please enter correct input");
	}
    return;
}

void temperature_calculator(){	
	int selection;
    printf("Enter the calculation type \n ");
	printf("1. Fahrenheit to Kelvin \n ");
	printf("2. Kelvin to Fahrenheit \n ");
	printf("-------------------------- \n ");
    scanf("%d",&selection);
    if(selection == 1){
    	fahrenheit_to_kelvin();
	}
	else if(selection == 2){
		kelvin_to_fahrenheit();
	}
	else{
		printf("Please enter correct input");
	}
    return;
}

int main(){
    int selection;
    
    //Temperature, Area&Perimeter and Standart Calculator
    
    printf("Enter the calculator type \n ");
	printf("1. Standart Calculator \n ");
	printf("2. Area&Perimeter Calculator \n ");
	printf("3. Temperature Calculator \n ");
	printf("------------------------- \n ");
    scanf("%d",&selection);
    if(selection == 1){
    	standart_calculator();
	}
	else if(selection == 2){
		area_perimeter_calculator();
	}
	else if(selection == 3){
		temperature_calculator();
	}
	else{
		printf("Please enter correct input");
	}
    
    return 0;
}


