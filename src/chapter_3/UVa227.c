#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * 有一个5*5的网格，其中恰好有一个格子是空的，其他格子各有一个字母。 一共有4种指
 令：A, B, L, R，分别表示把空格上、 下、 左、 右的相邻字母移到空格中。 输入初始网格和指
 令序列（以数字0结束），输出指令执行完毕后的网格。 如果有非法指令，应输出“This
 puzzle has no final configuration.”
 */

void puzzle() {
	const int maxn = 10;
	char a[maxn][maxn];
	char c[100];
	//输入
	for (int i = 0; i < 5; i++) {
//		gets(a[i]);
		fgets(a[i], 10, stdin);
	}
	int blankX;
	int blankY;
	//查找空格的位置
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == ' ') {
				blankX = i;
				blankY = j;
			}
		}
	}
	//输入指令
	fgets(c, 100, stdin);
	int cLen = strlen(c);
	//移动
	for (int i = 0; i < cLen - 1; i++) {
		if (c[i] == 'A' && blankX != 0) {
			a[blankX][blankY] = a[blankX - 1][blankY];
			a[--blankX][blankY] = ' ';
		}
		if (c[i] == 'R' && blankY != 4) {
			a[blankX][blankY] = a[blankX][blankY + 1];
			a[blankX][++blankY] = ' ';
		}
		if (c[i] == 'B' && blankX != 4) {
			a[blankX][blankY] = a[blankX + 1][blankY];
			a[++blankX][blankY] = ' ';
		}
		if (c[i] == 'L' && blankY != 0) {
			a[blankX][blankY] = a[blankX][blankY - 1];
			a[blankX][--blankY] = ' ';
		}
	}
	//打印
	for(int i = 0; i < 5; i++) {
		printf("%s", a[i]);
	}
}

/**
 * test
 *
 * TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0

TRGSJ
XOKLI
MDVBN
WP AE
UQHCF
 */
//int main(){
//	puzzle();
//	return 0;
//}
