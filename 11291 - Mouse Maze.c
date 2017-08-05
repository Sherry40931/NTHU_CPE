#include <stdio.h>

int main(){
    int testcase, i, j, k, row, col, now, put, path;
    char buf;
    scanf("%d", &testcase);
    for(k = 0; k < testcase; k++){
        scanf("%d %d%c", &row, &col, &buf);
        char map[row][col];
        int step[row][col];
        int queX[row*col];
		int queY[row*col];
		// INPUT //
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                scanf("%c", &map[i][j]);
                step[i][j] = -1;			//�]�w�����S���L
                if(map[i][j] == 'S'){		//�_�I��m�s�JQueue
                    queX[0]= i;
                    queY[0]= j;
                }
            }
            scanf("%c", &buf);				//����n�O�o�Y
        }

        now = 0;
        put = 1;
        step[queX[now]][queY[now]] = 0;

        while(1){
        /******* nothing in the queue *********/
            if(now >= put){
                printf("-1\n");
                break;
            }

			//��Queue�{�b�s����m���X��(x,y)
            int x = queX[now];
            int y = queY[now];

        //////////////////��//////////////////
			if(y-1>=0){
				if(map[x][y-1] == 'F'){					// ���I
					printf("%d\n", step[x][y]+1);
					break;
				} 										// �����B�٨S���L
				else if(map[x][y-1] != '#' && step[x][y-1] == -1){
					step[x][y-1] = step[x][y]+1; 			//�]�w�U�@�Ӧ�m�O�{�b��step+1
					queX[put] = x;						//�]�wque[put]=��
					queY[put] = y-1;
					put++;								//�U�@�Ӧ�m�s��que_put�̭�
				}
			}

        //////////////////�k////////////////
			if(y+1<col){
				if(map[x][y+1] == 'F'){
					printf("%d\n", step[x][y]+1);
					break;
				}
				else if(map[x][y+1] != '#' && step[x][y+1] == -1){
					step[x][y+1] = step[x][y]+1;
					queX[put] = x;
					queY[put] = y+1;
					put++;
				}
			}

        //////////////////�W////////////////
			if(x-1>=0){
				if(map[x-1][y] == 'F'){
					printf("%d\n", step[x][y]+1);
					break;
				}
				else if(map[x-1][y] != '#' && step[x-1][y] == -1){
					step[x-1][y] = step[x][y]+1;
					queX[put] = x-1;
					queY[put] = y;
					put++;
				}
			}
        //////////////////�U////////////////
			if(x+1<row){
				if(map[x+1][y] == 'F'){
					printf("%d\n", step[x][y]+1);
					break;
				}
				else if(map[x+1][y] != '#' && step[x+1][y] == -1){
					step[x+1][y] = step[x][y]+1;
					queX[put] = x+1;
					queY[put] = y;
					put++;
				}
			}
            now++;
        }
    }
    return 0;
}
