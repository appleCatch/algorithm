#include <iostream>

using namespace std;

// ���������麯��
bool checkInvalidArray(int* numbers, int length) {
	bool inputInvalid = false;
	if (NULL == numbers || length <= 0) inputInvalid = true;
	return inputInvalid;
}

// ����ҵ��������Ƿ���ȷ
bool checkMoreThanHalf(int* numbers, int length, int number) {
	int times = 0;
	for (int i = 0; i < length; i++) {
		if (number == numbers[i]) times++;
	}
	if (times * 2 <= length) {
		return false;
	}
	return true;
}

// �����������
int MoreThanHalfNumber(int* numbers, int len) {
	if (!checkInvalidArray(numbers, len))return 0;
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < len; i++) {
		if (times == 0) {
			times = 1;
			result = numbers[i];
		}
		else if (result == numbers[i]) {
			times++;
		}
		else {
			times--;
		}
	}

	if (!checkMoreThanHalf(numbers, len, result)) {

		return 0;
	}

	return result;
}
int main() {
	cout << "hello world..." << endl;
	system("pause");
}