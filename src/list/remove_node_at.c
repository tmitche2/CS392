#include "list.h"
/*
 Removes the node at index n or the last node.
 Parse once
*/
void* remove_node_at(struct s_node** head, int n){
	//my_str("In remove node at\n");
	//my_str("im in RNA");
	if(n < 1 || (*head) == NULL){
		//print_int(*head);
		remove_node(head); //CHECK
		return NULL;
	}
	if ((*head)->elem == NULL){
		//my_str("Fuck off");
		return NULL;
	}
	int x = count_s_nodes(*head);
	void* temp;
	struct s_node *var = NULL;
	//print_int(*head);
	if(x <= n){ //Remove LAST
		//my_str("XXXXX Removing LAST XXXXXXX ");
		int i;
		for(i = 0; i < x; i++){
			if((*head)->next == NULL){
				break;
			}
			(*head) = (*head)->next;
		}
			if ((*head)->next==NULL){
			var = (*head);
			//my_str("RNA + RL ");
			(*head)=var->prev;
			var->prev=NULL;
			var->elem=NULL;
			free(var);
			(*head)->next = NULL;
		}
		for(i = 0; i < x; i++){
			if((*head)->prev == NULL){
				break;
			}
			(*head) = (*head)->prev;
		}

	}
	else if(head != NULL){//Removing any index but not head or last
		var = (*head);
		while(var->next != NULL && n > 0){
			var = var->next;
			n--;
		}
		temp = var->elem;
		if(var->next == NULL){
			var->prev->next = NULL;
			free(var);
			return temp;
		}
		var->prev->next = var->next;
		var->next->prev = var->prev;
		free(var);
		return temp;
	}


	return NULL;
}
