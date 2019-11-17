/*
 * interview_42.cpp
 *
 *  Created on: 2019年11月17日
 *      Author: junyao
 */
#include <iostream>
#include <string.h>
using namespace std;

void reverse(char * pStart, char * pEnd) {
	if(pStart == NULL || pEnd == NULL) return;
	while (pStart < pEnd) {
		char tmp = *pStart;
		*pStart = *pEnd;
		*pEnd = tmp;
		pStart++;
		pEnd--;
	}
}
// 翻转字符串，根据空格
char * reverseSentence(char * pData) {
	if(pData == NULL) return NULL;
	// 计算出start和end
	char * pStart = pData;
	char * pEnd = pData;
	while(*pEnd != '\0') {
		pEnd++;
	}
	pEnd--;
	// 翻转所有
	reverse(pStart, pEnd);
	// 根据空格进行局部翻转
	pStart = pEnd = pData;
	while(*pStart != '\0') {
		if(*pStart == ' ') {
			pStart++;
			pEnd++;
		} else if (*pEnd == ' ' || *pEnd == '\0') {
			reverse(pStart, --pEnd);
			pStart = ++pEnd;
		} else {
			pEnd++;
		}
	}
	return pData;
}

// 旋转字符串，根据指定数字
char * rotateString(char* pStr, int n) {
	if(pStr == NULL || n < 0) return NULL;
	// 获取字符串的长度
	int len = static_cast<int>(strlen(pStr));
	if(len < 1 || len < n) return NULL;
	// 计算两段的起止节点
	char * pFirstStart = pStr;
	char * pFirstEnd = pStr + n -1;
	char * pSecondStart = pStr + n;
	char * pSecondEnd = pStr + len -1;
	// 分别翻转两个小段，然后将整个句子翻转
	reverse(pFirstStart, pFirstEnd);
	reverse(pSecondStart, pSecondEnd);

	reverse(pFirstStart, pSecondEnd);
	return pStr;
}
