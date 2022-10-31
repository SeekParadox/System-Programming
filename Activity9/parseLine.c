#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

char *ourString;
char *token;

printf("Please enter a string ::");
fgets(ourString, 100, stdin);

token = strtok(ourString, " ");

while(token != NULL) {
	printf("%s\n",token);
	token = strtok(NULL, " ");
}





return 0;
}
