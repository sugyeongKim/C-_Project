#include "Room.h"

Room::Room() {
	//�Ϲ� ȣ��
	for (int i = 100; i <= 200; i=+100) {
		for (int j = 1; j <= 5; j++) {
			r.room_num = i + j;
			r.room_use = 0; 
			string user = NULL;
			string date_inL = NULL;
			string date_out = NULL;
			Com.push_back(r);
		}
	}

	//vip��
	for (int i = 300; i <= 400; i = +100) {
		for (int j = 1; j <= 5; j++) {
			r.room_num = i + j;
			r.room_use = 0;
			string user = NULL;
			string date_inL = NULL;
			string date_out = NULL;
			Vip.push_back(r);
		}
	}
	
};

void Room::Reservation() {
	
}; //�� �����ϱ�

void Room::CheckIn() {

}; //�Խ�

void Room::CheckOut() {

}; //���

void Room::ShowRoom() {

}; //���� ����

void Room::addroom() {

}; //���� �߰�

void Room::deleteroom() {

}; //���� ����/ ����������������� �޴�

void Room::roomservice() {

}; //�뼭��

room Room::InsertRoom() {
	room room;
	return room;
}//���Ϳ� ��ֱ�
