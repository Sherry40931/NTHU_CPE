#include <iostream>
#include <string>
#include <sstream>

/*
1113111611151113
311013211011222110
17111510
1611101315
*/
using namespace std;
int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int T, k;
	string S;
	int len, i, j, cnt;
	
	scanf("%d", &T);
	
	while(T--){
		
		//input
		cin >> S >> k;		
		
		//main
		while(k--){
			ostringstream convert;
			len = S.length();
			
			//count number
			cnt = 1; i = 0;
			while(i < len){
				while(S[i] == S[i+cnt]){
					cnt++;
					if(i+cnt >= len)	break;
				}				
				convert<<cnt<<S[i];
				i += cnt;
				cnt = 1;
			}
						
			//new S
			S.clear();
			S = convert.str();
		}
		printf("%s\n", S.c_str());
	}
	
	fclose(fptr);
	return 0;
}