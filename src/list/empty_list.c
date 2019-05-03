#include "list.h"
/*
 Frees all the nodes in the list.
 CHALLENGE: Write in two lines (allowed to use other methods in
 this assignment)
*/
void empty_list(struct s_node** head){
	while(*head != NULL && (*head)->elem != NULL){
		//my_str("Before: ");
		//traverse_char(*head);
		remove_node(head);
		//my_str(" After: ");
		//traverse_char(*head);
		//my_char('\n');
		if((*head)->elem == NULL){
			return;
		}
	}
} //TODO: test to make sure NULL head statements work