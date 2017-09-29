#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quePos[501*501][2], tbl[505][505];
char map[505][505];
int N, R, C;

int mouse_move(int next_x, int next_y, int cur_x, int cur_y, int in){
	if(next_x>=0 && next_y>=0 && next_x<R && next_y<C){
		//reach final point
		if(map[next_x][next_y] == 'F'){
			printf("%d\n", tbl[cur_x][cur_y]+1);
			in = -1;
		}
		//count step
		else if(map[next_x][next_y] != '#' && tbl[next_x][next_y] == -1){
			tbl[next_x][next_y] = tbl[cur_x][cur_y] + 1;
			quePos[in][0] = next_x;
			quePos[in][1] = next_y;
			in++;
		}
	}
	return in;
}

int main(){
	FILE *fptr;
	fptr = freopen("testcase.txt", "r", stdin);
	
	int i, j;
	int in, out, x, y;
	char nouse;
	
	scanf("%d", &N);
	while(N--){
		
		//initialize
		memset(map, '#', 505*505);
		memset(tbl, -1, 505*505);
		in = 1; out = 0;
		
		//input
		scanf("%d%d", &R, &C);
		scanf("%c", &nouse);
		for(i=0; i<R; i++){
			for(j=0; j<C; j++){
				scanf("%c", &map[i][j]);
				//starting point
				if(map[i][j] == 'S'){
					quePos[0][0] = i;
					quePos[0][1] = j;
					tbl[i][j] = 0;
				}
			}
			scanf("%c", &nouse);
		}		
		
		//mouse move
		while(in > out){
			x = quePos[out][0];
			y = quePos[out][1];
			
			//up
			if(in > 0)
				in = mouse_move(x-1, y, x, y, in);
			//down
			if(in > 0)
				in = mouse_move(x+1, y, x, y, in);
			//left
			if(in > 0)
				in = mouse_move(x, y-1, x, y, in);
			//right
			if(in > 0)
				in = mouse_move(x, y+1, x, y, in);
			
			out++;
		}
		
		//no result
		if(in != -1)	printf("-1\n");
	}
	
	fclose(fptr);
	return 0;
}