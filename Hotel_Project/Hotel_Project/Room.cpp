#include "Room.h"

Room::Room() {
	//일반 호실
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

	//vip룸
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
	
}; //방 예약하기

void Room::CheckIn() {

}; //입실

void Room::CheckOut() {

}; //퇴실

void Room::ShowRoom() {

}; //객실 보기

void Room::addroom() {

}; //객실 추가

void Room::deleteroom() {

}; //객실 삭제/ 없어도되지않을가싶은 메뉴

void Room::roomservice() {

}; //룸서비스

room Room::InsertRoom() {
	room room;
	return room;
}//벡터에 룸넣기
