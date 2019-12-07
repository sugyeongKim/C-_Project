#ifndef Member_H
#define Member_H
#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;


class Member {
private:
	char* mid;	//ȸ�� ���̵�
	char* mpw; // ȸ�� ��й�ȣ
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
	Member(char* id, char* password, char* name, int age, char* phone,
		char* gender, int point, int check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //ȸ����������
	int JoinMember(); //ȸ������?
	int DeleteMember(); //ȸ��Ż��?
	void ShowMember();//��� �����ֱ�
	int checkMember(char* id); //ȸ�� üũ
	int DBconnecter();
	int SetMember(Member* m); //
	void deleteAllM();


	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?
	char Query[256];

};
#endif // Member_H
