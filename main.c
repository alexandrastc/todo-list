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

	printf("------------------ TO-DO LIST -----------------\n");
	printf("\n\n\t1.Add new task");
	printf("\n\t2.Display all tasks");
	printf("\n\t3.Display by category");
	printf("\n\t4.Sort by priority");
	printf("\n\t5.Delete task");
	printf("\n\t6.Quit\n\n\n");

	printf("Your choice : ");
	
	int choice = getchar();

}