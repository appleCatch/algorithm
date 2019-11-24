/*
 * interview_34.cpp
 *
 *  Created on: 2019年11月23日
 *      Author: junyao
 */
#include <iostream>
using namespace std;
int Min(int a, int b, int c) {
	int min = a > b ? b : a;
	return min > c ? c : min;
}
int getUglyNumber(int index) {
	if (index <= 0) return 0;
	int * uglyNumbers = new int[index];
	uglyNumbers[0] = 1;
	int* t2 = uglyNumbers;
	int* t3 = uglyNumbers;
	int* t5 = uglyNumbers;
	int nextIndex = 1;
	while(nextIndex < index) {
		int minNumber = Min(*t2 * 2, *t3*3, *t5*5);
		uglyNumbers[nextIndex] = minNumber;
		while(*t2*2 <= uglyNumbers[nextIndex]) {
			t2++;
		}
		while(*t3*3 <= uglyNumbers[nextIndex]){
			t3++;
		}
		while(*t5*5 <= uglyNumbers[nextIndex]) {
			t5++;
		}
		nextIndex ++;
	}
	int uglyNumber = uglyNumbers[nextIndex-1];
	delete [] uglyNumbers;
	return uglyNumber;
}



