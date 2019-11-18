/*
 * interview_36.cpp
 *
 *  Created on: 2019年11月18日
 *      Author: junyao
 */
#include <iostream>
using namespace std;
int doInversePairs(int * copy, int * data, int start, int end) {
	if(start == end) {
		copy[start] = data[start];
		return 0;
	}
	int len = (end - start) / 2;
	int left = doInversePairs(copy, data, start, start + len);
	int right = doInversePairs(copy, data, start + len + 1, end);

	int i = start + len;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while(i >= start && j >= start + len + 1) {
		if(data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - len;
		} else {
			copy[indexCopy--] = data[j--];
		}
	}
	// 补全其他元素
	for(;i >= start; i--){
		copy[indexCopy--] = data[i];
	}
	for(;j >=start + len + 1; j--){
		copy[indexCopy--] = data[j];
	}
	return left + right + count;
}
int inversePairs(int * data, int len) {
	if(data == NULL || len < 0) return 0;
	// 并归排序需要使用辅助数组
	int * copy = new int[len];
	for(int i = 0; i < len; i++) {
		copy[i] = data[i];
	}
	// 调用算法计算
	return doInversePairs(copy, data, 0, len-1);
}



