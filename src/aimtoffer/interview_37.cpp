/*
 * interview_37.cpp
 *
 *  Created on: 2019年11月18日
 *      Author: junyao
 */

#include <iostream>
#include <math.h>
using namespace std;

// 定义节点
struct ListNode {
	int val;
	ListNode * pNext;
};
int getListNodeLen(ListNode * pHead) {
	int len = 0;
	ListNode * p = pHead;
	while(p != NULL) {
		len ++;
		p = p->pNext;
	}
	return len;
}
ListNode* findFirstCommon(ListNode* first, ListNode * second) {
	int len1 = getListNodeLen(first);
	int len2 = getListNodeLen(second);
	int diff = abs(len1 - len2);
	ListNode * pLongHead = first;
	ListNode * pShortHead = second;
	if(len1 < len2) {
		pLongHead = second;
		pShortHead = first;
	}
	// 先在长链表上遍历
	for(int i = 0; i<diff; i++) {
		pLongHead = pLongHead->pNext;
	}
	// 再一起遍历
	while(pLongHead != NULL && pShortHead != NULL && pLongHead->val != pShortHead->val) {
		pLongHead = pLongHead->pNext;
		pShortHead = pShortHead->pNext;
	}
	// 返回第一个公共节点
	return pLongHead;
}
