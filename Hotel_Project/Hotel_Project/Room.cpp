#include "Room.h"

Room::Room() {
	//�Ϲ� ȣ��
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 5; j++) {
			r.room_num = i*100 + j;
			r.room_use = 0; 
			r.uid = "";
			r.date_in = "";
			r.date_out = "";
			Com.push_back(r);
		}
	}

	//vip��
	for (int i = 4; i <= 6; i++) {
		for (int j = 1; j <= 5; j++) {
			r.room_num = i*100 + j;
			r.room_use = 0;
			r.uid = "";
			r.date_in = "";
			r.date_out = "";
			Vip.push_back(r);
		}
	}
};

void Room::Reservation() {
	//ȸ���� ������ �� ����.
	//üũ���� �� �ִ� �ּ� �ð��� ���⼭ ����

}; //�� �����ϱ�
//Guest

void Room::CheckIn() {
	//���⼭ ���Ϳ� üũ�νð� ��

}; //�Խ�
//Guest

void Room::CheckOut() {
	//����� A.M.11�ñ���

}; //���
//Guest





void Room::ShowRoom() {

}; //���� ����
//Owner

void Room::addroom() {

}; //���� �߰�
//Owner

void Room::deleteroom() {

}; //���� ����/ ����������������� �޴�

void Room::roomservice() {
	//���İ�Ƽ,ġŲ,����,������,��,��,�����
}; //�뼭��
//Guest

room Room::InsertRoom() {
	room room;
	return room;
}//���Ϳ� ��ֱ�
