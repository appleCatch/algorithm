#include <iostream>

using namespace std;

// 定义二叉树节点结构体
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*获取一个子树的转换后的最后一个节点地址*/
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInLeft) {
	if (pNode == NULL) return;
	// 如果当前节点的左子树不是空，继续递归获取左子树的最后节点
	BinaryTreeNode* pCurrent = pNode;
	if (pCurrent->m_pLeft != NULL) {
		ConvertNode(pCurrent->m_pLeft, pLastNodeInLeft);
	}
	// 然后将当前节点的左子树指向上面获取的最后节点
	pCurrent->m_pLeft = *pLastNodeInLeft;
	// 因为时双向链表，所以还要让pLastNodeInLeft节点指向当前节点
	if (*pLastNodeInLeft != NULL) {
		(*pLastNodeInLeft)->m_pRight = pCurrent;
	}
	// 对pLastNodeInLeft进行赋值，取当前节点
	*pLastNodeInLeft = pCurrent;

	// 处理右节点
	if (pCurrent->m_pRight != NULL) {
		ConvertNode(pCurrent->m_pRight, pLastNodeInLeft);
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	// 左子树的最后一个节点
	BinaryTreeNode* pLastNodeInLeft = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInLeft);
	// pLastNodeInLeft指向的是双向链表的尾节点，需要返回的是头节点
	BinaryTreeNode* pHeadOfTree = pLastNodeInLeft;
	while (pHeadOfTree != NULL && pHeadOfTree->m_pLeft != NULL) {
		pHeadOfTree = pHeadOfTree->m_pLeft;
	}
	return pHeadOfTree;
}

int main() {
	//构建测试二叉搜索树，进行测试
	system("pause");
	return 0;
}