/*
 * interview_31.cpp
 *
 *  Created on: 2019年11月30日
 *      Author: junyao
 */
#include <iostream>

using namespace std;

bool g_invalid_input = false;
int findGreatestSumOfSubArray(int *pData, int len) {
	if(pData == NULL || len <=0) {
		g_invalid_input = true;
		return 0;
	}

	g_invalid_input = false;
	int nCurSum = 0;
	int nGreatestSum = 0x800000000;
	for (int i = 0; i<len; i++) {
		if(nCurSum < 0) nCurSum = pData[i];
		else nCurSum += pData[i];

		if(nCurSum > nGreatestSum) nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}



