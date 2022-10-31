#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

/**
 * Purpose/Description: A class for creating a linkedList from a text file. The list is either printed to console or to an output file.
 *           Author's Panther ID:  6366280
 *           Certification:
 *   I hereby certify that this work is my own and none of it is the work of
 *   any other person.
 */

/**
 * A struct for a Node
 * @member letter - points to the character value of the node
 * @member next - points to the next node
 * @member prev - points to the previous node
 *
 */
typedef struct Node_struct
{
	char letter;
	struct Node_struct *next;
	struct Node_struct *prev;

} Node;

/**
 * A function for creating a new node
 * @param toInsert - takes in char for the nodes character value
 * @return - new Node
 */
Node *createNode(char toInsert)
{
	Node *aNode = (Node *)malloc(sizeof(Node)); // dynamic allocation of Node
	aNode->letter = toInsert;
	aNode->next = NULL;
	aNode->prev = NULL;
	return aNode;
}

/**
 * A function for inserting a Node by alphabetic value
 * @param **headp - takes in the address pointer to the head Node of the list
 * @param *head - takes in the pointer to the current head Node
 * @param charr - takes in the letter to be compared and added to a new Node
 */
void insert(Node **headp, Node *head, char charr)
{
	// checks if the new character is smaller than the head of the list character
	if (charr < head->letter && charr != head->letter)
	{
		Node *temp = createNode(charr);
		temp->next = head; // makes the new Node's next pointer point to the current head of the list
		head->prev = temp; // makes the head's previous node the new Node
		*headp = temp;	   // assigns temp as the new head node
		return;
	}
	Node *temp = head;

	while (temp != NULL)
	{ // loop continues until conditon is met or node is placed in the list
		// checks for duplicates
		if (temp->letter == charr)
			return;

		// checks the character is less than the current Node in the loop we create and place a new node before it
		if (charr < temp->letter)
		{
			Node *aNode = createNode(charr);
			temp->prev->next = aNode; // assigns the current Node's previous reference to next Node with our new node
			aNode->prev = temp->prev; // assigns the new Node's previous reference with the current Node's previous Node
			temp->prev = aNode;		  // assigns the current Node's previous reference with the new Node
			aNode->next = temp;		  // assigns the new Node's next reference to the current Node
			return;
		}

		// checks if the next node in the list exist
		if (temp->next == NULL)
		{
			Node *aNode = createNode(charr);
			temp->next = aNode; // adds new node to the tail of the list
			aNode->prev = temp; // assigns the tail Node's previous reference to previous tail
			return;
		}

		temp = temp->next;
	}
}

/**
 * A function for writing characters to an output file
 * @param *fileName - takes in the name of file to be written too
 * @param *currentNode - takes in the pointer to the current head
 * @return true upon successful creation and writting to the file | false upon file not opening
 */

bool writeToFile(char *fileName, Node *currentNode)
{
	FILE *fileOutput = NULL;
	fileOutput = fopen(fileName, "w"); // opens file for writing

	if (fileOutput == NULL)
	{
		return false; // file unsuccessfully opened because of null pointer
	}

	Node *temp = currentNode;

	while (temp != NULL)
	{									// loops until nodes are completely populated into the ouput file
		putc(temp->letter, fileOutput); // puts single characters into the file
		temp = temp->next;
	}

	fclose(fileOutput);

	return true;
}

/**
 * A function for printing out Node's to the stdout
 * @param *printNode - takes in the pointer to the current head
 */

void printList(Node *printNode)
{
	Node *temp = NULL;
	temp = printNode;

	while (temp != NULL)
	{
		printf("%c", temp->letter); // prints character by character to the stdout
		temp = temp->next;
	}

	printf("\n");
}

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0, n = 27, oflag = 0;
	char *oVal;
	char current;
	static char usage[] = "usage: %s  [-o output_file_name] input_file_name";
	FILE *file = NULL;
	Node *head = NULL;

	while ((c = getopt(argc, argv, "o:")) != -1) //gets the arguments from the command line

		switch (c)
		{
		// optional file name
		case 'o':
			oflag = 1;
			oVal = optarg; // stores the argument as a filename
			break;

		case '?':
			err = 1;
			break;
		}

	if ((optind + 1) > argc)
	{
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: input_file_name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
		// check if error occured in the options
	}
	else if (err)
	{
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}

	file = fopen(argv[argc - 1], "r");

	if (file == NULL)
	{							 // checks if file is has a null pointer
		printf("usage: file: %s\n",argv[argc - 1]); // prints out the usaage statement
		return 1;
	}

	do
	{
		current = fgetc(file); // gets current char value in the file
		if (feof(file))
			break;
		if (isalpha(current))
		{
			current = toupper(current); // converts characters to uppercase

			if (head == NULL)
			{ // if null exist in the list one is created
				head = createNode(toupper(current));
			}
			else
				insert(&head, head, toupper(current));
		}

	} while (1);

	fclose(file);

	if (oflag == 1)
	{ // checks if file name was given
		// tries to write to the file, if the file name is null the values are printed instead
		if (!writeToFile(oVal, head))
			printList(head);
	}
	else
		printList(head); // no output file name was given, print to the stdout

	while (head->next != NULL)
	{ // free's all nodes in the list
		head = head->next;
		free(head->prev);
	}

	free(head);
	head = NULL;

	return 0;
}
