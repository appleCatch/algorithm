#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * 把前n（n≤10000）个整数顺次写在一起：123456789101112…数一数0～9各出现多少次
 *（输出10个整数，分别是0，1，…，9出现的次数）
 */

void digitCounting(){
	const int maxn = 100005;
	char s[maxn];
	int T;
	int count[10];
	scanf("%d", &T);
	while(T--){
		memset(count, 0, sizeof(count));
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			count[s[i]-'0']++;
		}
		for(int j = 0; j < 10; j++){
			printf("%d ", count[j]);
		}
		printf("\n");
	}
}

/**
 * test
 *
 * 2
 * 123
 * 0 1 1 1 0 0 0 0 0 0
 * 55555555555555555
 * 0 0 0 0 0 17 0 0 0 0
 */
//int main(){
//	digitCounting();
//	return 0;
//}
