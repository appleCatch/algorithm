#include <stdio.h>
#include <string.h>

/**
 * 如果一个字符串可以由某个长度为k的字符串重复多次得到，则称该串以k为周期。 例
 * 如，abcabcabcabc以3为周期（注意，它也以6和12为周期）
 */

void periodicStrings() {
	const int maxn = 100;
	char s[maxn];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int len = strlen(s);
		int j;
		for (int i = 1; i <= len; i++) {
			if (len % i == 0) {
				for (j = i; j <= len; j++) {
					if (s[j] != s[j % i]) {
						break;
					}
				}
				if(j == len){
					printf("%d", i);
					break;
				}
			}
		}
		printf("\n");
	}
}

/**
 * test
 *
 * 3
 * ababab
 * 2
 * aaaaaa
 * 1
 * abcabcabc
 * 3
 */
//int main(){
//	periodicStrings();
//	return 0;
//}
