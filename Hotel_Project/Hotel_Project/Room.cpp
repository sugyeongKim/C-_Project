#include "Room.h"

Room::Room(string type, int num, int use, string uid, string date_in, string date_out) {
	this->room_type = type;
	this->room_num = num;
	this->room_use = use;
	this->uid = uid;
	this->date_in = date_in;
	this->date_out = date_out;
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
