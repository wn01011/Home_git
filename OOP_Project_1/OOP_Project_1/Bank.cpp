#include "Bank.h"

Customer customer[100] = { 0 };
int func = 0;
int custoNum = 0;


int MakeAccount()
{
	int accountNum;
	cout << "계좌번호를 입력하시오: ";
	cin >> accountNum;
	
	return accountNum;
}
void CashInput(int* _cashAmount)
{
	int cashIn, total;
	cout << "입금할 금액을 입력하시오: ";
	cin >> cashIn; 	cout << endl;

	total = *_cashAmount + cashIn;
	*_cashAmount = total;
}
void CashOutput(int* _cashAmount)
{
	int cashOut, total = 0;
	cout << "출금할 금액을 입력하시오: ";
	cin >> cashOut; cout << endl;
	total = *_cashAmount - cashOut;
	if (total < 0)
	{
		cout << "출금할 금액이 모자랍니다." << endl;
		return;
	}
	else
		*_cashAmount = total;
}
void BankManager()
{

	cout << "\n선택할 기능을 고르세요\n" << "1.계좌개설\n2.입금\n3.출금\n4.전체고객 잔액조회\n5.프로그램 종료" << endl;
	cin >> func;
	switch (func)
	{
	case 1:
	{
		customer[custoNum].accountNum = MakeAccount();
		cout << "\n계좌ID: ";
		cin >> customer[custoNum].accountName;
		cout << "계좌생성이 완료되었습니다\n" << "당신의 계좌번호는 " << customer[custoNum].accountNum << " 입니다" << endl;
		++custoNum;
	}	break;
	case 2:
	{
		int custNumInput;
		int myNum = 0;

		cout <<"\n[입\t금]" << "\n당신의 계좌번호를 입력하세요:";
		cin >> custNumInput;
		
		for (int i = 0; i < custoNum; ++i)
			if (customer[i].accountNum == custNumInput)
				myNum = i;

		CashInput(&customer[myNum].cashAmount);
		cout << "\n입금이 완료되었습니다." << endl;

	}	break;
	case 3:
	{
		int custNumInput;
		int myNum = 0;
		cout << "\n[출\t금]" << "당신의 계좌번호를 입력하세요: ";
		cin >> custNumInput;
		for (int i = 0; i < custoNum; ++i)
			if (customer[i].accountNum == custNumInput)
				myNum = i;
	
		CashOutput(&customer[myNum].cashAmount);
		cout << "\n출금이 완료되었습니다." << endl;
	}	break;
	case 4:
	{
		cout << "\n[모든 계좌의 정보 출력]" << endl;
		for (int i = 0; i < 100; ++i)
		{
			if (customer[i].accountNum == 0) break;
			cout << "계좌ID: " << customer[i].accountName << endl;
			cout << "계좌번호 " << customer[i].accountNum << "의 통장잔액은 :" << customer[i].cashAmount << endl;
		}
	}	break;
	case 5:
	{
		cout << "\n프로그램을 종료합니다." << endl;
		return;
	}	break;
	default:
		cout << "\n잘못된 숫자를 입력하셧습니다." << endl;
		break;
	}
	cout << endl;
	BankManager();
}