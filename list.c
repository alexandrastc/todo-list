/**
* \file
* \brief Source code for the list header file.
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* \brief Adds tasks from input.txt file to the linked list.
* \param head Takes as parameter a pointer to the first element of the list.
* \return Doesn't return anything.
*/ 
void add_tasks(NODE *head)
{	
	FILE *fp;
	char buff[5];

	/**
	* File is opened.
	*/
	fp = fopen("input.txt","r");

	/**
	* Prints message in case it can't be opened.
	*/
	if(fp == NULL){
	
		perror("Error opening file.");
	
	} else {

		while(!feof(fp)){
			
			/**
			* Allocates memory for new node.
			*/
			NODE* new_node;
			new_node = (NODE*)malloc(sizeof(NODE));
	
			/**
			* Saves the priority ( with 5 maximum number of digits ).
			*/
			fgets(buff,5,fp);
			new_node->priority = atoi(buff);

			/**
			* Allocates memory for the category and reads it.
			*/
			new_node->category = (char*)malloc(sizeof(char)*MAX_CHAR);
			fgets(new_node->category,MAX_CHAR,fp);
			
			/**
			* Deletes newline character left by fgets.
			*/
			if (new_node->category[strlen(new_node->category)-1] == '\n'){
				
				new_node->category[strlen(new_node->category)-1] = '\0';

			}

			/**
			* Allocates memory for task and reads it.
			*/
			new_node->task = (char*)malloc(sizeof(char)*MAX_CHAR);
			fgets(new_node->task,MAX_CHAR,fp);

			/**
			* If task is empty, it frees the memory allocated for the node and quits.
			*/
			if (strcmp(new_node->task," ") == 0 || strcmp(new_node->task,"\n") == 0
				|| strcmp(new_node->task,"\0") == 0){

				free(new_node);
				break;

			}
			/**
			* Deletes newline character left by fgets.
			*/
			if (new_node->task[strlen(new_node->task)-1] == '\n'){
				
				new_node->task[strlen(new_node->task)-1] = '\0';

			}

			/**
			* New node points to the first non-empty element.
			*/
			new_node->next = head->next;

			/**
			* New node becomes the first non-empty element.
			*/
			head->next = new_node;
		}
	}
	/**
	* Closes file.
	*/
	fclose(fp);
 	
}
/**
* \brief Prints all the nodes of the list.
* \param head Takes a pointer to the first element of the list as a parameter.
* \return Doesn't return anything.
*/
void print_all(NODE *head)
{
	FILE *fp;
	fp = fopen("output.txt","a+");
	
	/** 
	* Opens file.
	*/
	if (fp == NULL){
	
		/** 
		* Prints message in case it can't be opened and quits.
		*/
		printf("Can't be opened.");
		return;
	
	} else {
	
		/**
		* Prints message in case the list is empty.
		*/
		if (head->next == NULL){

			printf("The list is empty.\n");
	
		} else {

			NODE *current = head;

			do{

				/**
				* Prints everything stored in each node.
				*/
				current = current->next;
				fprintf(fp,"Priority: %d \n", current->priority);
				fprintf(fp,"Category: %s \n", current->category);
				fprintf(fp,"Task: %s\n\n", current->task);

			} while (current->next != NULL);
			fprintf(fp,"\n");
		
		}
	}
	/**
	* Closes file.
	*/
	fclose(fp);
}
/**
* \brief Prints every element that has the same category as the one entered by the user.
* \param head Takes as a parameter a pointer to the first element of the list.
* \return Doesn't return anything.
*/
void print_by_categ(NODE *head)
{
	FILE *fp;
	fp = fopen("output.txt","a+");
	/**
	* Opens (or creates) output file (output.txt). If one already exists and it has data in it, the results will be printed after.
	*/
	
	char categ[MAX_CHAR];
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);
	/**
	* Asks user to enter a category.
	*/
	
	if (fp == NULL){

		/**
		* Prints a message in case it can't be opened and quits.
		*/
		printf("Can't be opened.");
		return;
	
	} else {

		/**
		* Prints message in case list is empty.
		*/
		if (head->next == NULL){

			fprintf(fp,"The list is empty.\n");
		
		} else {

			NODE *current = head;

			while (current->next != NULL){
			
				/** 
				* Goes through every element and checks if its category matches the one provided by the user. If it does, it gets printed.
				*/
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
	/** 
	* File is closed.
	*/
	fclose(fp);
}
/**
* \brief Merge sort function.
* \param headRef Takes as a parameter a pointer to the pointer of the first element.
* \return Doesn't return anything.
*/
void merge_sort(NODE** headRef)
{
  	NODE* head = *headRef;
	NODE* a;
	NODE* b;
	
	/** 
	* If list is empty or has 1 element, it quits.
	*/
  	if ((head == NULL) || (head->next == NULL)){

    	return;
  	
  	}
 
	/**
	* It else splits it into 2 sublists.
	*/
 	front_back_split(head, &a, &b); 
 
	/** 
	* Recursively sorts the sublists.
	*/
  	merge_sort(&a);
  	merge_sort(&b);
 
	/**
	* Merges them together.
	*/
  	*headRef = sorted_merge(a, b);

}

/**
* \brief Function that merges two sublists together.
* \param a Pointer to the first sublist.
* \param b Pointer to the second sublist.
* \return Returns a pointer to the now merged list.
*/
NODE* sorted_merge(NODE* a, NODE* b)
{
	NODE* result = NULL;
	
	/**
	* If one of them is empty, the other is returned.
	*/
  	if (a == NULL){

    	return(b);

  	} else if (b==NULL){
    	
    	return(a);
  	
  	}
	
	/**
	* Based on priority, it picks a or b and recurs.
	*/
  	if (a->priority <= b->priority){
    	
    	result = a;
     	result->next = sorted_merge(a->next, b);

  	} else {
     	
     	result = b;
     	result->next = sorted_merge(a, b->next);

  	}
	
  	return(result);
}
/**
* \brief Function that splits the list in two sublists.
* Splits the nodes into front and back halves and returns the two lists using pointers.
* If the length is odd, the extra node goes in the front list.
* \param source Pointer to the first element of the list that has to be split.
* \param frontRef Pointer to a pointer of the first sublist.
* \param backRef Pointer to a pointer of the second sublist.
* \return Doesn't return anything.
*/
void front_back_split(NODE* source, NODE** frontRef, NODE** backRef)
{
	NODE* fast;
	NODE* slow;

	/**
	* If the list is empty or has just one element, it doesn't split it.
	*/
  	if (source==NULL || source->next==NULL){

    	*frontRef = source;
    	*backRef = NULL;
 	
 	} else {
    
    	slow = source;
    	fast = source->next;
 
		/**
		* 'fast' advances two nodes and 'slow' one node.
		*/
    	while (fast != NULL){

      		fast = fast->next;
      		if (fast != NULL){

        		slow = slow->next;
        		fast = fast->next;
      		}

    	}
		/** 
		* 'slow' is before the midpoint in the list, so it gets split in two.
		*/
    	*frontRef = source;
    	*backRef = slow->next;
    	slow->next = NULL;
  	}
}
/**
* \brief Function that deletes a node, based on input provided by user.
* \param head Takes as a parameter a pointer to the first element in the list.
* \return Doesn't return anything.
*/
void delete_task(NODE *head){
    
	char task[MAX_CHAR];
	
	/**
	* Asks user to enter a task.
	*/
	printf("Please enter the task : \n");
	fscanf(stdin," %[^\n]%*c",task);

    NODE *current;                               
    NODE *deleted_node;                          
    		           
    current = head;                               
    
    if (current->next == NULL){
		/** 
		* Prints message in case list is empty.
		*/
		printf("The list is empty.\n");
	
	} else {

    	while(current->next != NULL){
    	
			/** 
			* Goes through every element and checks if its category matches the provided one.
			* If it does, it is deleted.
			*/
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
/**
* \brief Function that modifies the category based on user input.
* \param head Takes as a parameter a pointer to the first element of the list.
* \return Doesn't return anything.
*/
void modify_categ(NODE *head)
{

	/**
	* Asks user to enter the category to be modified.
	*/
	char categ[MAX_CHAR];
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

	/**
	* Asks user to enter new name for the category.
	*/
	char new_categ[MAX_CHAR];
	printf("Please enter the new name for the category : \n");
	fscanf(stdin," %[^\n]%*c",new_categ);

	NODE *current;

	current = head;

	while(current->next != NULL){
		
		if (current->next != NULL){

			current = current->next;
	
		}
		
		/**
		* It goes through every element and checks if its category matches the one provided.
		* If it does, it changes it to the new one.
		*/
		if (strcmp(current->category,categ) == 0){

			strcpy(current->category,new_categ);

		}

	}
}
/**
* \brief Function that deletes a category.
* It replaces the category with a blank to symbolise that it's empty.
* \param head Takes as a parameter a pointer to the first element in the list.
* \return Doesn't return anything.
*/
void delete_categ(NODE *head)
{
	char categ[MAX_CHAR];

	/**
	* Asks user for the category to be deleted.
	*/
	printf("Please enter the category : \n");
	fscanf(stdin," %[^\n]%*c",categ);

	NODE *current;

	current = head;

	while(current->next != NULL){
		
		if (current->next != NULL){

			current = current->next;
	
		}
		
		/** 
		* Goes through each node and if its category matches the one provided by the user, it is deleted ( replaced by a blank space ).
		*/ 
		if (strcmp(current->category,categ) == 0){

			strcpy(current->category," ");

		}

	}
}

