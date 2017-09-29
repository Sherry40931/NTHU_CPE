#include <stdio.h>
#include <stdlib.h>

long long int gcd(long long int a, long long int b){
	if(a%b == 0)	return b;
	else			return gcd(b, a%b);
}

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int t, a, b;
	int i;
	long long int top, down, k;
	
	while(scanf("%d", &t) != EOF){
		
		//input
		top = 0;	down = 1;
		for(i=0; i<t; i++){
			scanf("%d %d", &a, &b);
			//add fraction
			top = top*b + a*down;
			down *= b;
		}
		
		//gcd
		k = gcd(top, down);
		printf("%lld/%lld\n", top/k, down/k);
	}
	
	fclose(fptr);
	return 0;
}