#include "list.h"
/*
 Removes the last node from the list.
 Parse Once.
*/
void* remove_last(struct s_node** head){
	//struct s_node** head;
	//my_str("In Remove Last\n");
	if(head != NULL && *head != NULL && (*head)->elem != NULL){
		//my_str("If Statement- RL");
		int n=count_s_nodes(*head);
		//my_int(n);
		remove_node_at(head,n);
		//my_str("made it");
	}
	//my_str("Outside If RL");
	return NULL;
}