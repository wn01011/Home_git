#include "Bank.h"

Customer customer[100] = { 0 };
int func = 0;
int custoNum = 0;


int MakeAccount()
{
	int accountNum;
	cout << "���¹�ȣ�� �Է��Ͻÿ�: ";
	cin >> accountNum;
	
	return accountNum;
}
void CashInput(int* _cashAmount)
{
	int cashIn, total;
	cout << "�Ա��� �ݾ��� �Է��Ͻÿ�: ";
	cin >> cashIn; 	cout << endl;

	total = *_cashAmount + cashIn;
	*_cashAmount = total;
}
void CashOutput(int* _cashAmount)
{
	int cashOut, total = 0;
	cout << "����� �ݾ��� �Է��Ͻÿ�: ";
	cin >> cashOut; cout << endl;
	total = *_cashAmount - cashOut;
	if (total < 0)
	{
		cout << "����� �ݾ��� ���ڶ��ϴ�." << endl;
		return;
	}
	else
		*_cashAmount = total;
}
void BankManager()
{

	cout << "\n������ ����� ������\n" << "1.���°���\n2.�Ա�\n3.���\n4.��ü�� �ܾ���ȸ\n5.���α׷� ����" << endl;
	cin >> func;
	switch (func)
	{
	case 1:
	{
		customer[custoNum].accountNum = MakeAccount();
		cout << "\n����ID: ";
		cin >> customer[custoNum].accountName;
		cout << "���»����� �Ϸ�Ǿ����ϴ�\n" << "����� ���¹�ȣ�� " << customer[custoNum].accountNum << " �Դϴ�" << endl;
		++custoNum;
	}	break;
	case 2:
	{
		int custNumInput;
		int myNum = 0;

		cout <<"\n[��\t��]" << "\n����� ���¹�ȣ�� �Է��ϼ���:";
		cin >> custNumInput;
		
		for (int i = 0; i < custoNum; ++i)
			if (customer[i].accountNum == custNumInput)
				myNum = i;

		CashInput(&customer[myNum].cashAmount);
		cout << "\n�Ա��� �Ϸ�Ǿ����ϴ�." << endl;

	}	break;
	case 3:
	{
		int custNumInput;
		int myNum = 0;
		cout << "\n[��\t��]" << "����� ���¹�ȣ�� �Է��ϼ���: ";
		cin >> custNumInput;
		for (int i = 0; i < custoNum; ++i)
			if (customer[i].accountNum == custNumInput)
				myNum = i;
	
		CashOutput(&customer[myNum].cashAmount);
		cout << "\n����� �Ϸ�Ǿ����ϴ�." << endl;
	}	break;
	case 4:
	{
		cout << "\n[��� ������ ���� ���]" << endl;
		for (int i = 0; i < 100; ++i)
		{
			if (customer[i].accountNum == 0) break;
			cout << "����ID: " << customer[i].accountName << endl;
			cout << "���¹�ȣ " << customer[i].accountNum << "�� �����ܾ��� :" << customer[i].cashAmount << endl;
		}
	}	break;
	case 5:
	{
		cout << "\n���α׷��� �����մϴ�." << endl;
		return;
	}	break;
	default:
		cout << "\n�߸��� ���ڸ� �Է��ϼ˽��ϴ�." << endl;
		break;
	}
	cout << endl;
	BankManager();
}