#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "display.h"

typedef struct NOD{
	
	int priority;
	char* category;
	char* task; 
	struct NOD *next;

} NODE;

int main()
{
	//start node is created

	NODE *head = NULL;

	//allocating memory for it

	head = (NODE*) malloc(sizeof(NODE));

	//"menu" displaying user's options

	menu();
	
	int choice = getchar();

}