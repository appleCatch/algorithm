//
// Created by Byte on 2020/4/6.
//
#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
};

void FindPath(BinaryTreeNode *pRoot, int expectedNum, int currentSum, vector<int> path);

void FindPath(BinaryTreeNode * pRoot, int expectedNum) {
    // parameter check operation
    if (pRoot == NULL) return;
    vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedNum, currentSum, path);
}

void FindPath(BinaryTreeNode *pRoot, int expectedNum, int currentSum, vector<int> path) {
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    bool isLeaf = pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL;
    if (isLeaf && currentSum==expectedNum) {
        printf("A path found: \n");
        vector<int>::iterator it = path.begin();
        for(; it!=path.end(); it++){
            printf("%d\t", *it);
        }
        printf("\n");
    }
    if (pRoot->m_pLeft!=NULL){
        FindPath(pRoot->m_pLeft, expectedNum, currentSum, path);
    }
    if (pRoot->m_pRight != NULL) {
        FindPath(pRoot->m_pRight, expectedNum, currentSum, path);
    }
    // remove current node value when returning to parent node
    currentSum-=pRoot->m_nValue;
    path.pop_back();
}
