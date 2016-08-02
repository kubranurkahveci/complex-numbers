#ifndef COMPLEX_H_
#define COMPLEX_H_


 struct complex {
	float re;
	float im;
};

void add (struct complex c1, struct complex c2,struct complex *c3);
void substract (struct complex c1, struct complex c2,struct complex *c3);
void print (struct complex c1, struct complex c2);
void multiply (struct complex c1, struct complex c2, struct complex *c3);
int length (struct complex c1);
void compare (struct complex c1, struct complex c2);
void real (struct complex c1, struct complex c2);
void imaginary (struct complex c1, struct complex c2);




#endif /* COMPLEX_H_ */
