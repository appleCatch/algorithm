/*
 * interview_45.cpp
 *
 *  Created on: 2019年11月12日
 *      Author: junyao
 */
#include <iostream>
#include <list>
using namespace std;
// list的初始化不是该函数的职能
void lastDeleted(int m, list<int> &l) {
	list<int>::iterator icurr = l.begin();
	while(l.size() > 1) {
		for(int i = 0; i<m; i++) {
			icurr ++;
			if(icurr == l.end()) {
				icurr = l.begin();
			}
		}
		list<int>::iterator pNext = ++icurr;
		if(pNext == l.end()) pNext = l.begin();
		--icurr;
		// 移除
		l.erase(icurr);
		icurr = pNext;
	}
}

// 第二种方法，基于数学规律
int last_deleted_2(int n, int m) {
	if(n < 1 || m < 1) {
		return -1;
	}
	int last = 0;
	for(int i = 2; i<=n;i++) {
		last = (last + m) % i;
	}
	return last;
}



