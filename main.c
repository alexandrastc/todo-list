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

<<<<<<< .merge_file_X4wsJC
<<<<<<< .merge_file_HN3HQm
<<<<<<< .merge_file_ejtz0F
<<<<<<< .merge_file_HznnHP
	while (choice != '9'){
	
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
			case '7': break;
				break;
			case '8': break;
				break;
			case '9': break;
				break;
			default: 
				printf("\nPlease enter your choice (1 to 9).\n");
=======
=======
>>>>>>> .merge_file_wU4R9F
=======
>>>>>>> .merge_file_SYzCtl
=======
>>>>>>> .merge_file_YGxxRC
	while (choice != '8' ){
	
		switch (choice){
			
			case '1':
					 add_task(head,1,"wubba","lubba dub dub");
					 add_task(head,2,"i need","a break");
					 add_task(head,3,":(","ughhh");
					 printf("Task added.\n");
				break;
			
			case '2':
					 print_all(head);
				break;
			
			case '3':
					 print_by_categ(head,"wubba");
				break;
			
			case '4':
					MergeSort(&head);
					printf("All sorted.\n");
				break;
			
			case '5':
					delete_task(head,"a break");
					printf("Task deleted. \n");
				break;
			
			case '6': break;
				break;
			
			case '7': break;
				break;
			
			case '8': break;
				break;

			default: 
				printf("\nPlease enter your choice (1 to 8).\n");
<<<<<<< .merge_file_X4wsJC
<<<<<<< .merge_file_HN3HQm
<<<<<<< .merge_file_ejtz0F
>>>>>>> .merge_file_EbTJrP
=======
>>>>>>> .merge_file_wU4R9F
=======
>>>>>>> .merge_file_SYzCtl
=======
>>>>>>> .merge_file_YGxxRC
		}
		
		choice = getchar();
		
<<<<<<< .merge_file_X4wsJC
<<<<<<< .merge_file_HN3HQm
<<<<<<< .merge_file_ejtz0F
<<<<<<< .merge_file_HznnHP
		if (choice != '9'){
=======
		if (choice != '8'){
>>>>>>> .merge_file_EbTJrP
=======
		if (choice != '8'){
>>>>>>> .merge_file_wU4R9F
=======
		if (choice != '8'){
>>>>>>> .merge_file_SYzCtl
=======
		if (choice != '8'){
>>>>>>> .merge_file_YGxxRC
		
			menu();
		
		}
	}

	return 0;

}