#include <iostream>

using namespace std;

// ����������ڵ�ṹ��
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*��ȡһ��������ת��������һ���ڵ��ַ*/
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInLeft) {
	if (pNode == NULL) return;
	// �����ǰ�ڵ�����������ǿգ������ݹ��ȡ�����������ڵ�
	BinaryTreeNode* pCurrent = pNode;
	if (pCurrent->m_pLeft != NULL) {
		ConvertNode(pCurrent->m_pLeft, pLastNodeInLeft);
	}
	// Ȼ�󽫵�ǰ�ڵ��������ָ�������ȡ�����ڵ�
	pCurrent->m_pLeft = *pLastNodeInLeft;
	// ��Ϊʱ˫���������Ի�Ҫ��pLastNodeInLeft�ڵ�ָ��ǰ�ڵ�
	if (*pLastNodeInLeft != NULL) {
		(*pLastNodeInLeft)->m_pRight = pCurrent;
	}
	// ��pLastNodeInLeft���и�ֵ��ȡ��ǰ�ڵ�
	*pLastNodeInLeft = pCurrent;

	// �����ҽڵ�
	if (pCurrent->m_pRight != NULL) {
		ConvertNode(pCurrent->m_pRight, pLastNodeInLeft);
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	// �����������һ���ڵ�
	BinaryTreeNode* pLastNodeInLeft = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInLeft);
	// pLastNodeInLeftָ�����˫�������β�ڵ㣬��Ҫ���ص���ͷ�ڵ�
	BinaryTreeNode* pHeadOfTree = pLastNodeInLeft;
	while (pHeadOfTree != NULL && pHeadOfTree->m_pLeft != NULL) {
		pHeadOfTree = pHeadOfTree->m_pLeft;
	}
	return pHeadOfTree;
}

int main() {
	//�������Զ��������������в���
	system("pause");
	return 0;
}