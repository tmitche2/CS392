#include "list.h"

void intTest(){
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	int five = 5;
	int six = 6;
	int seven = 7;
	int eight = 8;
	int nine = 9;
	int ten = 10;
	int eleven = 11;

	struct s_node *head = new_node(&zero, NULL, NULL);
	struct s_node *n1 = new_node(&one, NULL, NULL);
	struct s_node *n2 = new_node(&two, NULL, NULL);
	struct s_node *n3 = new_node(&three, NULL, NULL);
	struct s_node *n4 = new_node(&four, NULL, NULL);
	struct s_node *n5 = new_node(&five, NULL, n3);
	struct s_node *n6 = new_node(&six, NULL, NULL);
	struct s_node *n7 = new_node(&seven, n1, NULL);
	struct s_node *n8 = new_node(&eight, NULL, NULL);
	struct s_node *n9 = new_node(&nine, NULL, NULL);
	struct s_node *n10 = new_node(&ten, NULL, NULL);
	struct s_node *n11 = new_node(&eleven, NULL, NULL);

	my_str("START...\n");
	add_node(n1, &head);
	add_node(n2, &head);
	add_node(n3, &head);
	add_node(n4, &head);
	my_str("--------DEBUG_INT------------\n");
	debug_int(head);
	my_char('\n');
	add_node_at(n5, &head, 5);
	debug_int(head);
	my_char('\n');
	my_str("--------TRAVERSING----------\n");
	traverse_int(head);
	my_char('\n');
	remove_node_at(&head, -7);
	traverse_int(head);
	my_str("\nXXX Passed remove node at for -7 XXX\n");
	my_char('\n');
	my_str("-------REMOVE NODE--------------\n Before: ");
	traverse_int(head);
	remove_node(&head);
	my_str(" After: ");
	traverse_int(head);
	my_str(" Passed remove node");
	my_char('\n');
	my_str("-------REMOVE LAST--------------\n Before: ");
	traverse_int(head);
	remove_last(&head);
	my_str(" After: ");
	traverse_int(head);
	//my_str("prints");
	my_char('\n');
	my_str("------------Appending More------------\n");
	append(n6, &head);
	append(n7, &head);
	append(n8, &head);
	append(n9, &head);
	append(n10, &head);
	traverse_int(head);
	my_char('\n');
	//my_int(count_s_nodes(head));
	my_char('\n');
	debug_int(head);
	my_str("Debug works");
	my_char('\n');
	my_str("-------REMOVE NODE AT 6--------------\n Before: ");
	traverse_int(head);
	remove_node_at(&head, 6);
	my_str(" After: ");
	traverse_int(head);
	my_char('\n');
	my_str("-------REMOVE NODE AT 1--------------\n Before: ");
	traverse_int(head);
	remove_node_at(&head, 1);
	my_str(" After: ");
	traverse_int(head);
	my_char('\n');
	my_str("------------Adding 10------------\n");
	add_elem(&ten, &head);
	traverse_int(head);
	my_char('\n');
	my_int(count_s_nodes(head));
	my_char('\n');
	my_str("-----------Printing *(int*)node_at(head, 3) -> elem-----------\n");
	my_int(*(int*)node_at(head, 3) -> elem);
	my_char('\n');
	traverse_int(head);
	my_char('\n');
	my_str("------------Emptying List------------\n");
	empty_list(&head);
	my_str("------------Traverse------------\n");
	traverse_int(head);
	my_char('\n');
	my_str("------------Debug Empty List------------\n");
	debug_int(head);
	my_char('\n');
	my_str("----------Remove Node of Empty List------------\n");
	remove_node(&head);
	traverse_int(head);
	my_char('\n');
	my_str("------------Remove Last of Empty List------------\n");
	remove_last(&head);
	traverse_int(head);
	my_char('\n');
	my_str("----------Remove Node at Empty List----------\n");
	remove_node_at(&head, 0);
	my_char('\n');
	my_str("---------Appending 11 to Head---------\n");
	append(n11, &head); /*CHECK THIS FOR REUSING NODES*/
	traverse_int(head);
	my_char('\n');
	my_str("-----------Holy shit i got intTest...-----------------");
}

void charTest(){
	char zero = '0';
	char one = '1';
	char two = '2';
	char three = '3';
	char four = '4';
	char five = '5';
	char six = '6';
	char seven ='7';
	char eight = '8';
	char nine = '9';
	char ten = 'A';
	char eleven = 'B';

	struct s_node *head = new_node(&zero, NULL, NULL);
	struct s_node *n1 = new_node(&one, NULL, NULL);
	struct s_node *n2 = new_node(&two, NULL, NULL);
	struct s_node *n3 = new_node(&three, NULL, NULL);
	struct s_node *n4 = new_node(&four, NULL, NULL);
	struct s_node *n5 = new_node(&five, NULL, n3);
	struct s_node *n6 = new_node(&six, NULL, NULL);
	struct s_node *n7 = new_node(&seven, n1, NULL);
	struct s_node *n8 = new_node(&eight, NULL, NULL);
	struct s_node *n9 = new_node(&nine, NULL, NULL);
	struct s_node *n10 = new_node(&ten, NULL, NULL);
	struct s_node *n11 = new_node(&eleven, NULL, NULL);


	my_str("----------START CHAR TEST-----------\n");add_node(n1, &head);
	add_node(n2, &head);
	add_node(n3, &head);
	add_node(n4, &head);
	debug_char(head);
	traverse_char(head);
	my_char('\n');
	my_str("-----------Adding Node At-----------\n");
	add_node_at(n5, &head, 5);
	debug_char(head);
	my_char('\n');
	traverse_char(head);
	my_char('\n');
	my_str("-----------Removing node at-----------\n");
	remove_node_at(&head, -7);
	traverse_char(head);
	my_char('\n');
	my_str("-----------Removing node-----------\n");
	remove_node(&head);
	traverse_char(head);
	my_char('\n');
	my_str("-----------Removing last-----------\n");
	remove_last(&head);
	traverse_char(head);
	my_char('\n');
	my_str("-----------Appending More-----------\n");
	append(n6, &head);
	append(n7, &head);
	append(n8, &head);
	append(n9, &head);
	append(n10, &head);
	traverse_char(head);
	my_char('\n');
	my_str("Amount of nodes: ");
	my_int(count_s_nodes(head));
	my_char('\n');
	debug_char(head);
	my_char('\n');
	my_char('\n');
	my_str("-----------Removing node at(twice)-----------\n");
	remove_node_at(&head, 6);
	traverse_char(head);
	my_char('\n');
	remove_node_at(&head, 1);
	traverse_char(head);
	my_char('\n');
	my_str("-----------Adding Elem----------\n");
	add_elem(&ten, &head);
	traverse_char(head);
	my_char('\n');
	my_str("Amount of nodes: ");
	my_int(count_s_nodes(head));
	my_char('\n');
	my_str("Check: ");
	my_char(*(char*)node_at(head, 3) -> elem);
	my_char('\n');
	traverse_char(head);
	my_char('\n');
	my_str("-----------Empty List-----------\n");
	empty_list(&head);
	traverse_char(head);
	my_char('\n');
	debug_char(head);
	my_char('\n');
	my_str("-----------Removing node from Empty List-----------\n");
	remove_node(&head);
	my_char('\n');
	my_str("-----------Removing last from Empty List-----------\n");
	remove_last(&head);
	my_char('\n');
	my_str("-----------Removing node at from Empty List-----------\n");
	remove_node_at(&head, 0);
	my_char('\n');
	my_str("-----------Adding to empty list-----------\n");
	append(n11, &head); /*CHECK THIS FOR REUSING NODES*/
	traverse_char(head);
	my_char('\n');
	my_str("FUCK YEA");
}

void stringTest(){
	char zero[] = "zero";
	char one[] = "one";
	char two[] = "two";
	char three[] = "three";
	char four[] = "four";
	char five[] = "five";
	char six[] = {'s', 'i', 'x', '\0'};
	char seven[] = "seven";
	char eight[] = "eight";
	char nine[] = "nine";
	char ten[] = "ten";
	char eleven[]= "eleven";

	struct s_node *head = new_node(zero, NULL, NULL);
	struct s_node *n1 = new_node(one, NULL, NULL);
	struct s_node *n2 = new_node(two, NULL, NULL);
	struct s_node *n3 = new_node(three, NULL, NULL);
	struct s_node *n4 = new_node(four, NULL, NULL);
	struct s_node *n5 = new_node(five, NULL, n3);
	struct s_node *n6 = new_node(six, NULL, NULL);
	struct s_node *n7 = new_node(seven, n1, NULL);
	struct s_node *n8 = new_node(eight, NULL, NULL);
	struct s_node *n9 = new_node(nine, NULL, NULL);
	struct s_node *n10 = new_node(ten, NULL, NULL);
	struct s_node *n11 = new_node(eleven, NULL, NULL);


	my_str("---------------My_str Test------------\n");
	add_node(n1, &head);
	add_node(n2, &head);
	add_node(n3, &head);
	add_node(n4, &head);
	my_char('\n');
	add_node_at(n5, &head, 5);
	my_str("------------Traverse 1------------\n");
	traverse_string(head);
	my_char('\n');
	my_str("------------Remove Node At-----------\n");
	remove_node_at(&head, -7);
	traverse_string(head);
	my_char('\n');
	my_str("------------Remove Node------------\n");
	remove_node(&head);
	traverse_string(head);
	my_char('\n');
	my_str("------------Remove Last------------\n");
	remove_last(&head);
	traverse_string(head);
	my_char('\n');
	my_str("------------Appending More------------\n");
	append(n6, &head);
	append(n7, &head);
	append(n8, &head);
	append(n9, &head);
	append(n10, &head);
	traverse_string(head);
	my_char('\n');
	my_str("Amount of nodes: ");
	my_int(count_s_nodes(head));
	my_char('\n');
	my_str("------------Remove Node At------------\n");
	remove_node_at(&head, 6);
	traverse_string(head);
	my_char('\n');
	remove_node_at(&head, 1);
	traverse_string(head);
	my_char('\n');
	my_str("------------Add Elem------------\n");
	add_elem(&ten, &head);
	traverse_string(head);
	my_char('\n');
	my_str("Amount of nodes: ");
	my_int(count_s_nodes(head));
	my_char('\n');
	my_str("Traversal: ");
	traverse_string(head);
	my_char('\n');
	my_str("------------Emptying List------------\n");
	empty_list(&head);
	traverse_string(head);
	my_char('\n');
	my_str("-----------Removing node from Empty List-----------\n");
	remove_node(&head);
	my_char('\n');
	my_str("-----------Removing last from Empty List-----------\n");
	remove_last(&head);
	my_char('\n');
	my_str("-----------Removing node at from Empty List-----------\n");
	remove_node_at(&head, 0);
	my_char('\n');
	my_str("-----------Appending to Empty List-----------\n");
	append(n11, &head); /*CHECK THIS FOR REUSING NODES*/
	add_elem("elem1", &head);
	traverse_string(head);
	my_char('\n');
	my_str("-----------Removing node once again-----------\n");
	remove_node(&head);
	traverse_string(head);
	my_char('\n');
	my_str("CONGRATU-FUCKIN-LATIONS\n");

}

void emptyTest(){
	int one = 1;
	int two = 2;
	int three = 3;
	int five = 5;

	struct s_node *head = new_node(NULL, NULL, NULL);
	struct s_node *head2 = new_node(&one, NULL, NULL);
	struct s_node *h = NULL;
	struct s_node **h2 = NULL;
	struct s_node *n1 = new_node(&one, NULL, NULL);
	struct s_node *n2 = new_node(&two, NULL, NULL);
	/*struct s_node *n3 = new_node(&three, NULL, NULL);*/


	my_str("-----------Test adding to Null head----------");
	my_char('\n');
	add_node(n1, &head);
	//my_str("Added the node");
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	add_node(n2, &h);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*add_node(n3, h2);*/
	my_char('\n');


	my_str("-------------Test remove from Null head-----------");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');
	remove_node(&head);
	//my_str("does it blank here");
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	remove_node(&h);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*remove_node(h2);*/
	my_char('\n');


	my_str("-----------Test append to Null head--------------");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');
	append(n1, &head);
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	append(n2, &h);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*append(n3, h2);*/
	my_char('\n');



	my_str("---------Test remove_last from Null head-----------");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');
	remove_node(&head);
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	remove_node(&h);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*remove_node(h2);*/
	my_char('\n');



	my_str("-----------Test remove_node_at from Null head------------");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');
	//my_str("before RNA");
	remove_node_at(&head, 3);
	//my_str("after RNA");
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	remove_node_at(&h, 3);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*remove_node_at(h2, 3);*/
	my_char('\n');

	my_str("---------Test add_node_at to Null head----------");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');
	add_node_at(n1, &head, 1);
	traverse_int(head);
	my_char('\n');
	debug_int(head);
	my_char('\n');

	add_node_at(n2, &h, 1);
	traverse_int(h);
	my_char('\n');
	debug_int(h);
	my_char('\n');

	/*add_node_at(n3, h2, 1);*/
	my_char('\n');


	my_str("Test elem_at to Null head");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');

	my_str("Test node_at to Null head");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');

	node_at(head, 1);
	my_char('\n');
	node_at(h, 1);
	my_char('\n');


	my_str("Test count_s_nodes with Null head");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');

	my_int(count_s_nodes(head));
	my_char('\n');
	my_int(count_s_nodes(h));
	my_char('\n');


	my_str("Test empty_list with Null head");
	head = new_node(NULL, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);
	/*n3 = new_node(&three, NULL, NULL);*/
	my_char('\n');

	empty_list(&head);
	debug_int(head);
	my_char('\n');
	traverse_int(head);
	my_char('\n');
	empty_list(&h);
	my_char('\n');
	debug_int(h);
	my_char('\n');
	traverse_int(h);
	my_char('\n');
	/*empty_list(h2);*/
	my_char('\n');



	my_str("Test adding null item with Null head or Real head");
	head = new_node(NULL, NULL, NULL);
	head2 = new_node(&one, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	my_char('\n');
	add_node(n1, &head);
	/*traverse_int(head);*/
	my_char('\n');
	head = new_node(NULL, NULL, NULL);
	add_node(n2, &head);
	/*traverse_int(head);*/
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_node(n1, &head2);
	traverse_int(head2);
	my_char('\n');
	head2 = new_node(&one, NULL, NULL);
	add_node(n2, &head2);
	traverse_int(head2);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_node(n1, &h);
	traverse_int(h);
	my_char('\n');
	h = NULL;
	add_node(n2, &h);
	traverse_int(h);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	/*add_node(n1, h2);
	my_char('\n');
	h2 = NULL;
	add_node(n2, h2);*/
	my_char('\n');


	my_str("Test append with Null head or Real head");
	head = new_node(NULL, NULL, NULL);
	head2 = new_node(&one, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	my_char('\n');
	append(n1, &head);
	/*traverse_int(head);*/
	my_char('\n');
	head = new_node(NULL, NULL, NULL);
	append(n2, &head);
	/*traverse_int(head);*/
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	append(n1, &head2);
	traverse_int(head2);
	my_char('\n');
	head2 = new_node(&one, NULL, NULL);
	append(n2, &head2);
	traverse_int(head2);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	append(n1, &h);
	traverse_int(h);
	my_char('\n');
	h = NULL;
	append(n2, &h);
	traverse_int(h);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	/*append(n1, h2);*/
	my_char('\n');
	h2 = NULL;
	/*append(n2, h2);*/
	my_char('\n');



	my_str("Test add_node_at with Null head or Real head");
	head = new_node(NULL, NULL, NULL);
	head2 = new_node(&one, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	my_char('\n');
	add_node_at(n1, &head, 2);
	/*traverse_int(head);*/
	my_char('\n');
	head = new_node(NULL, NULL, NULL);
	add_node_at(n2, &head, 2);
	/*traverse_int(head);*/
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_node_at(n1, &head2, 2);
	traverse_int(head2);
	my_char('\n');
	head2 = new_node(&one, NULL, NULL);
	add_node_at(n2, &head2, 2);
	traverse_int(head2);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_node_at(n1, &h, 2);
	traverse_int(h);
	my_char('\n');
	h = NULL;
	add_node_at(n2, &h, 2);
	traverse_int(h);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	/*add_node_at(n1, h2, 2);
	my_char('\n');
	h2 = NULL;
	add_node_at(n2, h2, 2);*/
	my_char('\n');


	my_str("Test add_elem with Null head or Real head");
	head = new_node(NULL, NULL, NULL);
	head2 = new_node(&one, NULL, NULL);
	h = NULL;
	h2 = NULL;
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	my_char('\n');
	add_elem(n1, &head);
	my_str("made it pt 1");
	/*traverse_int(head);*/
	my_char('\n');
	head = new_node(NULL, NULL, NULL);
	add_elem(NULL, &head);
	my_str("here now");
	/*traverse_int(head);*/
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_elem(n1, &head2);
	my_str("got another");
	traverse_int(head2);
	my_char('\n');
	head2 = new_node(&one, NULL, NULL);
	add_elem(NULL, &head2);
	traverse_int(head2);
	my_str("even more");
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	add_elem(n1, &h);
	traverse_int(h);
	my_char('\n');
	h = NULL;
	add_elem(NULL, &h);
	traverse_int(h);
	my_char('\n');
	n1 = new_node(NULL, NULL, NULL);
	n2 = NULL;

	/*add_elem(n1 -> elem, h2);*/
	my_char('\n');
	h2 = &n1;
	add_elem(NULL, h2);
	my_char('\n');


	my_str("Test head that is not really a head (not in front)");
	my_char('\n');
	head = new_node(&five, NULL, NULL);
	head2 = new_node(&three, NULL, NULL);
	n1 = new_node(&one, NULL, NULL);
	n2 = new_node(&two, NULL, NULL);

	add_node(n2, &head);
	add_node_at(head2, &head, 1);
	add_node(n1, &head2);
	debug_int(head);
	my_char('\n');
	debug_int(head2);
	my_char('\n');
	traverse_int(head2);
	my_char('\n');

}




int main(){
	intTest();
	my_char('\n');
	charTest();
	my_char('\n');
	stringTest();
	my_char('\n');
	emptyTest();
	my_str("Time to drink 5000 beers and celebrate that you didn't segfault!");
	my_char('\n');

	return 0;
}
