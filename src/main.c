
#include <stdio.h>
#include <math.h>
#include "complex.h"

	int main (){

	int sonuc;
	struct complex c1, c2, c3;

    printf("real part");
    scanf("%f", &c1.re);
    printf("imaginary part");
    scanf("%f", &c1.im);

    printf("real part 2");
    scanf("%f", &c2.re);
    printf("imaginary part2");
    scanf("%f", &c2.im);

    print(c1,c2);
    add(c1,c2,&c3);
    substract(c1,c2, &c3);
    multiply(c1,c2,&c3);
    sonuc=length(c1);
    printf("length:%d\n\n", sonuc);
    compare(c1,c2);
    real(c1,c2);
    imaginary(c1,c2);

	return 0;
}
