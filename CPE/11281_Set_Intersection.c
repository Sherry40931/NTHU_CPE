#include <stdio.h>
#include <stdlib.h>

int first[1000001], second[1000001], out[1000001];

int cmp(const void *a, const void *b){
	if(*(int*)a > *(int*)b) return 1;
	if(*(int*)a == *(int*)b) return 0;
	return -1;
}

int cmp2(const void *a, const void *b){
	return *(int*)a-*(int*)b;
	//相減可能會overflow
}

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N, M;
	int i, j, k;
	
	while(scanf("%d", &N) != EOF){
		if(N == 0)	break;
		
		//get input
		for(i=0; i<N; i++)
			scanf("%d", &first[i]);

		scanf("%d", &M);
		for(i=0; i<M; i++)
			scanf("%d", &second[i]);
		
		//sort
		qsort(first, N, sizeof(int), cmp);
		qsort(second, M, sizeof(int), cmp2);
		
		
		for(i=0; i<N; i++)
			printf("%d ", first[i]);
		printf("\n^cmp\n");
		for(i=0; i<M; i++)
			printf("%d ", second[i]);
		printf("\n^cmp2\n");
		
							
		//intersection
		i=0; j=0; k=0;
		while(i < N && j < M){
			if	   (first[i] < second[j])   i++;
			else if(first[i] > second[j])	j++;
			else if(first[i] == second[j]){
				out[k] = first[i];
				i++; j++; k++;
			}
		}
		
		//print out
		if(k==0)	
			printf("empty\n");
		else{
			for(i=0; i<k-1; i++)
				printf("%d ", out[i]);
			printf("%d\n", out[k-1]);
		}
	}
	
	fclose(fptr);
	return 0;
}