#include <stdio.h>
#include <stdlib.h>

int main(){

	int N, i, ptr=0;
	char buf, stack[1001]={};
	scanf("%d%c", &N, &buf);
	
	for(i=0; i<N; i++){
		ptr = 0;
		while(1){
			buf = getchar();

			if(buf == '\n' || buf == EOF){
				if(ptr==0)	printf("Case %d: Yes\n", i+1);
				else 		printf("Case %d: No\n", i+1);
				break;
			}
			else if(buf=='{' || buf=='[' || buf=='(' || buf=='<'){
				stack[ptr] = buf;
				ptr++;
			}
			else if(buf=='}'){
				if(stack[ptr-1]=='{')	ptr--;
				else{
					stack[ptr] = buf;
					ptr++;
				}
			}
			else if(buf==']'){
				if(stack[ptr-1]=='[')	ptr--;
				else{
					stack[ptr] = buf;
					ptr++;
				}
			}
			else if(buf==')'){
				if(stack[ptr-1]=='(')	ptr--;
				else{
					stack[ptr] = buf;
					ptr++;
				}
			}
			else if(buf=='>'){
				if(stack[ptr-1]=='<')	ptr--;
				else{
					stack[ptr] = buf;
					ptr++;
				}
			}
		}
		
	}
	
	return 0;
}