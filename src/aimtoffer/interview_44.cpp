/*
 * interview_44.cpp
 *
 *  Created on: 2019年11月16日
 *      Author: junyao
 */
#include <iostream>
using namespace std;

int compare(const void * arg1, const void * arg2) {
	return *((int*)arg1) - *((int*)arg2);
}

bool isConsence(int * number, int len){
	if(number == NULL || len < 1) return false;
	// 排序
	qsort(number, len, sizeof(int), compare);
	// 统计数组中的数字
	int zeroNums = 0;
	int gapNums = 0;
	for (int i = 0; i < len; i++) {
		if(*(number + i) == 0) zeroNums++;
	}
	// 统计数组中的间隔数目
	int small = zeroNums;
	int big = small + 1;
	// 切入的角度特别好，利用两个循环变量即可实现空缺的计数和对子的判断
	while(big < len) {
		// 有对子产生（除0以外）
		if(*(number + small) == *(number + big)) return false;
		gapNums += *(number + big) - *(number + small) -1;
		small = big;
		big++;
	}
	return gapNums > zeroNums ? false : true;
}



