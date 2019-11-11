#include <iostream>
#include <vector>
using namespace std;
// 定义树节点结构
typedef struct TreeNode {
    int val;
    vector<TreeNode*> m_children;
} TreeNode;

// 定义查找子节点路径的方法
bool getNodePath(TreeNode * pRoot, TreeNode * pNode, vector<TreeNode*> &path) {
    // 如果两个节点相同，返回true
    if (pRoot == pNode) return true;
    path.push_back(pRoot);
    // 获取子节点的迭代器
    vector<TreeNode*>::iterator i = pRoot->m_children.begin();
    bool found = false;
    while (!found && i < pRoot->m_children.end()) {
        found = getNodePath(*i, pNode, path);
        i++;
    }
	if (!found) {
		path.pop_back();
	}
    return true;
}

// 相当于求两个链表的公共节点
TreeNode * getLastCommonNode(vector<TreeNode*> &path1, vector<TreeNode*> &path2) {
	vector<TreeNode*>::iterator i1 = path1.begin();
	vector<TreeNode*>::iterator i2 = path2.begin();
	TreeNode* pCommon = NULL;
	while (i1 != path1.end() && i2 != path2.end()) {
		if (*i1 == *i2) {
			pCommon = *i1;
		}
		i1++;
		i2++;
	}
	return pCommon;
}

/*
总的方法入口，给出根节点，求两个节点的最低公共祖先
*/
TreeNode * getLastCommonParent(TreeNode * pRoot, TreeNode* pNode1, TreeNode* pNode2) {
	if (pRoot == NULL || pNode1 == NULL || pNode2 != NULL) return NULL;
	vector<TreeNode*> path1;
	vector<TreeNode*> path2;
	getNodePath(pRoot, pNode1, path1);
	getNodePath(pRoot, pNode2, path2);
	return getLastCommonNode(path1, path2);
}

/*
int main() {
	cout << "hello world " << endl;
	system("pause");
	return 0;
}
*/

