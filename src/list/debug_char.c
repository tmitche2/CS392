#include "list.h"
/*
 Prints all the elems as chars separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL)
*/
void debug_char(struct s_node* head){
	while(head!=NULL && head->elem != NULL){
		my_char('(');
		if(head->prev==NULL)
			my_str("NULL");
		else
			print_char(head->prev);
		my_str(" <- ");
		print_char(head);
		my_str(" -> ");
		if(head->next==NULL){
			my_str("NULL)");
		}

		else{
			print_char(head->next);
			my_str("), ");
		}
		head=head->next;

	}
	return;
}