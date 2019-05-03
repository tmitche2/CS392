#include "list.h"
/*
 Prints all the elems as chars separated by a space
*/
void traverse_char(struct s_node* head){
	if(head == NULL){
		return;
	}
	if(head!=NULL){
		if(head->elem == NULL){
			return;
		}
		print_char(head);
		if(head->next != NULL){
			traverse_char(head->next);
		}
	}
}