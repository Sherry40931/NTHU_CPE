#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int t, n, a[10001], b[10001];
	int i, c, out[10001], sum;
		
	scanf("%d", &t);
	while(t--){
		//input
		scanf("%d", &n);
		for(i=0; i<n; i++)	scanf("%1d", &a[i]);
		for(i=0; i<n; i++)	scanf("%1d", &b[i]);
		
		//add
		c = 0;
		for(i=n-1; i>=0; i--){
			sum = a[i]+b[i]+c;
			if(sum>1){
				sum -= 2;
				c = 1;
			}
			else	
				c = 0;
			out[i] = sum;
		}	
		
		//print out
		for(i=0; i<n; i++)	printf("%d", out[i]);
		printf("\n");
	}
	
	fclose(fptr);
	return 0;
}