#include <iostream>

inline int SQUARE(int x)
{
	return x * x;
}

int main()
{
	int num = 5;

	std::cout << SQUARE(5) << std::endl;
	//res 25;
	return 0;
}