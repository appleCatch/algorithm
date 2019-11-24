/*
 * interview_35.cpp
 *
 *  Created on: 2019年11月23日
 *      Author: junyao
 */
#include <iostream>
using namespace std;

char firstNotReplicatingChar(char * data) {
	if(NULL == data) return '\0';
	const int tableSize = 256;
	unsigned int table[tableSize];
	// 遍历字符串
	for(int i = 0; i < tableSize; i++) table[i] = 0;
	char* pStr = data;
	while(*(pStr)!='\0') {
		table[*(pStr)] ++;
		pStr++;
	}
	// 遍历第二遍
	pStr = data;
	while(*(pStr) != '\0') {
		if(table[*(pStr)] == 1) {
			return *(pStr);
		}
		pStr++;
	}
	return '\0';
}



