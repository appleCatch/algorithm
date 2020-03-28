#include <iostream>

using namespace std;

//����ṹ������
struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

// ��һ������pNext��������
void CloneNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;

		pNode = pCloned->m_pNext;
	}
}

// �ƶ�sibling�ڵ�λ��
void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL) {
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

// ��ԭ�����������ֿ�
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;
	//�����������ͷ�ڵ㸳ֵ
	if (pNode != NULL) {
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneHead->m_pNext;
		pNode = pNode->m_pNext;
	}
	while (pNode != NULL) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

void Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	ComplexListNode* pCloneHead = ReconnectNodes(pHead);
}

int main() {
	//��Ҫ������������ʵ��
	//ֱ�ӵ���Clone����
	system("pause");
	return 0;
}