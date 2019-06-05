#include <stdio.h>
#include <string.h>

/**
 * 如果x加上x的各个数字之和得到y，就说x是y的生成元。 给出n（1≤n≤100000），求最小
 * 生成元。 无解输出0
 */
void digit_generator(){
	const int maxn = 100005;
	int arr[maxn];
	memset(arr, 0, sizeof(arr));
	//一次性初始化, 数组下标当索引
	for(int i = 1; i < maxn; i++) {
		int x = i, y = i;
		while(y > 0) {
			x += y % 10;
			y = y / 10;
		}
		if(arr[x]==0 || i < arr[x]) arr[x] = i;
	}

	int T;
	int n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
}


/**
 * 测试
 *
 *
 *  2005
	1979
	216
	198
	121
	0
 */
//int main(){
//	digit_generator();
//	return 0;
//}
