#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;



class Room {

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
	MYSQL_ROW Row, r; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
	int fields; // �� ����?
	int vip; // vip�� ����
	int base; // �Ϲ� �� ����
	char Query[256], Q[256];
	int x = 50, y = 18, key;//gotoxy�� �ʿ���

	Room();
	~Room();
	Room(char* type, int num, int use, char* uid, char* date_in, char* date_out);
	int Reservation(); //�� ����&�Խ�
	int CheckOut(); //���
	int RoomStatus();
	void ShowRoom(); //���� ����
	int addroom(); //���� �߰�
	int roomservice(); //�뼭��
	int InsertRoomService(int money, int room_num);
	int InsertRoom(char* type);
	int DBconnecter();
	void SetRoom();
	void deleteAllR();
};
#endif // Member_H
