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
	int room_num; //호실
	int room_use; //예약중인지 아닌지 1이면 예약중
	string uid; //사용자 아이디
	string date_in; //체크인 날짜
	string date_out; //체크아웃 날짜
	//Member** base; //회원과 연결

	friend ostream& operator <<(ostream& os, const room& room);
};


class Room {
	room r;
	vector<room> Vip;
	vector<room> Com;

	string room_type; //룸 종류
	int room_num; //호실
	int room_use; //예약중인지 아닌지 1이면 예약중
	string uid; //사용자 아이디
	string date_in; //체크인 날짜
	string date_out; //체크아웃 날짜

	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 열 정보?

	int vip; // vip룸 갯수
	int base; // 일반 룸 갯수

public:
	Room(string type, int num, int use, string uid, string date_in, string date_out);
	void Reservation(); //방 예약하기
	void CheckIn(); //입실
	void CheckOut(); //퇴실
	void ShowRoom(); //객실 보기
	void addroom(); //객실 추가
	void deleteroom(); //객실 삭제
	void roomservice(); //룸서비스
	room InsertRoom();
};
#endif // Member_H
