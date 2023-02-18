// 구현할 기능
// 계좌 개설 / 입금 / 출금 / 적금 / 전체 고객 잔액 조회

// 구현시 유의 사항
// 통장의 계좌 번호는 중복 x
// 입금 및 출금액은 무조건 0보다 크다
// 고객의 계좌 정보는 계좌 번호, 고객 이름, 고객의 잔액, 3가지만 저장 하고 관리
// 둘 이상의 고객 정보 저장을 위해 배열 이용
// 계좌 번호는 정수 형태.

// 인터페이스 형식으로 프로그램 실행
// ------------Menu--------------
// 1. 계좌 개설
// 2. 입급
// 3. 출금
// 4. 계좌 정보
// 5. 프로그램 종료
// 
// 선택:

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
		cout << "선택: ";
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
			cout << "잘못된 입력 입니다." << endl;
		}
	}

	system("pause");
}

void ShowMenu()
{
	cout << endl;
	cout << "---------------Menu---------------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 적금 예상 금액" << endl;
	cout << "4. 계좌 정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;

}

void MakeAccount()
{
	int num;

	cout << endl;
	cout << "어떤 은행의 계좌를 개설하시겠습니까?" << endl;
	cout << "1.우리은행" << endl << "2.국민은행" << endl << "3.신한은행" << endl << "4.농협은행" << endl << "5.IBK기업은행" << endl;
	cin >> num;
	cout << endl;

	if (num > 0 && num <= 5)
	{
		cout << num << ".의 계좌 개설을 시작하겠습니다." << endl;
	}


	cout << "계좌번호를 입력해주세요: ";
	cin >> account[accNum].accID;
	cout << "이름:";
	cin >> account[accNum].cusName;
	cout << "입금액: ";
	cin >> account[accNum].balance;

	accNum++;
}

void DepositMoney()
{
	int id;
	int money;

	cout << endl;
	cout << "[입금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (account[i].accID == id)
		{
			cout << "입금액: ";
			cin >> money;
			account[i].balance += money;
			cout << "입금 완료: " << endl;
			return;
		}
	}
	cout << "잘못된 계좌 번호 입력. " << endl;

}

void WithdrawMoney()
{
	int id;
	int money;

	cout << endl;
	cout << "[출금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (account[i].accID == id)
		{
			cout << "출금액: ";
			cin >> money;
			if (account[i].balance < money)
			{
				cout << "잔액 부족." << endl;
				return;
			}
			else
			{
				account[i].balance -= money;
				cout << "출금 완료: " << endl;
				return;
			}
		}
	}
	cout << "잘못된 계좌 번호 입력. " << endl;
}


void ShowAllAccInfo(void)
{
	cout << endl;
	cout << "[계좌 정보]" << endl;

	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌 ID: " << account[i].accID << endl;
		cout << "이름 : " << account[i].cusName << endl;
		cout << "잔액: " << account[i].balance << endl;
		cout << endl;
	}
}



