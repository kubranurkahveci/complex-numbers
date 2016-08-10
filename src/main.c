
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "complex.h"

#define LINE_SIZE1 (31)
#define LINE_SIZE2 (30)

	int main (int argc, char **argv)
{
	struct complex c1, c2, c3, c4;
	FILE *file_operation, *file_result;
	char line1[LINE_SIZE1];
	char line2[LINE_SIZE2];
	char *token = NULL;
	int i, ret, d;
	float im, re, k, result1;

if ((file_operation = fopen("operation.txt","r")) == NULL) {
	printf("Failed to open file\n");
	return -1;
}
if ((file_result = fopen ("result.txt","r")) == NULL ) {
	printf("Failed to open file\n");
	return -1;
}
while (fgets(line1, LINE_SIZE1, file_operation) != NULL) {
	token = strtok(line1, " ");
	if (strcmp(token, "add") == 0) {
		for(i = 0; i < 2; ++i) {
			token = strtok(NULL, " ");
			switch (i) {
	    	case 0:
	    		sscanf(token, "%f%fj",&c1.re,&c1.im);
	    		break;
	    	case 1:
	    		sscanf(token, "%f%fj",&c2.re,&c2.im);
	    		break;
	        }
		}
		c3=add(&c1, &c2);
		if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
			sscanf (line2, "%f%fj", &c4.re, &c4.im);
			if (compare(&c3, &c4) == 0) {
				puts ("PASS");
			} else {
				printf("%.1f%+.1fj != %.1f%+.1fj\n",c3.re,c3.im, c4.re, c4.im);
				puts ("FAIL!");
				break;
			}
		}
	} else if (strcmp(token, "substract") == 0) {
		for(i = 0; i < 2; ++i) {
			token = strtok(NULL, " ");
			if(i == 0) {
				sscanf(token, "%f%fj", &c1.re, &c1.im);
	        } else if(i == 1) {
	        	sscanf(token, "%f%fj", &c2.re, &c2.im);
	        }
	    }
	   c3 = substract(&c1, &c2);
	   if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
		   sscanf (line2, "%f%fj", &c4.re, &c4.im);
		   if (compare(&c3, &c4) == 0) {
			   puts ("PASS");
		   } else {
			   printf("%.1f%+.1fj != %.1f%+.1fj\n", c3.re, c3.im, c4.re, c4.im);
			   puts ("FAIL!");
			   break;
		   }
	   }
	} else if (strcmp(token, "multiply") == 0) {
	   for(i = 0; i < 2; ++i) {
	       token = strtok(NULL, " ");
	       if(i == 0) {
	    	   sscanf(token, "%f%fj",&c1.re, &c1.im);
	       } else if(i == 1) {
	    	   sscanf(token, "%f%fj",&c2.re, &c2.im);
	       }
	 }
	   c3 = multiply(&c1, &c2);
	   if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
		   sscanf (line2, "%f%fj", &c4.re, &c4.im);
		   if (compare(&c3, &c4) == 0) {
			   puts ("PASS");
		   } else {
			   printf("%.1f%+.1fj != %.1f%+.1fj\n", c3.re, c3.im, c4.re, c4.im);
			   puts ("FAIL!");
			   break;
		   }
	   }
	} else if (strcmp(token, "compare") == 0) {
	   for(i = 0; i < 2; ++i) {
	       token = strtok(NULL, " ");
	       if(i == 0) {
	           sscanf(token, "%f%fj",&c1.re,&c1.im);
	       } else if(i == 1) {
	    	   sscanf(token, "%f%fj",&c2.re,&c2.im);
	       }
	  }
	   ret = compare(&c1, &c2);

	   if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
		   sscanf (line2, "%d", &d);
		   if (ret == d) {
			   puts ("PASS");
		   } else {
			   printf("%d != %d\n",ret, d);
			   puts ("FAIL!");
			   break;
		   }
	   }
	} else if (strcmp(token, "real") == 0) {
	    token = strtok(NULL, " ");
	   	sscanf(token, "%f%fj",&c1.re,&c1.im);
	   	float re = real(&c1);

	   	if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
	   		sscanf (line2, "%f", &k);
	   		if (compare_float(re, k) == 1) {
	   			puts ("PASS");
	   		} else {
	   			printf("%f != %f\n",re, k);
	   			puts ("FAIL!");
	   			break;
	   		}
	   	}
	} else if (strcmp(token, "imaginary") == 0) {
	    token = strtok(NULL, " ");
	   	sscanf(token, "%f%fj",&c1.re, &c1.im);
	   	float im = imaginary(&c1);

	   	if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
	   		sscanf (line2, "%f", &k);
	   		if (compare_float(im, k) == 1) {
	   			puts ("PASS");
	   		} else {
	   			printf("%f != %f\n",im, k);
	   			puts ("FAIL!");
	   			break;
	   		}
	   	}
	} else if (strcmp(token, "length") == 0) {
		token = strtok(NULL, " ");
		sscanf(token, "%f%fj",&c1.re, &c1.im);
		result1 = length(&c1);

		if (fgets(line2, LINE_SIZE2, file_result) != NULL) {
			sscanf (line2, "%f", &k);
			if (compare_float(result1, k) == 1) {
				puts ("PASS");
			} else {
				printf("%f != %f\n",result1, k);
				puts ("FAIL!");
				break;
	   		}
		}
	}
}
fclose(file_operation);
fclose(file_result);
return 0;
}
