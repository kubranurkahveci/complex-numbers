
#include <stdio.h>
#include <math.h>
#include "complex.h"

	int main (){

	int result1,result2;
	struct complex *c1,*c2,p1,p2;

	c1=&p1;
	c2=&p2;

    printf("real part");
    scanf("%f",&c1->re);
    printf("imaginary part");
    scanf("%f",&c1->im);

    printf("real part 2");
    scanf("%f",&c2->re);
    printf("imaginary part2");
    scanf("%f",&c2->im);

    print(c1,c2);
    add(c1,c2);
    substract(c1,c2);
    multiply(c1,c2);
    result1=length(c1);
    printf("length c1: %d\n\n",result1);
    result2=length(c2);
    printf("length c2: %d\n\n",result2);
    compare(c1,c2);
    real(c1,c2);
    imaginary(c1,c2);

	return 0;
}
