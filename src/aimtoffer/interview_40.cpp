/*
 * interview_40.cpp
 *
 *  Created on: 2019年11月18日
 *      Author: junyao
 */

#include <iostream>
using namespace std;
int findFirstBitIs1(int num) {
	int indexBit = 0;
	while((num & 1 == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;
		indexBit++;
	}
	return indexBit;
}

bool isBit1(int indexOf1, int base) {
	base = base >> indexOf1;
	return (base & 1);
}
void findSeprateNum(int * data, int len, int * num1, int * num2) {
	if(data == NULL || len < 2) return;
	int resultExclusiveOR = 0;
	for(int i = 0; i < len; i++) resultExclusiveOR ^= *(data + i);
	unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for(int i = 0; i < len; i++) {
		if(isBit1(indexOf1, *(data + i))) {
			*num1 ^= *(data + i);
		} else {
			*num2 ^= *(data + i);
		}
	}
}


