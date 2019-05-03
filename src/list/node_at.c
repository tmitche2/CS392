#include "list.h"
/*
 Returns a pointer to the node at index n or the last node.
 Parse once
*/
struct s_node* node_at(struct s_node* head, int n){
	struct s_node *var = NULL;
	if(head != NULL){
		var = head;
		while(n > 0 && var->next != NULL){
			var = var->next;
			n--;
		}
	}
	return var;
}