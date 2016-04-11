#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "display.h"


int main()
{
	//start node is created

	NODE *head = NULL;

	//allocating memory for it

	head = (NODE*) malloc(sizeof(NODE));

	//"menu" displaying user's options, takes no input

	menu();
	
	int choice = getchar();

	while (choice != '6'){
	
		switch (choice){
			case '1':add_task(head,1,"Wubba","Lubba Dub Dub");
					 printf("Task added.\n");
				break;
			case '2':print_all(head);
				break;
			case '3':;
				break;
			case '4':;
				break;
			case '5':;
				break;
			case '6': break;
				break;
			default: 
				printf("\nPlease enter your choice (1 to 6).\n");
		}
		
		choice = getchar();
		
		if (choice != '6'){
		
			menu();
		
		}
	}

	return 0;

}