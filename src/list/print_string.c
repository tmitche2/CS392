#include "list.h"
/*
 Prints the elem of node as a string
*/
void print_string(struct s_node* node){
	if(node==NULL)
	{
		my_str("No str\n");
	}
	else
	{
		my_str((char*)(node->elem));
	}
}