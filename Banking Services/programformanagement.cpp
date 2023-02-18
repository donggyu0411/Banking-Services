// ������ ���
// ���� ���� / �Ա� / ��� / ���� / ��ü �� �ܾ� ��ȸ

// ������ ���� ����
// ������ ���� ��ȣ�� �ߺ� x
// �Ա� �� ��ݾ��� ������ 0���� ũ��
// ���� ���� ������ ���� ��ȣ, �� �̸�, ���� �ܾ�, 3������ ���� �ϰ� ����
// �� �̻��� �� ���� ������ ���� �迭 �̿�
// ���� ��ȣ�� ���� ����.

// �������̽� �������� ���α׷� ����
// ------------Menu--------------
// 1. ���� ����
// 2. �Ա�
// 3. ���
// 4. ���� ����
// 5. ���α׷� ����
// 
// ����:

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int NAME_LEN = 30;
const int MAX_CUS_NUM = 100;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE =1 , DEPOSIT , WITHDRAW , INQUIRE , EXIT};

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} ACCOUNT;

ACCOUNT account[MAX_CUS_NUM];
int accNum = 0;

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �Է� �Դϴ�." << endl;
		}
	}

	system("pause");
}

void ShowMenu()
{
	cout << endl;
	cout << "---------------Menu---------------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ���� ���� �ݾ�" << endl;
	cout << "4. ���� ���� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;

}

void MakeAccount()
{
	int num;

	cout << endl;
	cout << "� ������ ���¸� �����Ͻðڽ��ϱ�?" << endl;
	cout << "1.�츮����" << endl << "2.��������" << endl << "3.��������" << endl << "4.��������" << endl << "5.IBK�������" << endl;
	cin >> num;
	cout << endl;

	if (num > 0 && num <= 5)
	{
		cout << num << ".�� ���� ������ �����ϰڽ��ϴ�." << endl;
	}


	cout << "���¹�ȣ�� �Է����ּ���: ";
	cin >> account[accNum].accID;
	cout << "�̸�:";
	cin >> account[accNum].cusName;
	cout << "�Աݾ�: ";
	cin >> account[accNum].balance;

	accNum++;
}

void DepositMoney()
{
	int id;
	int money;

	cout << endl;
	cout << "[�Ա�]" << endl;
	cout << "���� ID: ";
	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (account[i].accID == id)
		{
			cout << "�Աݾ�: ";
			cin >> money;
			account[i].balance += money;
			cout << "�Ա� �Ϸ�: " << endl;
			return;
		}
	}
	cout << "�߸��� ���� ��ȣ �Է�. " << endl;

}

void WithdrawMoney()
{
	int id;
	int money;

	cout << endl;
	cout << "[���]" << endl;
	cout << "���� ID: ";
	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (account[i].accID == id)
		{
			cout << "��ݾ�: ";
			cin >> money;
			if (account[i].balance < money)
			{
				cout << "�ܾ� ����." << endl;
				return;
			}
			else
			{
				account[i].balance -= money;
				cout << "��� �Ϸ�: " << endl;
				return;
			}
		}
	}
	cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}


void ShowAllAccInfo(void)
{
	cout << endl;
	cout << "[���� ����]" << endl;

	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID: " << account[i].accID << endl;
		cout << "�̸� : " << account[i].cusName << endl;
		cout << "�ܾ�: " << account[i].balance << endl;
		cout << endl;
	}
}



