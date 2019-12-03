#ifndef ROOM_H
#define ROOM_H

#include "Member.h"
#include <iostream>
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>

struct room {
	int room_num; //ȣ��
	int room_use; //���������� �ƴ��� 1�̸� ������
	string uid; //����� ���̵�
	string date_in; //üũ�� ��¥
	string date_out; //üũ�ƿ� ��¥
	//Member** base; //ȸ���� ����

	friend ostream& operator <<(ostream& os, const room& room);
};


class Room {
	room r;
	vector<room> Vip;
	vector<room> Com;

	string room_type; //�� ����
	int room_num; //ȣ��
	int room_use; //���������� �ƴ��� 1�̸� ������
	string uid; //����� ���̵�
	string date_in; //üũ�� ��¥
	string date_out; //üũ�ƿ� ��¥

	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?

	int vip; // vip�� ����
	int base; // �Ϲ� �� ����

public:
	Room(string type, int num, int use, string uid, string date_in, string date_out);
	void Reservation(); //�� �����ϱ�
	void CheckIn(); //�Խ�
	void CheckOut(); //���
	void ShowRoom(); //���� ����
	void addroom(); //���� �߰�
	void deleteroom(); //���� ����
	void roomservice(); //�뼭��
	room InsertRoom();
};
#endif // Member_H
