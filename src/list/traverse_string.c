#include "list.h"
/*
 Prints all the elems as strings separated by a space
*/
void traverse_string(struct s_node* head){
	if(head == NULL){
		return;
	}
	if(head!=NULL){
		if(head->elem == NULL){
			return;
		}
		print_string(head);
		if(head->next != NULL){
			traverse_string(head->next);
		}
	}
}
