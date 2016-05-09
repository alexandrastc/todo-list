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

void print_by_categ(NODE *head, char *categ)
{
	if (head->next == NULL){

		printf("The list is empty.\n");
	
	} else {

		NODE *current = head;

		while (current->next != NULL){
		
			if (strcmp(current->next->category,categ) == 0){
			
				current = current->next;
				printf("Priority: %d \n", current->priority);
				printf("Category: %s \n", current->category);
				printf("Task: %s\n\n", current->task);
			
			}

			if (current->next != NULL){

				current = current->next;
			}

		}
		printf("\n");
		
	}
}
void MergeSort(NODE** headRef)
{
  	NODE* head = *headRef;
	NODE* a;
	NODE* b;
 
  	if ((head == NULL) || (head->next == NULL)){

    	return;
  	
  	}
 
 
 	FrontBackSplit(head, &a, &b); 
 
 
  	MergeSort(&a);
  	MergeSort(&b);
 
  
  	*headRef = SortedMerge(a, b);

}
NODE* SortedMerge(NODE* a, NODE* b)
{
	NODE* result = NULL;
 
  	if (a == NULL){

    	return(b);

  	} else if (b==NULL){
    	
    	return(a);
  	
  	}

  	if (a->priority <= b->priority){
    	
    	result = a;
     	result->next = SortedMerge(a->next, b);

  	} else {
     	
     	result = b;
     	result->next = SortedMerge(a, b->next);

  	}
  	return(result);
}
void FrontBackSplit(NODE* source, NODE** frontRef, NODE** backRef)
{
	NODE* fast;
	NODE* slow;

  	if (source==NULL || source->next==NULL){

    	*frontRef = source;
    	*backRef = NULL;
 	
 	} else {
    
    	slow = source;
    	fast = source->next;
 
  
    	while (fast != NULL){

      		fast = fast->next;
      		if (fast != NULL){

        		slow = slow->next;
        		fast = fast->next;
      		}

    	}
 
    	*frontRef = source;
    	*backRef = slow->next;
    	slow->next = NULL;
  	}
}
void delete_task(NODE *head,char *task){
    
    NODE *current;                               
    NODE *deleted_node;                          
    		           
    current = head;                               
    
    if (current->next == NULL){

		printf("The list is empty.\n");
	
	} else {

    	while(current->next != NULL){
    	
    		if (strcmp(current->next->task,task) == 0){

    			deleted_node=current->next;           
    			current->next=deleted_node->next;      
    			free(deleted_node);

    		}
    	
    		if(current->next != NULL){
        	
        		current=current->next;
    	
    		}
    
   		 }
   	}

}
