/** 
* \file
* \brief Header file for functions that use the linked list.
*/
#ifndef _LIST_H_
#define _LIST_H_ 
#define MAX_CHAR 1000
/**
* \def MAX_CHAR 
* \brief The maximum number of characters of the variables in which the tasks and categories are stored.
*/
/**
* \struct NOD
* \brief Linked list used to store the priority, category and task.
*/
typedef struct NOD{
	
	/**
	* \var priority
	* \brief Stores the priority.
	* Is a number from 0 to 10.
	*/
	int priority;
	
	/**
	* \var category
	* \brief Contains the category. 
	Stores up to 1000 characters, can be made out of multiple words separated by a blank.
	*/
	char* category;
	
	/**
	* \var task
	* \brief Contains the task.
	Stores up to 1000 characters, can be made out of multiple words separated by a blank.
	*/
	char* task;

	/**
	* \var next
	* \brief Pointer to the next element in the list.
	*/
	struct NOD *next;

} NODE;
	
	/** 
	* \var NODE 
	* \brief Used for declarations.
	*/

	void add_tasks(NODE *head);
	void print_all(NODE *head);	
	void print_by_categ(NODE *head);
	NODE* sorted_merge(NODE* a, NODE* b);
	void front_back_split(NODE* source, NODE** frontRef, NODE** backRef);
	void merge_sort(NODE** headRef);
	void delete_task(NODE *head);
	void modify_categ(NODE *head);
	void delete_categ(NODE *head);

#endif 