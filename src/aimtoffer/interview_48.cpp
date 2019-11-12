/*
 * interview_48.cpp
 *
 *  Created on: 2019年11月11日
 *      Author: junyao
 */
#include <iostream>
using namespace std;
// 利用私有的构造函数和析构函数，设计不可继承的类
class SealedClass1 {
public:
	static SealedClass1 * newInstance() {
		return new SealedClass1();
	}
	static void deleteInstance(SealedClass1* instance) {
		delete instance;
	}

private:
	SealedClass1(){}
	~ SealedClass1(){}
};

// 利用虚拟继承实现
template <typename T> class MakeSealed {
	friend T;
private:
	MakeSealed(){}
	~ MakeSealed() {}
};

// 利用虚拟继承，因为sealedClass2是makeSealed的友元属性，所以可以直接调用
// makeSealed的构造方法和析构方法。
// 但是sealedClass2的字类却不是makesealed的友元属性，所以不能创建实例对象。
class SealedClass2 : virtual public MakeSealed<SealedClass2> {
public:
	SealedClass2(){}
	~ SealedClass2(){}
};

//int main(){
//	SealedClass2 class2;
//	SealedClass1* class1 = SealedClass1::newInstance();
//	return 0;
//}



