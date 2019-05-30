#include <stdio.h>
#include <string.h>

/**
 * 蛇形填数
 */
void sol_3_3() {
	//定义二维数据
	int matrix[20][20];
	//初始化
	memset(matrix, 0, sizeof(matrix));
	//读取客户端输入
	int n, x, y, tot = 0;
	scanf("%d", &n);
	tot = matrix[x=0][y=n-1] = 1;
	while(tot < n * n){
		while((x < n-1) && !matrix[x+1][y]) matrix[++x][y] = ++tot;
		while((y - 1 >= 0) && !matrix[x][y-1]) matrix[x][--y] = ++tot;
		while((x -1 >= 0) && !matrix[x-1][y]) matrix[--x][y] = ++tot;
		while((y < n-1) && !matrix[x][y+1]) matrix[x][++y] = ++tot;
	}
	//打印
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
}

//int main(){
//	//测试蛇形函数
//	sol_3_3();
//	return 0;
//}
