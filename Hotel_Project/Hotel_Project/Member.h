#ifndef Member_H
#define Member_H
#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;

struct member {
	char* id;	//ȸ�� ���̵�
	char* name;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	char* phone;	//ȸ�� ��ȭ��ȣ
	char* gender;//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	bool check;		//true�� ȸ��, false�� Ż��
	int cnt;		//�̿�Ƚ��
	int total_amount; //�� �ݾ�
	
	//friend ostream& operator <<(ostream& os, const member& member);
};


class Member {
private:
	member mthis;
	//vector<member> mem;
	char* mid;	//ȸ�� ���̵�
	char* mname;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	char* mphone;	//ȸ�� ��ȭ��ȣ
	char* mgender;//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	int check;		//true�� ȸ��, false�� Ż��
	int cnt;		//�̿�Ƚ��
	int total_amount; //�� �ݾ�

public:
	Member *m;
	Member();
	~Member();
	Member(char* id, char* name, int age, char* phone,
		char* gender, int point, int check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //ȸ����������
	void JoinMember(); //ȸ������?
	int DeleteMember(); //ȸ��Ż��?
	void ShowMember();//��� �����ֱ�
	void SearchMember(); //ȸ���˻�
	void PrintMember(); //ȸ�� ���
	int DBconnecter();
	int SetMember(Member* m); //���Ϳ� ����ֱ�?
	void deleteAllM();
	//void ModifyDB(char* component);


	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?
	char Query[256];

};
#endif // Member_H
