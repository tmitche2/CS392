#include "list.h"
/*
 Prints all the elems as ints separated by a space
*/
void traverse_int(struct s_node* head){
	//struct s_node* temp = head;
	if(head == NULL){
		return;
	}
	if(head!=NULL){
		//my_str(" Head: ");
		if(head->elem == NULL){
			return;
		}
		print_int(head);
		//my_str(" Head->Next: ");
		//print_int(head->next);
		if(head->next != NULL){
			traverse_int(head->next);
		}
	}
}