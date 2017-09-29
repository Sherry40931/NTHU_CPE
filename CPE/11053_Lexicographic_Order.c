#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char list[1001][51];

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N, i;
	
	while(scanf("%d", &N) != EOF){
		if(N == 0)	break;
		
		//input
		for(i=0; i<N; i++)
			scanf("%s", list[i]);
		
		//sort
		qsort(list, N, sizeof(char[51]), (int(*)(const void*,const void*)) strcmp);
		
		//output
		for(i=0; i<N; i++)
			printf("%s\n", list[i]);
		printf("\n");
	}
	
	fclose(fptr);
	return 0;
}