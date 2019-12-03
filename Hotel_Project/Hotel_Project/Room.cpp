#include "Room.h"

Room::Room() {
	//일반 호실
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

	//vip룸
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
