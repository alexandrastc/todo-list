#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_task(NODE *head, int p, char *c, char *t)
{
	NODE* new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	
	new_node->priority = p;

	new_node->category = (char*)malloc(sizeof(*c));
	strcpy(new_node->category,c);

	new_node->task = (char*)malloc(sizeof(*t));
	strcpy(new_node->task,t);

	new_node->next = head->next;

	head->next = new_node;

}

void print_all(NODE *head)
{
	if (head->next == NULL){

		printf("The list is empty.\n");
	
	} else {

		NODE *current = head;

		do{

			current = current->next;
			printf("Priority: %d \n", current->priority);
			printf("Category: %s \n", current->category);
			printf("Task: %s\n\n", current->task);

		} while (current->next != NULL);
		printf("\n");
		
	}
}