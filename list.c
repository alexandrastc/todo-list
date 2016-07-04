#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add_tasks(NODE *head)
{	
	FILE *fp;
	char buff[5];

	fp = fopen("input.txt","r");

	if(fp == NULL){
	
		perror("Error opening file.");
	
	} else {

		while(!feof(fp)){

			NODE* new_node;
			new_node = (NODE*)malloc(sizeof(NODE));
	
			fgets(buff,5,fp);
			new_node->priority = atoi(buff);

			new_node->category = (char*)malloc(sizeof(char)*MAX_CHAR);
			fgets(new_node->category,MAX_CHAR,fp);
			
			if (new_node->category[strlen(new_node->category)-1] == '\n'){
				
				new_node->category[strlen(new_node->category)-1] = '\0';

			}

			new_node->task = (char*)malloc(sizeof(char)*MAX_CHAR);
			fgets(new_node->task,MAX_CHAR,fp);

			if (new_node->task[strlen(new_node->task)-1] == '\n'){
				
				new_node->task[strlen(new_node->task)-1] = '\0';

			}

			new_node->next = head->next;

			head->next = new_node;
		}
	}

	fclose(fp);
 	
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

<<<<<<< HEAD
void print_by_categ(NODE *head, char *categ)
{
=======
void print_by_categ(NODE *head)
{

	char categ[MAX_CHAR];
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

>>>>>>> source
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
<<<<<<< HEAD
void delete_task(NODE *head,char *task){
    
=======
void delete_task(NODE *head){
    
	char task[MAX_CHAR];

	printf("Please enter the task : \n");
	fscanf(stdin," %[^\n]%*c",task);

>>>>>>> source
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
<<<<<<< HEAD
=======
void modify_categ(NODE *head)
{

	char categ[MAX_CHAR];
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

	char new_categ[MAX_CHAR];
	printf("Please enter the new name for the category : \n");
	fscanf(stdin," %[^\n]%*c",new_categ);

	NODE *current;

	current = head;

	while(current->next != NULL){
		
		if (current->next != NULL){

			current = current->next;
	
		}

		if (strcmp(current->category,categ) == 0){

			strcpy(current->category,new_categ);

		}

	}
}
void delete_categ(NODE *head)
{
	char categ[MAX_CHAR];

	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

	NODE *current;

	current = head;

	while(current->next != NULL){
		
		if (current->next != NULL){

			current = current->next;
	
		}

		if (strcmp(current->category,categ) == 0){

			strcpy(current->category," ");

		}

	}
}

>>>>>>> source
