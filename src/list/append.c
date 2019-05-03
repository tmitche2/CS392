#include "list.h"
/*
 Adds a node to the end of a list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 Parse once
*/
void append(struct s_node* node, struct s_node** head){
	//struct s_node *var;
	if(node != NULL && head != NULL && *head != NULL){
		add_node(node, head);
		return;
	}
}
