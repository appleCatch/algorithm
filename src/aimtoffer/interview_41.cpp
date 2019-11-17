/*
 * interview_41.cpp
 *
 *  Created on: 2019年11月17日
 *      Author: junyao
 */
#include <iostream>
using namespace std;
// 针对第一问
bool findNumberWithSum(int *data, int len, int sum) {
	bool found = false;
	if(data == NULL || len < 1) return found;
	// 数组从小到大有序
	int *start = data;
	int *end = data + len -1;
	while(start < end) {
		long curSum = *start + *end;
		if(curSum == sum) {
			found = true;
			cout << *start << "---> " << *end << endl;
			// 找到的两个数，可以通过指针的形式传进来，修改后返回去
		} else if (curSum < sum) {
			// 值偏小，移动小指针
			start++;
		} else {
			end--;
		}
	}
	return found;
}

// 针对第二问
void printSequence(int small, int big) {
	for(int i = small; i<=big; i++) {
		printf("%d ", i);
	}
	printf("\n");
}
void findContinuousSequence(int sum) {
	if (sum < 3) return;
	int small = 1;
	int big = 2;
	int middle = (sum + 1) / 2;
	int curSum = small + big;
	while(small < middle) {
		if (curSum == sum) printSequence(small, big);
		while(curSum > sum && small < middle) {
			curSum -= small;
			small++;
			if(curSum == sum) printSequence(small, big);
		}
		big++;
		curSum += big;
	}
}


