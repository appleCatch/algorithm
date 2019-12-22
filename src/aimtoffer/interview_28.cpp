#include <iostream>

using namespace std;

//真正的排列逻辑
void Permutation(char* pStr, char* begin) {
	if (*begin == '\0') printf("%s\n", pStr);
	else {
		for (char* pCh = begin; *pCh != '\0'; pCh++) {
			char temp = *pCh;
			*pCh = *begin;
			*begin = temp;
			Permutation(pStr, begin + 1);
			// exchange
			temp = *pCh;
			*pCh = *begin;
			*begin = temp;
		}
	}
}

void Permutation(char* pChar) {
	if (pChar == NULL) return;
	Permutation(pChar, pChar);
}

int main() {
	cout << "hello world" << endl;
	char str[4] = { 'a','b','c','\0'};
	Permutation(str);
	system("pause");
}