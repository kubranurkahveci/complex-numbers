
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "complex.h"

#define LINE_SIZE (31)

	int main (int argc, char **argv)
{
    float result1;
	struct complex *c1,*c2,c3,p1,p2,p3;
	FILE *file;
	char line[LINE_SIZE];
	char *token=NULL;
	int i,ret;

	c1=&p1;
	c2=&p2;

if ((file = fopen("operation.txt","r")) == NULL) {
	printf("Failed to open file\n");
	return -1;
}
while (fgets(line, LINE_SIZE, file) != NULL) {
	token = strtok(line, " ");
	if (strcmp(token, "add") == 0) {
		for(i = 0; i < 2; ++i) {
			token = strtok(NULL, " ");
			switch (i) {
	    	case 0:
	    		sscanf(token, "%f %f",&c1->re,&c1->im);
	    		break;
	    	case 1:
	    		sscanf(token, "%f %f",&c2->re,&c2->im);
	    		break;
	        }
		}
		c3=add(c1,c2);
		printf("%.1f%+.1fj\n",c3.re,c3.im );

	} else if (strcmp(token, "substract") == 0) {
		for(i = 0; i < 2; ++i) {
			token = strtok(NULL, " ");
			if(i == 0) {
				sscanf(token, "%f %f",&c1->re,&c1->im);
	        } else if(i == 1) {
	        		sscanf(token, "%f %f",&c2->re,&c2->im);
	        }
	    }
	   c3=substract(c1,c2);
	   printf("%.1f%+.1fj\n",c3.re,c3.im );

	} else if (strcmp(token, "multiply") == 0) {
	   for(i = 0; i < 2; ++i) {
	       token = strtok(NULL, " ");

	       if(i == 0) {
	    	   sscanf(token, "%f %f",&c1->re,&c1->im);
	       } else if(i == 1) {
	        	   sscanf(token, "%f %f",&c2->re,&c2->im);
	       }
	 }
	   c3=multiply(c1,c2);
	   printf("%.1f%+.1fj\n",c3.re,c3.im);

	} else if (strcmp(token, "compare") == 0) {
	   for(i = 0; i < 2; ++i) {
	       token = strtok(NULL, " ");
	       if(i == 0) {
	           sscanf(token, "%f %f",&c1->re,&c1->im);
	       } else if(i == 1) {
	    	   sscanf(token, "%f %f",&c2->re,&c2->im);
	       }
	  }
	   ret = compare(c1,c2);
	   if (ret == 0) {
		   puts ("c1 = c2");
	   } else if (ret == 1) {
		   puts ("c1 > c2");
	   } else puts ("c1 < c2");

	} else if (strcmp(token, "print") == 0) {
	    token = strtok(NULL, " ");
	    	sscanf(token, "%f %f",&c1->re,&c1->im);
	    	print(c1);

	} else if (strcmp(token, "real") == 0) {
	    token = strtok(NULL, " ");
	   		sscanf(token, "%f %f",&c1->re,&c1->im);
	   		float re = real(c1);
	   		printf("%.1f\n", re);

	} else if (strcmp(token, "imaginary") == 0) {
	    token = strtok(NULL, " ");
	   		sscanf(token, "%f %f",&c1->re,&c1->im);
	   		float im = imaginary(c1);
	   		printf("%.1f\n", im);

	} else if (strcmp(token, "length") == 0) {
	    token = strtok(NULL, " ");
	   		sscanf(token, "%f %f",&c1->re,&c1->im);
	   		result1 = length(c1);
	   		printf("%.1f\n",result1);
	}
 }
fclose(file);
return 0;
}
