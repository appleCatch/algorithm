#include <stdio.h>
#include <string.h>

/**
 *输入一个r行c列（1≤r，c≤10）的网格，黑格用“*”表示，每个白格都填有一个字母。 如
 果一个白格的左边相邻位置或者上边相邻位置没有白格（可能是黑格，也可能出了网格边
 界），则称这个白格是一个起始格。
 首先把所有起始格按照从上到下、 从左到右的顺序编号为1, 2, 3,…

 接下来要找出所有横向单词（Across）。 这些单词必须从一个起始格开始，向右延伸到
 一个黑格的左边或者整个网格的最右列。 最后找出所有竖向单词（Down）。 这些单词必须
 从一个起始格开始，向下延伸到一个黑格的上边或者整个网格的最下行
 */

void crosswordAnswers() {
	const int maxn = 12;
	//定义缓存和序号标识数组
	char b[maxn][maxn];
	int nth[maxn][maxn];
	//定义序号累加器
	int nums = 1;
	//定义行列标识
	int r, c;

	//init
	memset(b, 0, sizeof(b));
	memset(nth, 0, sizeof(nth));
	//行列赋值
	while (scanf("%d", &r), r) {
		scanf("%d", &c);

		//用户输入赋值
		for (int i = 0; i < r; i++) {
			scanf("%s", b[i]);
			//测试打印
			printf("%s\n", b[i]);
		}

		//找出起始格并编号
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] == '*')
					continue;
				if (j - 1 < 0 || b[i][j - 1] == '*' || i - 1 < 0
						|| b[i - 1][j] == '*') {
					nth[i][j] = nums++;
				}
			}
		}
		//测试输出编号的正确性
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%3d", nth[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		//找单词
		//处理横行
		printf("cross..\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c;) {
				if (nth[i][j] == 0 || b[i][j] == '*') {
					j++;
					continue;
				}
				while (j < c && b[i][j] != '*') {
					printf("%c", b[i][j]);
					j++;
				}
				printf("\n");
			}
		}
		//处理纵向
		printf("Down...\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (nth[i][j] == 0 || b[i][j] == '*') {
					continue;
				}
				//将扫描过的位置标记置为0, 不可重复状态
				nth[i][j] = 0;
				int k = i;
				while (k < r && b[k][j] != '*') {
					printf("%c", b[k][j]);
					nth[k][j] = 0;
					k++;
				}
				printf("\n");
			}
		}
	}
}


/**
 * test
 *
 * 2
2
AT
AT
*O
*O
  1  2
  0  3

cross..
AT
O
Down...
A
TO

6
7
AIM*DEN
AIM*DEN
*ME*ONE
*ME*ONE
UPON*TO
UPON*TO
SO*ERIN
SO*ERIN
*SA*OR*
*SA*OR*
IES*DEA
IES*DEA
  4  5  6  0  7  8  9
  0 10  0  0 11  0  0
 12  0  0 13  0 14  0
 15  0  0 16 17  0  0
  0 18 19  0 20  0  0
 21  0  0  0 22  0 23

cross..
AIM
DEN
ME
ONE
UPON
TO
SO
ERIN
SA
OR
IES
DEA
Down...
A
IMPOSE
MEO
DO
ENTIRE
NEON
US
NE
ROD
AS
I
A
 */
//int main(){
//	crosswordAnswers();
//	return 0;
//}
