#include <stdio.h>
#include <string.h>

/**
 * 给出一个由O和X组成的串（长度为1～80），统计得分。 每个O的得分为目前连续出现
 * 的O的个数，X的得分为0。 例如，OOXXOXXOOO的得分为1+2+0+0+1+0+0+1+2+3
 */

void score(){
	char s[81];
	int T; //轮数
	int len; //长度
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		len = strlen(s);
		int sum = 0;
		int value = 0;
		for(int i = 0; i < len; i++) {
			if(s[i]=='O'){
				value++;
			} else {
				value = 0;
			}
			sum += value;
		}
		printf("sum is %d \n", sum);
	}
}

/**
 * test
 * 1
 * OOXXOXXOOO
 * sum is 10
 */
//int main(){
//	score();
//	return 0;
//}
