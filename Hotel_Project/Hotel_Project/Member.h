#ifndef Member_H
#define Member_H

#include <iostream>
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>
#pragma comment(lib, "libmysql.lib")

using namespace std;

struct member {
	string id;	//ȸ�� ���̵�
	string name;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	string phone;	//ȸ�� ��ȭ��ȣ
	string gender;//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	bool check;		//true�� ȸ��, false�� Ż��
	int cnt;		//�̿�Ƚ��
	int total_amount; //�� �ݾ�
	friend ostream& operator <<(ostream& os, const member& member);

};


class Member {
private:
	member mthis;
	vector<member> mem;
	string id;	//ȸ�� ���̵�
	string name;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	string phone;	//ȸ�� ��ȭ��ȣ
	string gender;//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	bool check;		//true�� ȸ��, false�� Ż��
	int cnt;		//�̿�Ƚ��
	int total_amount; //�� �ݾ�
public:
	Member(string id, string name, int age, string phone, string gender, int point, bool check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //ȸ����������
	void JoinMember(); //ȸ������?
	void DeleteMember(member pthis); //ȸ��Ż��?
	void ShowMember();//��� �����ֱ�
	void SearchMember(); //ȸ���˻�
	int SetMember(member member); //���Ϳ� ����ֱ�?
	void PrintMember(); //ȸ�� ���
	int DBconnecter();

	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?

};
#endif // Member_H
