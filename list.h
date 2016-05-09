 #ifndef _LIST_H_
#define _LIST_H_ 

typedef struct NOD{
	
	int priority;
	char* category;
	char* task; 
	struct NOD *next;

} NODE;

	void add_task(NODE *head, int p, char *c, char *t);
	void print_all(NODE *head);	
	void print_by_categ(NODE *head, char *categ);
	NODE* SortedMerge(NODE* a, NODE* b);
	void FrontBackSplit(NODE* source, NODE** frontRef, NODE** backRef);
	void MergeSort(NODE** headRef);
#endif 