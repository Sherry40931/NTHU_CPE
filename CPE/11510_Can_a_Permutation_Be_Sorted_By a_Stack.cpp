#include <deque>
#include <iostream>

using namespace std;
int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int N, num, cur, i;
	deque<int> stack, supply;
	
	while(scanf("%d", &N) != EOF){
		//initialize
		stack.clear();
		supply.clear();
	
		//input
		for(i=0; i<N; i++){
			scanf("%d", &num);
			supply.push_back(num);
		}
		
		//main
		cur = 1;
		while(cur <= N){
			//pop
			if(!stack.empty() && stack.back() == cur){
				stack.pop_back();
				cur++;					
			}			
			//output
			else if(!supply.empty() && supply.front() == cur){
				supply.pop_front();
				cur++;
			}
			//push
			else if(!supply.empty()){
				stack.push_back(supply.front());
				supply.pop_front();
			}
			else	break;
		}
		
		if(cur <= N)	printf("NO\n");
		else			printf("YES\n");
	}
	
	fclose(fptr);
	return 0;
}