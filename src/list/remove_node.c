#include "list.h"
/*
 Removes the given node from the list. Returns elem and frees the
 node from memory.
 DOES NOT PARSE.
*/
void* remove_node(struct s_node** node){
	//my_str("HERE\n");
	if(node != NULL && (*node)!= NULL && (*node)->elem != NULL){
		//my_str("I'm here! Big If\n");
		struct s_node *temp;
		//void* elem= (*node)-> elem;
		temp=(*node);
		if ((*node)->prev==NULL){
			if ((*node)->next==NULL){
				//my_str("I'm here!2\n");
				free(temp);
			}
			else{
			//my_str("I'm here!3\n");
			(*node)=temp->next;
			temp->next=NULL;
			temp->elem=NULL;
			//my_str("it gets here");
			free(temp);
			}
		}
		else if ((*node)->next==NULL){ //Final Stage for emptying list
			//my_str("I'm here!4\n");
			(*node)=temp->prev;
			(*node)->elem = NULL;
			//temp->prev=NULL;
			//temp->elem=NULL;
			free(temp);
			//my_str("its doing something");
			return temp;
		}
		else{
			//my_str("I'm here!5\n");
			(*node)=temp->next;
			(*node)->prev=temp->prev;
			//my_str("it gets here");
			temp->prev=NULL;
			temp->next=NULL;
			temp->elem=NULL;
			free(temp);
			//my_str("free");
		}
		//my_str("outside");
		//my_int(*((int*)(elem)));
		//my_str("I'm here!6\n");
		if((*node)->next!= NULL){
			//my_str("In");
			return NULL;
		}
		//(*node)->elem= NULL;
		//return NULL;
	}
	/*if((*node)->elem == NULL){ I put this in empty list
		my_str("here");
		return NULL;
	}*/
	return NULL;

}
