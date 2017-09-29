#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N, a, b;
	char cmd[5], nouse;
	int i;
	Node *list, *head;
	Node *tmp, *new_head;
	
	//initialize
	scanf("%d", &N);
	list = (Node*)malloc(sizeof(Node)*(N+1));
	list[1].prev = NULL;
	list[1].data = 1;
	for(i=2; i<=N; i++){
		list[i].data = i;
		list[i].prev = &list[i-1];
		list[i-1].next = &list[i];
	}	
	list[N].next = NULL;
	head = &list[1];
	
	//operation
	nouse = getchar();
	while(scanf("%s", cmd) != EOF){
		if(cmd[0] == 'M'){
			//1 2 3 4 5  
			//Move 2 5
			//3 4 1 2 5
			scanf("%d %d", &a, &b);				
			
			if(list[a].next != &list[b]){
				new_head = list[a].next; //3
				tmp = list[b].prev; //4
		
				list[a].next = &list[b]; //2->5
				list[b].prev = &list[a]; //2<-5
		
				head->prev = tmp;  //4<-1
				tmp->next = head;  //4->1
		
				head = new_head;
			}
		}
		else if(cmd[0] == 'E')
			break;
	}
	
	//print out
	while(head != NULL){
		if(head->next == NULL)	break;
		printf("%d ", head->data);		
		head = head->next;
	}
	printf("%d\n", head->data);
	
	fclose(fptr);
	return 0;
}