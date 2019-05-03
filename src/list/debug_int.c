#include "list.h"
/*
 Prints all the elems as ints separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL)
*/
void debug_int(struct s_node* head){
	//my_str("Im in debug");
	while(head!=NULL && head->elem != NULL){
		my_char('(');
		if(head->prev==NULL){
			my_str("NULL");
		}
		else{
			print_int(head->prev);
		}
		my_str(" <- ");
		print_int(head);
		my_str(" -> ");
		if(head->next==NULL){
			my_str("NULL)");
		}

		else{
			print_int(head->next);
			my_str("), ");
		}
		head=head->next;

	}
	return;
	//my_str("Nothing here.");
}