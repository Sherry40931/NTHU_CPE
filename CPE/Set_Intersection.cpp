#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N, M, i, tmp;
	set<int> first, second, ans;
	set<int>::iterator it;
	
	while(scanf("%d", &N) != EOF){
		if(N == 0)	break;
		//initialize
		first.clear();
		second.clear();
		ans.clear();
		
		//get input
		for(i=0; i<N; i++){
			scanf("%d", &tmp);
			first.insert(tmp);
		}
		scanf("%d", &M);
		for(i=0; i<M; i++){
			scanf("%d", &tmp);
			second.insert(tmp);
		}
		
		//intersection
		set_intersection(first.begin(), first.end(),
						second.begin(), second.end(),
						inserter(ans, ans.begin()));
		
		//print out
		if(ans.empty())	
			printf("empty");
		else{
			printf("%d", *ans.begin());
			for(it=ans.begin(); it!=ans.end(); it++){
				if(it != ans.begin())
					printf(" %d", *it);
			}
		}
		printf("\n");
	}
	
	fclose(fptr);
	return 0;
}