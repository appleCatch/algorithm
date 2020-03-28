#include <iostream>
#include <vector>

using namespace std;

void doCombination(char* pStr, int num, vector<char>& res) {
	if (num == 0) {
		// 一轮结束，打印结果即可
		vector<char>::iterator iter = res.begin();
		for (; iter != res.end(); iter++) {
			printf("%c", *iter);
		}
		printf("\n");
		return;
	}
	if (*pStr == '\0') {
		return;
	}
	res.push_back(*pStr);
	doCombination(pStr+1, num-1, res);
	res.pop_back();
	doCombination(pStr+1, num, res);
}

void Combine(char * pStr) {
	if (pStr == NULL) return;
	vector<char> res;
	for (int i = 1; i <= strlen(pStr); i++) {
		doCombination(pStr, i, res);
	}
}

int main() {
	// 定义测试数据
	char testStr[] = {'a', 'b', 'c', 'd', '\0'};
	Combine(testStr);
	system("pause");
	return 0;
}