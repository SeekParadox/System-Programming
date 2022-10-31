/*
 * @author Michael Waller
 * @pantherID 6366280
 *“I affirm that I wrote this program myself without any help from any other people or sources from the internet.”
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

//A method that assigns seats to customers for this flight
int main() {
	int seatsArr[12];
	int firstClass = 0;
	int economy = 4;
	int userSelection;
	
	/*assign seats based user selection. Loop ends when there are no available seats
	* or the user wants to exit the loop
	*/
	do{
		char tempSelection[50];
		int i;
		printf("Please type 1 for \"first class\"\n");
		printf("Please type 2 for \"economy\"\n");
		printf("Please type 0 to quit\n");
		scanf("%s",tempSelection);

		//checks if the user selection is an integer
		for(i = 0; i < strlen(tempSelection); i++) {
			if(isdigit(tempSelection[i]) == 0) {
				printf("usage: planeseats.c tempSelection\n");
                        	return 1;
			}
		}

		userSelection = atoi(tempSelection);

		switch(userSelection) {
			//if user enters 0 then there is nothing to be done
			case 0:
				break;
			
			case 1:
				//check if there are available seats
				if(firstClass < 4) {
					seatsArr[firstClass++] = firstClass;
					printf("Your seat for this flight\n");
					printf("First Class:	seat No. %d\n",firstClass);
				}

				/*If there are no seats for the desired section 
				we ask the user if they would not mind another section
				*/
				 else if(economy < 12) {
					bool isValid = false;
					char alt[50];			
				
					printf("Would you like to select a seat from economy? ");
					
					//loop runs until user types yes or no
					while(!isValid) {
						scanf("%s", alt);
						
						if(strcmp(alt,"yes") == 0) {
							isValid = true;
							seatsArr[economy++] = economy;
							printf("Your seat for this flight\n");
							printf("Economy:    seat No. %d\n",economy - 4);
						} else if(strcmp(alt, "no") == 0) {
							isValid = true;
							printf("The next flight will be tomorrow\n");
							userSelection = 0;
						} else {
							printf("Please type \"yes\" or \"no\"\n");
						}
					}
				}
				break;
			
			case 2:
				 //check if ther are available seats
				if(economy < 12) {
                                        seatsArr[economy++] = economy;
                                        printf("Your seat for this flight\n");
                                        printf("Economy:    seat No. %d\n",economy - 4);
                                } 
				
				/*If there are no seats for the desired section
                                we ask the user if they would not mind another section
                                */
				else if(firstClass < 4) {
                                        bool isValid = false;
                                        char alt[50];

                                        printf("Would you like to select a seat from first class? ");
					//loop runs until user types yes or no
                                        while(!isValid) {
                                                scanf("%s", alt);

                                                if(strcmp(alt,"yes") == 0) {
                                                        isValid = true;
                                                        seatsArr[firstClass++] = firstClass;
                                                        printf("Your seat for this flight\n");
                                                        printf("First Class:    seat No. %d\n", firstClass);
                                                } else if(strcmp(alt, "no") == 0) {
                                                        isValid = true;
                                                        printf("The next flight will be tomorrow\n");
                                                        userSelection = 0;
                                                } else {
                                                        printf("Please type \"yes\" or \"no\"\n");
						}
                                        }
                                }
				break;

			default:
			printf("Invalid selection. Try again\n");
			break;
		}
	}while(userSelection != 0 && firstClass + economy - 4 != 12);
	
    return 0;
}
