/*
 * interview_43.cpp
 *
 *  Created on: 2019年11月16日
 *      Author: junyao
 */
#include <iostream>
#include <math.h>
using namespace std;
const int g_max = 6;
// 解法一
void shaizi_child_1(int origin, int current, int sum, int * pArr) {
	if(current == 1){
		// origin 就是数组中的偏移量
		*(pArr + (sum-origin))++;
	} else {
		for (int i = 1; i<= g_max; i++) {
			shaizi_child_1(origin, current-1, sum + i, pArr);
		}
	}
}

void shaizi_1(int n){
	if(n < 1) return;
	int max = n * g_max;
	int * pArr = new int[max-n + 1];
	// 初始化
	for(int i = n; i<=max; i++){
		*(pArr + (i - n)) = 0;
	}
	for(int i = 1; i <= g_max; i++) {
		shaizi_child_1(n, n, i, pArr);
	}
	// 打印和与概率
	int total = pow((double)g_max, n);
	for(int i = n; i<=max; i++){
		double ratio = (double)*(pArr+(i-n))/total;
		printf("%d:	%e\n", i, ratio);
	}
	delete [] pArr;
}

// 解法二， 使用循环，从起始值开始，减少中间变量的重复计算
// 使用两个数组循环记录上一次的值
void shaizi_2(int n) {
	if(n < 1) return;
	// 定义指针数组
	int * pProperties[2];
	// 初始化
	pProperties[0] = new int[g_max * n + 1];
	pProperties[1] = new int[g_max * n + 1];
	for(int i = 0; i < g_max * n + 1; i++) {
		pProperties[0][i] = 0;
		pProperties[1][i] = 0;
	}
	int flag = 0;
	for (int i = 1; i <= g_max; i++) {
		// 初始化一个骰子的和的分布
		pProperties[0][i] = 1;
	}
	for (int k = 2; k <= n; k++) {
		// 从第二个骰子开始计算
		for(int i = 0; i < k; i++) {
			pProperties[1-flag][i] = 0;
		}
		// 遍历最小值到最大值，每一个值的个数应该等于前一次的n-1,n-2,...,n-6的个数的和
		for(int i=k; i<= k * g_max; i++) {
			pProperties[1-flag][i] = 0;
			for(int j = 1; j <= g_max && j <= i; j++) {
				pProperties[1-flag][i] += pProperties[1-flag][i-j];
			}
		}
		// 将flag标记反转
		flag = 1 - flag;
	}

	// 打印比率
	double total = pow((double)g_max, n);
	for(int i = n; i<=g_max * n; i++) {
		double ratio = pProperties[flag][i] / total;
		printf("%d %e\n", i, ratio);
	}
	delete [] pProperties[0];
	delete [] pProperties[1];
}





