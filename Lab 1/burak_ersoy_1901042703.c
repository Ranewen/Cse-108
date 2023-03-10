#include <stdio.h>


void trigonometry_calculation(int a, int b, int c)
{
	//converting at least one of the integers to float, otherwise the result will be 0
    printf("Sin = %f\n", (a*1.0)/c);
    printf("Cos = %f\n", (b*1.0)/c);
    printf("Tan = %f\n", (a*1.0)/b);
    
    return;
}


void trigonometry(int a, int b, int c)
{
    trigonometry_calculation(a,b,c);
    
    return;
}


unsigned long age_calculation(int x)
{
	//the output will be larger than the "int", so unsigned long or something else should be used
	//no need to define a variable of a type of unsigned long, it will be done by the compiler because the function's type is unsigned long
    return x*365*24*60*60;
}


void age(int x)
{
    unsigned long seconds = age_calculation(x);
    printf("You are %lu seconds old.", seconds);
    
    return;
}

int main()
{
    int a, b, c, x;
    
    //triangle
    printf("Enter the sides of the triangle\na: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("c: ");
    scanf("%d",&c);
    trigonometry(a,b,c);
    
    //age
    printf("Enter your age: ");
    scanf("%d",&x);
    age(x);
    
    return 0;
}

