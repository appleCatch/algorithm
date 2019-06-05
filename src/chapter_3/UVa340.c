#include <stdio.h>
#include <string.h>
/**
 * 实现一个经典"猜数字"游戏。 给定答案序列和用户猜的序列，统计有多少数字位置正确
 * （A），有多少数字在两个序列都出现过但位置不对（B）
 * 输入包含多组数据。 每组输入第一行为序列长度n，第二行是答案序列，接下来是若干
 * 猜测序列。 猜测序列全0时该组数据结束。 n=0时输入结束
 *
 * 思路分析: 对于A可以直接统计
 * 对于B 对于每个数字（1～9），统计二者出现的次数c1和c2，则
 * min(c1,c2)就是该数字对B的贡献。 最后要减去A的部分
 */

void master_mind_hints(){
	const int maxn = 50;
	int a[maxn], b[maxn];
	//n=0 标识游戏结束
	int n, kcase = 0;
	while(scanf("%d", &n)==1 && n){
		printf("Game:%d\n", ++kcase);
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for(;;){
			int A = 0, B = 0;
			for(int i = 0; i < n; i++){
				scanf("%d", &b[i]);
				if(a[i] == b[i]) A++;
			}
			if(b[0]==0)break;//正常猜测,序列开始不能是0
			for(int i = 1; i <= 9; i++){
				int c1 = 0, c2 = 0;
				for(int j = 0; j < n; j++){
					if(a[j] == i) c1++;
					if(b[j] == i) c2++;
				}
				//取小的
				B += c1 < c2 ? c1 : c2;
			}
			printf("	(%d,%d)\n", A, B-A);
		}
	}
}

/**
 * test
 * 4
Game:1
1
3
5
5
1
1
2
3
	(1,1)
4
3
3
5
	(2,0)
6
5
5
1
	(1,2)
6
1
3
5
	(1,2)
1
3
5
5
	(4,0)
0
0
0
0
 */
//int main(){
//	master_mind_hints();
//	return 0;
//}
