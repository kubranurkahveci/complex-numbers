#include <stdio.h>
#include <math.h>
#include "complex.h"

 void add (struct complex c1, struct complex c2,struct complex *c3)
{
	c3->re=c1.re+c2.re;
	c3->im=c1.im+c2.im;
	printf("addition  \n");
	printf("%.1f%+.1fj\n\n", c3->re, c3->im);
}
 void substract (struct complex c1, struct complex c2, struct complex *c3)
{
	 c3->re=c1.re-c2.re;
	 c3->im=c1.im-c2.im;
	 printf("substract  \n");
	 printf("%.1f%+.1fj\n\n", c3->re, c3->im);
}
 void print (struct complex c1, struct complex c2)
{
	 printf("%.1f%+.1fj\n", c1.re, c1.im);
	 printf("%.1f%+.1fj\n\n", c2.re, c2.im);
}
 void multiply (struct complex c1, struct complex c2, struct complex *c3)
{
     c3->re=c1.re*c2.re-c1.im*c2.im;
     c3->im=c1.re*c2.im+c1.im*c2.re;
     printf("multiply  \n");
	 printf("%.1f%+.1fj\n\n", c3->re, c3->im);
}

 int length (struct complex c1)
{
	 int i,length;
	 i=(c1.re*c1.re)+(c1.im*c1.im);
	 length=sqrt(i);
	 return length;
}

 void compare (struct complex c1, struct complex c2)

{
	if(c1.re==c2.re && c1.im==c2.im)
	{printf("c1==c2\n\n");
	}
	if(length(c1)>length(c2))
	{printf("c1>c2\n\n");
	}
	else
	{printf("c1<c2\n\n");
	}
}
 void real (struct complex c1, struct complex c2)
{
	 printf("%.1f\n",c1.re);
	 printf("%.1f\n\n",c2.re);
}
 void imaginary (struct complex c1, struct complex c2)
 {
 	 printf("%.1f\n",c1.im);
 	 printf("%.1f\n",c2.im);
 }

