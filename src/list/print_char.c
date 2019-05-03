#include "list.h"
/*
 Prints the elem of node as a char
*/
void print_char(struct s_node* node){
	if(node==NULL || node->elem == NULL)
	{
		my_str("No char\n");
	}
	else
	{
		my_char(*((char*)(node->elem)));
	}
}