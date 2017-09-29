#include <stdio.h>
#include <string.h>
#define DOWN  0
#define RIGHT 1
#define UP    2
#define LEFT  3

int main(){
	//FILE *fptr;
	//fptr = freopen("testcase.txt", "r", stdin);
	
	char S[1005], tbl[40][40];
	int len, n;
	int i, j;
	int row, col, direction;
	
	while(fgets(S, 1005, stdin)){
		len = strlen(S);
		if(S[len-1] == '\n')	
			len -= 1;
		
		n=1;
		while(len > n*n)	
			n++;
		
		//initialize with boarder
		for(i=0; i<40; i++){
			for(j=0; j<40; j++){
				if(i<n && j<n)
					tbl[i][j] = 0;
				else
					tbl[i][j] = 1;
			}
		}
		
		//put into table
		i = 0;
		row = 0; col = 0;
		direction = 0;
		while(i < len){
			tbl[row][col] = S[i];
			i++;
			
			if(direction % 4 == DOWN){
				if(tbl[row+1][col] != 0){
					//move right
					col++;
					direction++;
				}
				else	row++;
			}
			else if(direction % 4 == RIGHT){
				if(tbl[row][col+1] != 0){
					//move up
					row--;
					direction++;
				}
				else	col++;
			}
			else if(direction % 4 == UP){
				if(row-1 < 0 || tbl[row-1][col] != 0){
					//move left
					col--;
					direction++;
				}
				else	row--;
			}
			else if(direction % 4 == LEFT){
				if(col-1 < 0 ||tbl[row][col-1] != 0){
					//move down
					row++;
					direction++;
				}
				else	col--;
			}
		}
		
		//remove blank in the end
		int flag;
		for(i=0; i<n ; i++){
			for(j=0; j<n; j++){
				if(tbl[i][j] != 0 && tbl[i][j] != ' ')
					flag = i*n+j;
			}
		}
		
		//print out
		int index=0;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				index++;
				if(tbl[i][j] != 0)
					printf("%c", tbl[i][j]);
				else
					printf(" ");
				if(index > flag)	break;
			}
		}
		printf("\n");
	}
	
	//fclose(fptr);
	return 0;
}