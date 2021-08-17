#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

#define ARY_STEP 10
#define SAFE_DELETE(p) if(p){delete[] p; p = nullptr;}

using namespace std;

class myStack
{
private:
	int curNum = 0;
	int stackOverflow = 1;
	int aryLength = stackOverflow * ARY_STEP;
	int* ary = new int[ARY_STEP] {0};
	int* ary2 = new int[aryLength] {0};
public:
	myStack() { cout << "Constructor\n"; }
	~myStack() { cout << "Destructor\n"; SAFE_DELETE(ary); }

	void Push();
	void Pop();
	void Print();
	void Manager();
};

#endif