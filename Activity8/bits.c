#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
uint32_t userInput;
int shiftSide;
int amount;

printf("Please type an unsigned integer:");
scanf("%d",&userInput);

printf("Enter [0] to shift left. Enter [1] to shift right :");
scanf("%d",&shiftSide);
printf("How many bits to shift the integer? ");
scanf("%d",&amount);

if(shiftSide == 0) {
	userInput = userInput << amount;
} else {
	userInput = userInput >> amount;

}

printf("Result: %d\n", userInput);








return 0;
}
