/*
 * interview_38.cpp
 *
 *  Created on: 2019年11月18日
 *      Author: junyao
 */
#include <iostream>
using namespace std;

int findFirstK(int * data, int len, int k, int start, int end){
	if(start > end) return -1;
	int middle = (start + end) / 2;
	int val = data[middle];
	if(val < k) {
		start = middle + 1;
	} else if (val > k) {
		end = middle -1;
	} else {
		if((data[middle-1] != k && middle > 0) || middle == 0) {
			return middle;
		} else {
			end = middle -1;
		}
	}
	return findFirstK(data, len, k, start, end);
}

int findLastK(int *data, int len, int k, int start, int end) {
	if(start > end) return -1;
	int middle = (start + end) / 2;
	int value = data[middle];
	if(value > k) {
		end = middle -1;
	} else if (value < k) {
		start = middle + 1;
	} else {
		if((middle < len-1 && data[middle + 1] != k) || middle == len-1) {
			return middle;
		} else {
			start = middle + 1;
		}
	}
	return findLastK(data, len, k, start, end);
}

int searchKNums(int * data, int len, int k) {
	int nums = 0;
	if(data != NULL && len > 1) {
		int first = findFirstK(data, len, k, 0, len-1);
		int end = findLastK(data, len, k, 0, len-1);
		if(first > -1 && end > -1) {
			nums = end - first + 1;
		}
	}
	return nums;
}


