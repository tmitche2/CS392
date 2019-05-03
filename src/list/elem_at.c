#include "list.h"
/*
 Returns a pointer to the elem at index n or the last node.
 Parse once.
*/
void* elem_at(struct s_node* head, int n){
	struct s_node *node = node_at(head, n);//not sure if this works?
	if(node != NULL){
		return node->elem;
	}
	return NULL;
}