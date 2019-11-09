#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 *输入m个长度均为n的DNA序列，求一个DNA序列，到所有序列的总Hamming距离尽量
小。 两个等长字符串的Hamming距离等于字符不同的位置个数，例如，ACGT和GCGA的
Hamming距离为2（左数第1, 4个字符不同）。

输入整数m和n（4≤m≤50, 4≤n≤1000），以及m个长度为n的DNA序列（只包含字母
A，C，G，T），输出到m个序列的Hamming距离和最小的DNA序列和对应的距离。 如有多
解，要求为字典序最小的解。 例如，对于下面5个DNA序列，最优解为TAAGATAC。

TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
 */

void DNAConsensusString(){
	//定义轮数
	int T;
	scanf("%d", &T);
	while(T--){
		//定义行和列
		int m, n;
		scanf("%d %d", &m, &n);
		//定义dna
		char dna[m][n+1];
		//赋值
		for(int i = 0; i < m; i++)scanf("%s", dna[i]);
		//统计每列出现次数最多的标识
		for(int c = 0; c < n; c++){
			int colCount[4];
			memset(colCount, 0, sizeof(colCount));
			for(int r = 0; r < m; r++){
				switch(dna[r][c]){
					case 'A': //序号0
						colCount[0]++;
						break;
					case 'C': //序号1
						colCount[1]++;
						break;
					case 'G': //序号2
						colCount[2]++;
						break;
					case 'T': //序号3
						colCount[3]++;
						break;
				}
			}
			//找出值最大的序号
			int max = 0;
			int maxIndx = 0;
			for(int i = 0; i < 4; i++){
				if(colCount[i] > max){
					max = colCount[i];
					maxIndx = i;
				}
			}
			//打印出标识
			switch(maxIndx){
			case 0:
				printf("A");
				break;
			case 1:
				printf("C");
				break;
			case 2:
				printf("G");
				break;
			case 3:
				printf("T");
				break;
			}
		}
		printf("\n");
	}
}


/**
 * test
 */
//int main(){
//	DNAConsensusString();
//	return 0;
//}
