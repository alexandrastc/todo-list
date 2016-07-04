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

	while (choice != '8' ){
	
		switch (choice){
			
			case '1':
					 add_tasks(head);
					 printf("Task added.\n");
				break;
			
			case '2':
					 print_all(head);
				break;
			
			case '3':
					 print_by_categ(head);
					 printf("Done. \n");
					 menu();
					 printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '4':
					merge_sort(&head);
					printf("All sorted.\n");
				break;
			
			case '5':
					delete_task(head);
					printf("Task deleted. \n");
					menu();
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '6': 	
					modify_categ(head);
					printf("Category modified. \n");
					menu();
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '7': 
					delete_categ(head);
					printf("Category deleted. \n");
					menu();
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '8': break;
				break;

			default: 
				printf("\nPlease enter your choice (1 to 8).\n");
		}
		
		choice = getchar();
		
		if (choice != '8'){
		
			menu();
		
		}
	}

	return 0;

}