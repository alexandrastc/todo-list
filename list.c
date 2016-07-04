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

			if (strcmp(new_node->task," ") == 0 || strcmp(new_node->task,"\n") == 0
				 || strcmp(new_node->task,"\0") == 0){

				free(new_node);
				break;

			}

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
	FILE *fp;
	fp = fopen("output.txt","a+");
	
	if (fp == NULL){
	
		return;
	
	} else {
	
		if (head->next == NULL){

			printf("The list is empty.\n");
	
		} else {

			NODE *current = head;

			do{

				current = current->next;
				fprintf(fp,"Priority: %d \n", current->priority);
				fprintf(fp,"Category: %s \n", current->category);
				fprintf(fp,"Task: %s\n\n", current->task);

			} while (current->next != NULL);
			fprintf(fp,"\n");
		
		}
	}
	fclose(fp);
}

void print_by_categ(NODE *head)
{
	FILE *fp;
	fp = fopen("output.txt","a+");

	char categ[MAX_CHAR];
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

	if (fp == NULL){

		return;
	
	} else {

		if (head->next == NULL){

			fprintf(fp,"The list is empty.\n");
		
		} else {

			NODE *current = head;

			while (current->next != NULL){
			
				if (strcmp(current->next->category,categ) == 0){
				
					current = current->next;
					fprintf(fp,"Priority: %d \n", current->priority);
					fprintf(fp,"Category: %s \n", current->category);
					fprintf(fp,"Task: %s\n\n", current->task);
				
				}

				if (current->next != NULL){

					current = current->next;
				}

			}
			fprintf(fp,"\n");
			
		}
	}
	fclose(fp);
}
void merge_sort(NODE** headRef)
{
  	NODE* head = *headRef;
	NODE* a;
	NODE* b;
 
  	if ((head == NULL) || (head->next == NULL)){

    	return;
  	
  	}
 
 
 	front_back_split(head, &a, &b); 
 
 
  	merge_sort(&a);
  	merge_sort(&b);
 
  
  	*headRef = sorted_merge(a, b);

}
NODE* sorted_merge(NODE* a, NODE* b)
{
	NODE* result = NULL;
 
  	if (a == NULL){

    	return(b);

  	} else if (b==NULL){
    	
    	return(a);
  	
  	}

  	if (a->priority <= b->priority){
    	
    	result = a;
     	result->next = sorted_merge(a->next, b);

  	} else {
     	
     	result = b;
     	result->next = sorted_merge(a, b->next);

  	}
  	return(result);
}
void front_back_split(NODE* source, NODE** frontRef, NODE** backRef)
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
void delete_task(NODE *head){
    
	char task[MAX_CHAR];

	printf("Please enter the task : \n");
	fscanf(stdin," %[^\n]%*c",task);

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

