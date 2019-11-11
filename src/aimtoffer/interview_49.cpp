#include <iostream>
using namespace std;

// 定义全局的状态枚举
enum G_status {
	k_valid = 0,
	k_invalid
};
int g_status = k_valid;

int charToInt(const char * str) {
	g_status = k_invalid;
	long long num = 0;
	// 对第一位的符号位判断
	if (str != NULL && *str != '\0') {
		bool minus = false;
		if (*str == '+') {
			str++;
		} else if (*str == '-') {
			minus = true;
			str++;
		}
		// 是否为结束标记
		if (*str == '\0') {
			return 0;
		}
		int flag = minus ? -1 : 1;
		while (*str != '\0') {
			if (*str >= '0' && *str <= '9') {
				num = num * 10 + flag * (*str - '0');
				str++;
			} else {
				break;
			}
		}
	}
	if (*str == '\0') {
		g_status = k_valid;
	}
	return (int)num;
}

/*
int main() {
	const char * str = "1234";
	int num = charToInt(str);
	cout << num << "," << g_status << endl;
	system("pause");
	return 0;
}
*/
