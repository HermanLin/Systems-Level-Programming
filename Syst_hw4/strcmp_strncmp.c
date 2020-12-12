#include <stdio.h>
#include <stdlib.h>

/*=====================================================================
strcmp
compares the string pointed to by str1 to the string pointed to by str2
pre: takes two constant char pointers (immutable)
post: returns 0 if both char pointers are equals
	  less than 0 if str1 is less than str2
	  greater than 0 if str1 is greater than str2
=====================================================================*/

/*=======================================================================================
strncmp
compares at most the first n bytes of str1 and str2, stops comparing after the null char.
pre: takes two constant char pointers (immutable) and a size
post: returns 0 if the first n bytes (or null terminated len) of str1 and str2 are equals
	  less than 0 if str1 is less than str2
	  greater than 0 if str1 is greater than str2
=======================================================================================*/

//main function
int main() {
	printf("testing strcmp\n");
	printf("\tstrcmp('hello', 'hello') = %d\n", strcmp("hello", "hello"));
	printf("\tstrcmp('hi', 'ho') = %d\n", strcmp("hi", "ho"));
	printf("\tstrcmp('stuyvesant', 'bronxsci') = %d\n", strcmp("stuyvesant", "bronxsci"));
	printf("\tstrcmp('herman', 'namreh') = %d\n", strcmp("herman", "namreh"));
	
	printf("testing strncmp\n");
	printf("\tstrncmp('goodbye', 'goodbye', 3) = %d\n", strncmp("goodbye", "goodbye", 3));
	printf("\tstrncmp('apple', 'orange', 1) = %d\n", strncmp("apple", "orange", 1));
	printf("\tstrncmp('cookies', 'biscuits', 5) = %d\n", strncmp("cookies", "biscuits", 5));
	printf("\tstrncmp('z', 'a', 1) = %d\n", strncmp("z", "a", 1));
	printf("\tstrncmp('z', 'a', 10) = %d", strncmp("z", "a", 10));
}