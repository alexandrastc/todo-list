#ifndef _LIST_H_
#define _LIST_H_ 
#define MAX_CHAR 1000

typedef struct NOD{
	
	int priority;
	char* category;
	char* task; 
	struct NOD *next;

} NODE;


	void add_tasks(NODE *head);
	void print_all(NODE *head);	
	void print_by_categ(NODE *head);
	NODE* SortedMerge(NODE* a, NODE* b);
	void FrontBackSplit(NODE* source, NODE** frontRef, NODE** backRef);
	void MergeSort(NODE** headRef);
	void delete_task(NODE *head);
	void modify_categ(NODE *head);
	void delete_categ(NODE *head);

#endif 