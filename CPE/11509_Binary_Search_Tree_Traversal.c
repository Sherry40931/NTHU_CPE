#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *left;
	struct node *right;
	int data;
}Node;

Node *root;

void insert(int data){
	Node *new_node, *tmp;
	
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->right = NULL;
	new_node->left = NULL;
	
	tmp = root;
	while(tmp != NULL){
		if(data == tmp->data)
			break;
		
		if(data > tmp->data){
			if(tmp->right == NULL){
				tmp->right = new_node;
				break;
			}
			else
				tmp = tmp->right;
		}		
		else if(data < tmp->data){
			if(tmp->left == NULL){
				tmp->left = new_node;
				break;
			}
			else
				tmp = tmp->left;
		}	
	}
}

void preorder(Node *cur){
	
	if(cur != NULL){
		printf(" %d", cur->data);
		preorder(cur->left);
		preorder(cur->right);
	}
}

void inorder(Node *cur){
	
	if(cur != NULL){
		inorder(cur->left);
		printf(" %d", cur->data);		
		inorder(cur->right);
	}
}

void postorder(Node *cur){
	
	if(cur != NULL){		
		postorder(cur->left);
		postorder(cur->right);
		printf(" %d", cur->data);
	}
}

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int T, N, tmp;
	int i;
	root = (Node*)malloc(sizeof(Node));
	
	scanf("%d", &T);
	while(T--){
	
		//input and construct tree
		scanf("%d", &N);
		if(N > 0){
			scanf("%d", &tmp);
			root->data = tmp;
			root->left = NULL; 
			root->right = NULL;
			for(i=1; i<N; i++){
				scanf("%d", &tmp);
				insert(tmp);
			}
		
			//print out
			printf("preorder:");
			preorder(root);
			printf("\n");
			printf("inorder:");
			inorder(root);
			printf("\n");
			printf("postorder:");
			postorder(root);
			printf("\n");
		}
		else{
			printf("preorder:\ninorder:\npostorder:\n");
		}
	}
	
	fclose(fptr);
	return 0;
}