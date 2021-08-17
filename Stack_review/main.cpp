#include "Stack.h"

void myStack::Push()
{
	cout << curNum << "��° �迭��� �Է�: ";
	cin >> ary[curNum];
	cout << endl;
	++curNum;
}

void myStack::Pop()
{
	if (curNum == 0)
	{
		cout << "������ �迭��Ұ� �����ϴ�." << endl;
		return;
	}
	--curNum;
	cout << curNum << "��° �迭��� Pop" << endl;
}

void myStack::Print()
{
	for (int i = 0; i < curNum; ++i)
	{
		cout << i << "��° �迭��� :" << ary[i] << endl;
	}
}

void myStack::Manager()
{
	int aryLength = stackOverflow * ARY_STEP;
	cout << "\t  MENU\n1.Push  2.Pop  3.Print  4.Exit\n";
	enum menu {
		PUSH = 1,
		POP,
		PRINT,
		EXIT
	};
	int switchNum;

	cin >> switchNum;
	switch (switchNum)
	{
	case PUSH:
	{
		if (curNum >= aryLength)
		{
			++stackOverflow;
			aryLength = stackOverflow * ARY_STEP;
			cout << "Stack is full!\t i'll try to expand the ary, try again\n";
			int* ary2 = new int[aryLength] {0};
			for (int i = 0; i < curNum; ++i)
			{
				ary2[i] = ary[i];
			}
			SAFE_DELETE(ary);
			ary = new int[aryLength] {0};
			for (int i = 0; i < curNum; ++i)
			{
				ary[i] = ary2[i];
			}
			SAFE_DELETE(ary2);
		}
		Push();
		break;
	}
	case POP:
		Pop();
		break;
	case PRINT:
		Print();
		break;
	case EXIT:
		cout << "���α׷��� �����մϴ�\n";
		return;
	default:
		cout << "�߸��� �Է��Դϴ�\n";
		break;
	}
	Manager();
}



int main()
{
	myStack stk;
	stk.Manager();
	return 0;
}