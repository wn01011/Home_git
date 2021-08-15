#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;
//�Ű������� const�� ���̰ڴٴ� ���� �� �Լ� �ȿ��� �ش� ���� �ٲ��� �ʰڴٴ� ���̴�.
Point& PntAdder(const Point& _p1, const Point& _p2);
Point tmp = { 0 };

int main(void)
{
	Point p1 = { 1, 2 };
	Point p2 = { 2, 4 };
	Point &p3 = PntAdder(p1,p2);
	cout << p3.xpos << "\t" << p3.ypos << endl;
	printf("%p, %p", &tmp, &p3);

	return 0;
}

Point& PntAdder(const Point& _p1, const Point& _p2)
{
	tmp = { _p1.xpos + _p2.xpos, _p1.ypos + _p2.ypos };
	return tmp;
}
