#include<stdio.h>

void russian_multiplication(unsigned int* multiplicand, unsigned int* multiplier)
{
	unsigned int remain=0;
	
	while(*multiplier!=1)
	{
		if(*multiplier%2==1)
			remain+=*multiplicand;
		
		*multiplier/=2;
		*multiplicand*=2;
	}
	
	*multiplicand+=remain;
}

void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double b0)
{
	double sixth_degree, fifth_degree, fourth_degree, third_degree, second_degree, first_degree, zero_degree;
	
	sixth_degree=(*a3)*(*b3);
	fifth_degree=(*a3)*(*b2)+(*a2)*(*b3);
	fourth_degree=(*a3)*(*b1)+(*a2)*(*b2)+(*a1)*(*b3);
	third_degree=(*a3)*b0+(*a2)*(*b1)+(*a1)*(*b2)+(*a0)*(*b3);
	second_degree=(*a2)*b0+(*a1)*(*b1)+(*a0)*(*b2);
	first_degree=(*a1)*b0+(*a0)*(*b1);
	zero_degree=(*a0)*b0;
	
	*a3=sixth_degree;
	*a2=fifth_degree;
	*a1=fourth_degree;
	*a0=third_degree;
	*b3=second_degree;
	*b2=first_degree;
	*b1=zero_degree;
}

int main()
{
	/* Russian Peasant Multiplication */
	
	unsigned int multiplicand, multiplier;
	double a3, a2, a1, a0, b3, b2, b1, b0;
	
	printf("Input the multiplicand: ");
	scanf("%u", &multiplicand);
	
	printf("Input the multiplier: ");
	scanf("%u", &multiplier);
	
	russian_multiplication(&multiplicand, &multiplier);
	
	printf("Product: %u\n", multiplicand);
	printf("Multiplier: %u\n\n", multiplier);
	
	

/*###########################################################################
																			#
																			#
#############################################################################
*/	

	/* Multiplication of Polynomials */
	
	printf("Input the first polynomial coefficients: ");
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	printf("Input the second polynomial coefficients: ");
	scanf("%lf %lf %lf %lf", &b3, &b2, &b1, &b0);
	
	multiply_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, b0);
	
	printf("Product: ");
	
	if(a3!=0.0)
		printf("%+lfx^6 ", a3);
	
	if(a2!=0.0)
		printf("%+lfx^5 ", a2);
		
	if(a1!=0.0)
		printf("%+lfx^4 ", a1);
		
	if(a0!=0.0)
		printf("%+lfx^3 ", a0);
		
	if(b3!=0.0)
		printf("%+lfx^2 ", b3);
		
	if(b2!=0.0)
		printf("%+lfx ", b2);
		
	if(b1!=0.0)
		printf("%+lf\n", b1);
		
	return 0;
}
