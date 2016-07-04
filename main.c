/**
* \file
* \brief Main function
* \return An integer 0 upon exit succes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "display.h"


int main()
{
	/**
	* Start node is created
	*/

	NODE *head = NULL;

	/**
	* Allocating memory for it
	*/

	head = (NODE*) malloc(sizeof(NODE));

	/**
	* Prints menu.
	*/
	menu();
	
	/** 
	* User makes a choice.
	*/
	int choice = getchar();

	while (choice != '8' ){
	
		switch (choice){
			
			case '1':
					 add_tasks(head);
					 printf("Task added.\n");
					 printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '2':
					 print_all(head);
					 printf("Done.\n");
					 printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '3':
					 print_by_categ(head);
					 printf("Done.\n");
					 printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '4':
					merge_sort(&head);
					printf("All sorted.\n");
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '5':
					delete_task(head);
					printf("Task deleted. \n");
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '6': 	
					modify_categ(head);
					printf("Category modified. \n");
					printf("\nPlease enter your choice (1 to 8).\n");
				break;
			
			case '7': 
					delete_categ(head);
					printf("Category deleted. \n");
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
