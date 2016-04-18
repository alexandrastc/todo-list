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


#endif