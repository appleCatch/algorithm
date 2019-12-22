#include <iostream>
#include <set>
#include <vector>

using namespace std;

// stl mutltiset
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& pData, intSet& leastNumbers, int k) {
	leastNumbers.clear();
	if (k < 0 || pData.size() < k) return;
	vector<int>::const_iterator iter = pData.begin();
	for (; iter != pData.end(); iter++) {
		if (leastNumbers.size() < k) leastNumbers.insert(*iter);
		else {
			setIterator greatest = leastNumbers.begin();
			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(greatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

int main() {
	cout << "hello worls" << endl;
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(9);
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(5);

	intSet leastNumbers;

	GetLeastNumbers(v, leastNumbers, 3);

	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); iter++) {
		cout << *iter << endl;
	}
	
	system("pause");
}