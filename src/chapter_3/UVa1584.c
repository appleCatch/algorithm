#include <stdio.h>
#include <string.h>

/**
 * 环状序列
 * 长度为n的环状串有n种表示法，分别为从某
 * 个位置开始顺时针得到
 * 在这些表示法中，字典序最小的称为"最小表示".
 *
 * 输入一个长度为n（n≤100）的环状DNA串（只包含A、 C、 G、 T这4种字符）的一种表
 * 示法，你的任务是输出该环状串的最小表示。 例如，CTCC的最小表示是
 * CCCT，CGAGTCAGCT的最小表示为AGCTCGAGTC
 *
 * 本题其实没有技巧可言, 每比较两个点所在序列的大小,都要将这两个点起始的串比较一遍,最终找出最小的串
 */

int less(char *s, int p, int q){
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		char pchar = *(s+(p+i)%len);
		char qchar = *(s+(q+i)%len);
		if(pchar != qchar) {
			return pchar < qchar;
		}
	}
	return 0;
}

void circular_sequence(){
	const int maxn = 100;
	char s[maxn];
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int ans = 0;
		int len = strlen(s);
		for(int i = 1; i < len; i++) {
			//如果i < ans, 更改ans的值
			if(less(s, i, ans)){
				ans = i;
			}
		}
		//输出最小序列
		for(int i = 0; i < len; i++){
			putchar(s[(ans+i)%len]);
		}
		printf("\n");
	}
}

/**
 * 测试最小环序列
 *
 * 2
 * CTCC
 * CCCT
 * CGAGTCAGCT
 * AGCTCGAGTC
 */
//int main(){
//	circular_sequence();
//	return 0;
//}
