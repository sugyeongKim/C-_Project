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
	//회원만 예약할 수 있음.
	//체크인할 수 있는 최소 시간을 여기서 정함

}; //방 예약하기
//Guest

void Room::CheckIn() {
	//여기서 벡터에 체크인시간 들어감

}; //입실
//Guest

void Room::CheckOut() {
	//퇴실은 A.M.11시까지

}; //퇴실
//Guest





void Room::ShowRoom() {

}; //객실 보기
//Owner

void Room::addroom() {

}; //객실 추가
//Owner

void Room::deleteroom() {

}; //객실 삭제/ 없어도되지않을가싶은 메뉴

void Room::roomservice() {
	//스파게티,치킨,피자,샐러드,빵,술,음료수
}; //룸서비스
//Guest

room Room::InsertRoom() {
	room room;
	return room;
}//벡터에 룸넣기
