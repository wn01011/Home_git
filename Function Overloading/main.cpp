#include <iostream>
void SwapExercise();void Swap(int*, int*);void Swap(char*, char*);void Swap(double*, double*);

//함수의 부분적 디폴트값 배정
//부분적 디폴트 값을 배정할 때는 반드시 오른쪽 부터 채워져야한다.
//함수를 호출할때 변수를 왼쪽 부터 채워넣기 때문이다.
void MyFunc(int num1, int num2 = 5, int num3 = 7)
{
	std::cout << num1<<"\t" << num2 << "\t" << num3 << std::endl;
}
int main()
{
	MyFunc(10);
	//res : 10	5	7
	return 0;
}
void SwapExercise()
{
	int num1 = 20, num2 = 30;
	Swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	Swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	Swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;
}
void Swap(int* _num1, int* _num2)
{
	
	int tmp = *_num1;
	*_num1 = *_num2;
	*_num2 = tmp;
}
void Swap(char* _num1, char* _num2)
{
	char tmp = *_num1;
	*_num1 = *_num2;
	*_num2 = tmp;
}
void Swap(double* _num1, double* _num2)
{
	double tmp = *_num1;
	*_num1 = *_num2;
	*_num2 = tmp;
}
