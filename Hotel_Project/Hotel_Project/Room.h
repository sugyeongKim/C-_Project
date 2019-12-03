#ifndef ROOM_H
#define ROOM_H

#include "Member.h"
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
public:

	Room();
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
