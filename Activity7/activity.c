#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {

char *letterE;
int *singleInt;
int *numArr;
char *lName;
float *aFloat;
singleInt = (int*) malloc(sizeof(int));
letterE = (char*) malloc(sizeof(char));
numArr = (int*) calloc(10, sizeof(int));
lName = (char *) malloc(6* sizeof(char));
aFloat = (float*) malloc( sizeof(float));

*letterE = 'E';
*singleInt = 25;
strcpy(lName, "Waller");
*aFloat = 32.76;

printf("Character: %c\n",*letterE);
free(letterE);
printf("Integer: %d\n", *singleInt);
free(singleInt);
printf("String: %s\n", lName);
free(lName);
printf("Floating Point: %.2f\n", *aFloat);
free(aFloat);
printf("Array of Integers: ");

for(int i = 0; i < 10; i++) {
	numArr[i] = i;
}

for(int i = 0; i < 10; i++) {
	printf("%d ", numArr[i]);
}

printf("\n");

free(numArr);
return 0;
}
