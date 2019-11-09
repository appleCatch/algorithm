#include <stdio.h>
#include <string.h>

/**
 * 输入整数a和b（0≤a≤3000，1≤b≤3000），输出a/b的循环小数表示以及循环节长度。 例
如a=5，b=43，小数表示为0.(116279069767441860465)，循环节长度为21。
 */

void repeatingDecimals(){
	const int maxn = 3000;
	int r[maxn], u[maxn], s[maxn];
	int m, n;
	while(scanf("%d%d", &m, &n)){
		memset(r, 0, sizeof(r));
		memset(u, 0, sizeof(u));
		int count = 0;
		int t = m;
		//存入商
		r[count++] = m / n;
		//获取余数
		m = m % n;
		while(!u[m] && m){
			//循环里执行重复除的运算
			u[m] = count; //保存对应余数的计数, 为找到循环节长度
			s[count] = m; //保存余数
			r[count++] = 10 * m / n;
			m = 10 * m % n;
		}
		//输出
		printf("%d/%d=%d.", t, n, r[0]);
		for(int i = 1; i <= 50 && i < count; i++){
			if(s[i] == m) {
				//打印循环节起始
				printf("(");
			}
			printf("%d", r[i]);
		}
		if(count > 50) {
			printf("...");
		}
		if(!m)printf("(0");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle",!m?1:count-u[m]);
	}
}

/**
 * test
 *
 * 76 25
76/25=3.04(0)
   1 = number of digits in repeating cycle
5 43
5/43=0.(116279069767441860465)
   21 = number of digits in repeating cycle
1 397
1/397=0.(00251889168765743073047858942065491183879093198992...)
   99 = number of digits in repeating cycle
 */
//int main(){
//	repeatingDecimals();
//	return 0;
//}
