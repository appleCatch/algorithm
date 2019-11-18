/*
 * interview_39.cpp
 *
 *  Created on: 2019年11月18日
 *      Author: junyao
 */
#include <iostream>
using namespace std;

// 定义节点
typedef struct Node {
	int value;
	Node * left;
	Node * right;
};
// 求树的最大高度
int treeDepth(Node * head) {
	if(head == NULL) return 0;
	int leftHeight = treeDepth(head->left);
	int rightHeight = treeDepth(head->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 重复的遍历的方式，判断一棵树是否为平衡二叉树
bool isBalanceTree(Node *pRoot) {
	if(pRoot == NULL) return true;
	int left = treeDepth(pRoot->left);
	int right = treeDepth(pRoot->right);
	int diff = left - right;
	if(diff <= 1 && diff >= -1) {
		return isBalanceTree(pRoot->left) && isBalanceTree(pRoot->right);
	} else {
		return false;
	}
}

// 利用后续遍历实现平衡二叉树的判断
bool isBalanceTree(Node * pRoot, int * depth) {
	if(pRoot == NULL) {
		*depth = 0;
		return true;
	}
	int left, right;
	if(isBalanceTree(pRoot->left, &left) && isBalanceTree(pRoot->right, &right)) {
		int diff = left - right;
		if(diff <= 1 && diff >= -1) {
			*depth = left > right ? left+1 : right + 1;
			return true;
		}
	}
	return false;
}

bool isBalance2(Node * pRoot) {
	int depth = 0;
	return isBalanceTree(pRoot, &depth);
}

