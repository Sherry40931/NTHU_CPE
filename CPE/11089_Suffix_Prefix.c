#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_longest_pair(char *a, char *b){
	int len_a = strlen(a);
	int len_b = strlen(b);
	
	int i, word_len;
	int same, max_len=0;
	
	//a is suffix, b is prefix
	for(word_len=len_a; word_len>0; word_len--){
		same = 1;
		//compare in curent length
		for(i=0; i<word_len; i++){
			if(a[len_a - word_len + i] != b[i]){
				same = 0;
				break;
			}
		}
		//if same, it is the longest
		if(same == 1){
			max_len = word_len;
			break;
		}
	}
	
	//b is suffix, a is prefix
	for(word_len=len_b; word_len>0; word_len--){
		same = 1;
		for(i=0; i<word_len; i++){
			if(b[len_b - word_len + i] != a[i]){
				same = 0;
				break;
			}
		}
		if(same == 1){
			if(max_len < word_len)
				max_len = word_len;
		}
	}
	
	return max_len;
}

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N;
	int i, j;
	int max_len, cur_len;
	char word[35][35], a[35], b[35];
	
	while(scanf("%d", &N) != EOF){
		//input
		for(i=0; i<N; i++){
			scanf("%s", word[i]);
		}
		
		//count
		max_len = 0;
		for(i=0; i<N; i++){
			for(j=i+1; j<N; j++){
				cur_len = get_longest_pair(word[i], word[j]);
				if (cur_len > max_len)
					max_len = cur_len;
			}
		}
		
		printf("%d\n", max_len);
	}
	
	fclose(fptr);
	return 0;
}