/*
 * interview_47.cpp
 *
 *  Created on: 2019年11月12日
 *      Author: junyao
 */
#include <iostream>
using namespace std;

int add_diy(int x, int y){
	int yhRes = x ^ y;
	int yuRes = (x & y) << 1;
	if(yuRes == 0) {
		return yhRes;
	}
	return add_diy(yuRes, yhRes);
}

// 基于循环的写法
int add_while(int x, int y) {
	int sum, carry;
	do {
		sum = x ^ y;
		carry = (x & y) << 1;
		x = sum;
		y = carry;
	} while(y != 0);
	return sum;
}



