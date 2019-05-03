#include "list.h"
/*
 Returns the value the length of the list
 Parse Once.
*/
int count_s_nodes(struct s_node* head){
	int count = 0;
	struct s_node* var = head;
	if (head != NULL){
		while(var != NULL){
			var = var->next;
			count++;
		}
	}
	return count;
}