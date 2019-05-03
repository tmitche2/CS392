#include "list.h"
/*
 Prints the elem of node as a in
*/
void print_int(struct s_node* node){
	if(node==NULL || node->elem == NULL)
	{
		my_str("No int\n");
	}
	else
	{
		my_int(*((int*)(node->elem)));
	}
}