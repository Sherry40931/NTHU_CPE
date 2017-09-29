#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int a ,long long int b){
	if(a%b == 0)	return b;
	else 			return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b){
	long long int tmp;
	
	tmp = gcd(a, b);
	
	return (a/tmp)*b;
}

int main(){
	//FILE *fptr;
	//fptr = freopen("testcase.txt", "r", stdin);
	
	int N;
	long long int x, y, z;
	long long int ans1, ans2;
	
	scanf("%d", &N);
	while(N--){
		scanf("%lld %lld %lld", &x, &y, &z);
		
		ans1 = gcd(gcd(x, y), z);
		ans2 = lcm(lcm(x, y), z);
		
		printf("%lld %lld\n", ans1, ans2);
	}
	
	//fclose(fptr);
	return 0;
}