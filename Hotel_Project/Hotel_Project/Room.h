#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;
/*struct room {
	int room_num; //ȣ��
	int room_use; //���������� �ƴ��� 1�̸� ������
	string uid; //����� ���̵�
	string date_in; //üũ�� ��¥
	string date_out; //üũ�ƿ� ��¥
	//Member** base; //ȸ���� ����

	friend ostream& operator <<(ostream& os, const room& room);
};*/


class Room {
	//room r;
	//vector<room> Vip;
	//vector<room> Com;

	char* room_type; //�� ����
	int room_num; //ȣ��
	int room_use; //���������� �ƴ��� 1�̸� ������
	char* uid; //����� ���̵�
	char* date_in; //üũ�� ��¥
	char* date_out; //üũ�ƿ� ��¥

	
public:
	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?
	int vip; // vip�� ����
	int base; // �Ϲ� �� ����
	char Query[256];
	int x = 50, y = 18, key;//gotoxy�� �ʿ���

	Room();
	~Room();
	Room(char* type, int num, int use, char* uid, char* date_in, char* date_out);
	void Reservation(); //�� �����ϱ�
	void CheckIn(); //�Խ�
	void CheckOut(); //���
	void ShowRoom(); //���� ����
	void addroom(); //���� �߰�
	void deleteroom(); //���� ����
	void roomservice(); //�뼭��
	void InsertRoom();
	int DBconnecter();
	void SetRoom();
	void deleteAllR();
};
#endif // Member_H
