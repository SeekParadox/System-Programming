/*
	example of command line parsing via getopt
	usage: activity [-r] -b bval value [value...]

	Paul Krzyzanowski
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int debug = 0;

int main(int argc, char **argv) {
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int rflag=0, bflag = 0;
	char *bval;
	static char usage[] = "usage: %s [-r] -b bval value [value...]\n";

	while ((c = getopt(argc, argv, "rb:")) != -1)
		switch (c) {
		case 'r':
			rflag = 1;
			break;
		case 'b':
			bflag = 1;
			bval = optarg;
			break;
		case '?':
			err = 1;
			break;
		}
	if (bflag == 0) {	/* -b was mandatory */
		fprintf(stderr, "%s: missing -b bval val\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if ((optind+1) > argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */

		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing value\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	/* see what we have */
	//printf("debug = %d\n", debug);
	//printf("rflag = %d\n", rflag);
	//printf("bflag = %d\n", bflag);
	//printf("bval = \"%s\"\n", bval);
	//printf("value = \"%s\"\n", argv[optind]);
	printf("Total = %d\n", atoi(bval) + atoi(argv[optind]));
	
	//if (optind < argc)	/* these are the arguments after the command-line options */
		//for (; optind < argc; optind++)
			//printf("argument: \"%s\"\n", argv[optind]);
	//else {
		//printf("no arguments left to process\n");
	//}
	exit(0);
}
