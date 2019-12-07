#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;



class Room {

	char* room_type; //룸 종류
	int room_num; //호실
	int room_use; //예약중인지 아닌지 1이면 예약중
	char* uid; //사용자 아이디
	char* date_in; //체크인 날짜
	char* date_out; //체크아웃 날짜

	
public:
	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row, r; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 열 정보?
	int vip; // vip룸 갯수
	int base; // 일반 룸 갯수
	char Query[256], Q[256];
	int x = 50, y = 18, key;//gotoxy에 필요함

	Room();
	~Room();
	Room(char* type, int num, int use, char* uid, char* date_in, char* date_out);
	int Reservation(); //방 예약&입실
	int CheckOut(); //퇴실
	int RoomStatus();
	void ShowRoom(); //객실 보기
	int addroom(); //객실 추가
	int roomservice(); //룸서비스
	int InsertRoomService(int money, int room_num);
	int InsertRoom(char* type);
	int DBconnecter();
	void SetRoom();
	void deleteAllR();
};
#endif // Member_H
