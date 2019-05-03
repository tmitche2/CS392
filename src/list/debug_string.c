#include "list.h"
/*
 Prints all the elems as strings separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL)
*/
void debug_string(struct s_node* head){
	while(head!=NULL && head->elem != NULL){
		my_char('(');
		if(head->prev==NULL){
			my_str("NULL");
		}
		else{
			print_string(head->prev);
		}
		my_str(" <- ");
		print_string(head);
		my_str(" -> ");
		if(head->next==NULL){
			my_str("NULL)");
		}

		else{
			print_string(head->next);
			my_str("), ");
		}
		head=head->next;

	}
	return;
}