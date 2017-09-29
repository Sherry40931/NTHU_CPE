#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N;
	int x[10001], tmp, max;
	int i;
	
	while(scanf("%d", &N) != EOF){
		//initialize
		memset(x, 0, sizeof(x));
		
		//input and count
		max = 0;
		while(N--){
			scanf("%d", &tmp);
			x[tmp]++;
			if(tmp > max)	max = tmp;
		}
		
		//print out
		for(i=0; i<max; i++){
			if(x[i] != 0)
				printf("%d %d ", x[i], i);	
		}
		printf("%d %d\n", x[max], max);
	}
	
	fclose(fptr);
	return 0;
}