#include <iostream>

using namespace std;

//定义结构体数据
struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

// 第一步根据pNext复制链表
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

// 移动sibling节点位置
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

// 将原链表和新链表分开
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;
	//将复制链表的头节点赋值
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
	//需要以上三步即可实现
	//直接调用Clone方法
	system("pause");
	return 0;
}