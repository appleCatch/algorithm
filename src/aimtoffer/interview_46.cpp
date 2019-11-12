/*
 * interview_46.cpp
 *
 *  Created on: 2019年11月12日
 *      Author: junyao
 */

#include <iostream>
using namespace std;

// 利用类的初始化过程实现
class Temp {
public:
	Temp(){
		++N;
		SUM += N;
	}

	static void reset(){
		N = 0;
		SUM = 0;
	}
	static unsigned int getSum(){
		return SUM;
	}
private:
	static unsigned int N;
	static unsigned int SUM;
};

unsigned int Temp::N = 0;
unsigned int Temp::SUM = 0;

void solution_1(){
	int n = 4;
	Temp::reset();
	Temp * pArr = new Temp[n];
	delete [] pArr;
	cout << Temp::getSum() << endl;
}

// 利用c++的虚函数完成
class A;
A* array[2]; // 声明包含两个A类型指针的数组

class A {
public:
	virtual unsigned int sum(unsigned int n){
		return 0;
	}
};

class B : public A {
public:
	virtual unsigned int sum(unsigned int n) {
		return array[!!n]->sum(n-1) + n;
	}
};

int solution_2(int n) {
	A a;
	B b;
	array[0] = a;
	array[1] = b;
	return array[1]->sum(n);
}

// 因为c中没有虚函数的概念，所以使用函数指针的方式
typedef unsigned int (*fun)(int n);

unsigned int solution_3_ter(int n) {
	return 0;
}
unsigned int sum_solution3(int n) {
	static fun f[2] = {solution_3_ter, sum_solution3};
	return n + f[!!n](n-1);
}

// 4、利用模板方法实现(这个实现不是特别的明白), 这种方式的限制颇多：
// n的值在编译期就要确定下来，
// n的值不应该太大
template <unsigned int n> struct Sum_solution4 {
	enum Value{
		N = Sum_solution4<n-1>::N + n
	};
};
// 终态的值设定
template <> struct Sum_solution4<1> {
	enum Value{
		N = 1
	};
};
