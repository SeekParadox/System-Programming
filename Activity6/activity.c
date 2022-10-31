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
	char* name = "Michael";
	int fflag = 0;
	FILE* spData = NULL;
	char *fval;
	static char usage[] = "usage: %s writer [-f filename]\n";

	while ((c = getopt(argc, argv, "f:")) != -1)
		switch (c) {

		case 'f':
			fflag = 1;
			fval = optarg;
			break;
		case '?':
			err = 1;
			break;
		}
	
	if (err) {
                fprintf(stderr, usage, argv[0]);
                exit(1);
        }
	
	if (fflag == 0) {	/* -f was optional */
		printf("%s\n",name);
		return 1;

	}
	spData = fopen(fval, "w");
	if(spData == NULL) {
		printf("%s\n", usage);
	}
	
		//spData = fopen(fval, "w");
		fprintf(spData, name);
	if(fclose(spData) == EOF) {
		printf("\aERROR closing temps\n");
		exit(102);

	}
	
	exit(0);
}
