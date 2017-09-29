#include <stdio.h>

int alph[52], out[21], M;

void dfs(int end, int step, int start){
	int i;
	
	//printf("%d %d %d\n", end, step, start);
	
	if(step == end){
		for(i=0; i<end; i++){
			if(out[i]<26)	printf("%c", out[i]+'A');
			else			printf("%c", out[i]-26+'a');
		}
		printf("\n");
		return;
	}
	else{
		for(i=start; i<M; i++){
			if(alph[i] != 0){
				out[step] = i;
				alph[i]--;
				dfs(end, step+1, i);
				alph[i]++;
			}
		}
	}
}

int main(){
	//FILE *fptr;
	//fptr = freopen("testcase.txt", "r", stdin);
	
	int T, N;
	int i;
	
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &M, &N);
		for(i=0; i<52; i++){
			if(i<M)		alph[i] = 1;
			else		alph[i] = 0;
		}
		dfs(N, 0, 0);
		printf("\n");
	}
	
	//fclose(fptr);
	return 0;
}