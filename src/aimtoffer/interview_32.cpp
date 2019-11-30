/*
 * interview_32.cpp
 *
 *  Created on: 2019年11月30日
 *      Author: junyao
 */
#include <iostream>
#include <string.h>
using namespace std;

// 10的n次幂的计算
int powerBase10(int n) {
	int result = 1;
	for (int i = 0;i<n; i++) result *= 10;
	return result;
}
// 递归计算每位为1时可能的数量
int numberOf1(char * arr) {
	if(!arr || *arr <='0' || *arr>'9' || *arr=='\0') return 0;
	int first = *arr - '0';
	// 找出字符串的长度
	unsigned int len = static_cast<unsigned int>(strlen(arr));
	// 判断first 和 长度
	if(len == 1 && first == 0) return 0;
	if(len ==1 && first > 0) return 1;
	// 长度大于1的情况，找出最高位为的1的数量，并依次递归下去
	int numberFirstDigit = 0; // 第一位是1的情况的个数
	if(first >1) numberFirstDigit = powerBase10(len-1); // 如果第一位大于1， 说明最高位为1的次数是10（0-9）的其余位次幂
	else if (first == 1) numberFirstDigit = atoi(arr+1) + 1; // 如果第一位等于一，说明最高位是1的次数是其余位的个数加1

	// 除去最高位之外的其余数位中1的次数
	int numberOtherDigits = first * (len-1) * powerBase10(len-2); // 根据排列组合，每个数位的可能值是（0-9）10种情况，len-2个数位幂次可能，共有len-1个这样的数位。

	// 递归下一位的情况
	int numberRecursive = numberOf1(arr+1);

	return numberFirstDigit + numberOtherDigits + numberRecursive;

}
// 定义函数，递归求1到n中1中出现的次数
int numberOf1Between1AndN(int n) {
	// 参数校验
	if (n <=0) return 0;
	//将数字转换为字符数组
	char numArr[50];
	sprintf(numArr, "%d", n);
	return numberOf1(numArr);
}



