#ifndef _BANK_H_
#define _BANK_H_
#include <iostream>
using namespace std;

int MakeAccount();
typedef struct
{
	int accountNum;
	char accountName[20];
	int cashAmount;
} Customer;
void CashInput(int* _cashAmount);
void CashOutput(int* _cashAmount);
void BankManager();


#endif