#ifndef COMPLEX_H_
#define COMPLEX_H_

struct complex {
	float re;
	float im;
};

struct complex add (struct complex *c1, struct complex *c2);
struct complex substract (struct complex *c1, struct complex *c2);
void print (struct complex *c1);
struct complex multiply (struct complex *c1, struct complex *c2);
float length (struct complex *c1);
int compare (struct complex *c1, struct complex *c2);
float real (struct complex *c1);
float imaginary (struct complex *c1);

#endif /* COMPLEX_H_ */
