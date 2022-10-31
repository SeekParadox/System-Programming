#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

	char charVar;
	char *pcharVar;
	int intVar;
	int *pintVar;
	char stringVar[100];
	char *pstringVar;
	double floatVar;
	double *pfloatVar;

	printf("Enter a single character: ");
	scanf("%c", &charVar);
	pcharVar = &charVar;

	printf("Enter an integer: ");
	scanf("%d", &intVar);
	pintVar = &intVar;

	printf("Enter a string: ");
	scanf("%s", stringVar);
	pstringVar = stringVar;

	printf("Enter a floating point number: ");
	scanf("%lf", &floatVar);
	pfloatVar = &floatVar;

	printf("Character: %c\n", charVar);
	printf("Integer: %d\n", intVar);
	printf("String: %s\n", stringVar);
	printf("Floating Point: %.1lf\n", floatVar);

	printf("Character Pointer: %p\n", pcharVar);
	printf("Integer Pointer: %p\n", pintVar);
	printf("String Pointer: %p\n", pstringVar);
	printf("Floating Point Pointer: %p\n", pfloatVar);
	return 0;
}
