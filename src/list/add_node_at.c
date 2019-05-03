#include "list.h"
/*
 Adds a node at index n of a list or at the end of the list if n is
 too large.
 Parse once
*/

void add_node_at(struct s_node* node, struct s_node** head, int n){
	struct s_node *var;
	var = *head;
	if (node != NULL && head != NULL){
		if (n >= count_s_nodes(*head)){
			append(node, head);
		}

		else if (n<1 || *head == NULL){
			add_node(node, head);
		}
		else{
			for (int i = 0; i < n && var->next != NULL; i++){
				var = var->next;
			}
			var->prev->next = node; //check over
			node->prev = var->prev;
			node->next = var;
			var->prev = node;
		}
	}
}