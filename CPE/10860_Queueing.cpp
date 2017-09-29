#include <deque>
#include <iostream>

using namespace std;
int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	char cmd[6], tmp[11];;
	deque<string> list;
	string name;
	
	while(scanf("%s", cmd) != EOF){
		//push
		if(cmd[1] == 'u'){
			scanf("%s", tmp);
			name = tmp;
			list.push_back(name);
		}
		//pop
		else if(cmd[1] == 'o' && !list.empty()){
			list.pop_front();
		}
		//front
		else if(cmd[1] == 'r'){
			if(list.empty())	printf("empty\n");
			else				printf("%s\n", list.front().c_str());				
		}
	}
	
	fclose(fptr);
	return 0;
}