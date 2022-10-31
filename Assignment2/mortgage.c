/*

	@Paul Krzyzanowski -creator
	@Michael Waller - author
	Panther id - 63666280
	This programs purpose is to calculate the monthly payments of a mortgage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int debug = 0;

/*
 * This method calculates and prints the monthly payment for the house.
 * @price price of the home
 * @rate interest rate for the home
 * @term the duration of the loan
 * @downpayment downpayment amount
 * */
void calculate(int price, double  rate, int term, int downpayment) {
       double  mRate = ((rate / 100) /12.00); // monthly rate
       int boroughedAmount = price - downpayment;
       int numPayments = term * 12;
       double raisedResult = (1 / (pow(mRate+1 ,numPayments))) - 1;
       double payment = mRate /raisedResult;
      
       payment = (-1 * payment) * boroughedAmount;

       if(downpayment < (.20 * (boroughedAmount))) {
	       payment += ((.01 * boroughedAmount) / 12);
       }

       printf("The payment on a loan of $%.2lf with an interest rate of %.3lf%% for a term of %d years will be $%.2lf\n", (double)price, (double)rate,term, payment);    
}


int main(int argc, char **argv) {
	
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int  rflag = 0;
	char *rval, *dval, *sval;
	double rate;
	int term = 30, downpayment = 0, price;
	static char usage[] = "usage: %s [-s term] -r rate [-d downpayment] price\n";

	//takes in the options for building a mortgage
	while ((c = getopt(argc, argv, "s:r:d:")) != -1)
		
		switch (c) {
		//term is optional. standard is 30 years
		case 's':
			//any value will set the term to 15
			sval = optarg;
			term = 15;
			break;

		//required interest rate. Must be between 3 and 10% inclusive
		case 'r':
			rflag = 1;
			rval = optarg;

			//we check if the string can be converted into an integer
			for(int i = 0; i < strlen(rval); i++) {
				if(isalpha(rval[i])){
					printf("usage: rval\n");
                                        return 1;
                                }
                        }
			
			rate = atof(rval);

			 if(rate < 3 || rate > 10) {
				 printf("usage: rate\n");
				 return 1;
			 }

			break;

		//optional downpayment. This cannot be greater than the price of the home.
		case 'd':
			dval = optarg;
			
			//we check if the string can be converted into an integer
			for(int i = 0; i < strlen(dval); i++) {
				if(!isdigit(dval[i])){
					printf("usage: dval\n");
                                        return 1;
                                }
                        }

			 downpayment = atoi(dval);
			break;
	
		case '?':
			err = 1;
			break;
		}
	if (rflag == 0) {
		/* -r was mandatory */
		fprintf(stderr, "%s: missing -r option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);

	} else if ((optind+1) > argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing price\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	//check if error occured in the options
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}

	//check if the price of the house is an integer
	char* temp = argv[optind];
	
	/* this is the price of the house */
	for (int i = 0; i < strlen(temp); i++) {
		if(!isdigit(temp[i])) {
			printf("usuage: temp\n");
			return 1;
			}
		}
	
	price = atoi(temp);

	//check if the price of the house is a valid number
	if(price < 0) {
		printf("usuage: price\n");
		return 1;
	//check to see if downpayment amount is allowed
	} else if(downpayment > price) {
		printf("usuage: downpayment\n");
		return 1;
	}

	calculate(price, rate, term, downpayment);
	exit(0);
}
