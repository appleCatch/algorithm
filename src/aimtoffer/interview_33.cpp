/*
 * interview_33.cpp
 *
 *  Created on: 2019年11月23日
 *      Author: junyao
 */
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

const int maxSize = 10;
char* strCombine1 = new char[2 * maxSize + 1];
char* strCombine2 = new char[2 * maxSize + 1];
// 重点在这个方法，自定义比较顺序，返回排列最小的组合
int compare(const void * str1, const void * str2) {
	strcpy(strCombine1, *(char**)str1);
	strcat(strCombine1, *(char**)str2);

	strcpy(strCombine2, *(char**)str2);
	strcat(strCombine2, *(char**)str1);
	return strcmp(strCombine1, strCombine2);
}

void printMinStr(int * numbers, int len) {
	// 异常情况判断
	if(NULL == numbers || len <= 0) return ;
	// 将数字转换为字符数组（二维）
	char** strNumbers = (char**)new int[len];
	for(int i = 0; i<len; i++) {
		strNumbers[i] = new char[maxSize + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}
	// 排序
	qsort(strNumbers, len, sizeof(char*), compare);
	// 打印
	for(int i = 0; i<len; i++) printf("%s", strNumbers[i]);
	printf("\n");

	// 删除内存中的空间
	for(int i=0; i<len; i++) {
		delete [] strNumbers[i];
	}
	delete [] strNumbers;
}



