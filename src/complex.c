#include <stdio.h>
#include <math.h>
#include "complex.h"

#define EPSILON (0.1F)

struct complex add (struct complex *c1, struct complex *c2)
{
	struct complex c3;
	c3.re = c1->re + c2->re;
	c3.im = c1->im + c2->im;
    return c3;
}
struct complex substract (struct complex *c1, struct complex *c2)
{
	 struct complex c3;
	 c3.re = c1->re - c2->re;
	 c3.im = c1->im - c2->im;
	 return c3;
}
void print (struct complex *c1)
{
	 //printf("%.1f%+.1fj\n",c1->re, c1->im);
}
struct complex multiply (struct complex *c1, struct complex *c2)
{
	 struct complex c3;
     c3.re = c1->re * c2->re - c1->im * c2->im;
     c3.im = c1->re * c2->im + c1->im * c2->re;
     return c3;
}
float length (struct complex *c1)
{
	 float i,length;
	 i = (c1->re * c1->re) + (c1->im * c1->im);
	 length = sqrt(i);
	 return length;
}

int compare_float(float x, float y)
{
	if (fabs(x - y) <= EPSILON ) {
		return 1;
	}
	return 0;
}

int compare (struct complex *c1, struct complex *c2)
{
	int ret = 0;
	if (compare_float(c1->re, c2->re) && compare_float(c1->im, c2->im)) {
		ret = 0;
	} else if (length(c1) > length(c2)) {
		ret = 1;
	} else {
		ret = -1;
	}
	return ret;
}
float real (struct complex *c1)
{
	 float re = c1->re;
	 return re;
}
float imaginary (struct complex *c1)
{
	 float im = c1->im;
 	 return im;
}

