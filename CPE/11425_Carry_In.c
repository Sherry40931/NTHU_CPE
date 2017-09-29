#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	char a[1001], b[1001];
	int i, c, cnt, m, n;
	int len_a, len_b, diff_a, diff_b, len;
		
	//input
	while(scanf("%s %s", a, b) != EOF){
		
		//initialize
		cnt = 0;
		
		//count len
		len_a = strlen(a);
		len_b = strlen(b);
		if(len_a >= len_b){
			diff_a = 0;
			diff_b = len_a - len_b;
			len = len_a;
		}
		else{
			diff_b = 0;
			diff_a = len_b - len_a;
			len = len_b;
		}
		
		//count carry
		c = 0;
		for(i=len-1; i>=0; i--){
			if(i-diff_a < 0)	m = 0;
			else				m = a[i-diff_a] - '0';

			if(i-diff_b < 0)	n = 0;
			else				n = b[i-diff_b] - '0';
			
			if(m + n + c > 9){
				c = 1;
				cnt++;
			}
			else
				c = 0;
		}
		
		//print out
		printf("%d\n", cnt);
	}
	
	fclose(fptr);
	return 0;
}