#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
Menu* m;

Room::Room(char* type, int num, int use, char* uid, char* date_in, char* date_out) {
	this->room_num = num;
	this->room_use = use;

	room_type = new char[20];
	uid = new char[20];
	date_in = new char[20];
	date_out = new char[20];

	strcpy_s(this->room_type, 20, type);
	strcpy_s(this->uid, 20, uid);
	strcpy_s(this->date_in, 20, date_in);
	strcpy_s(this->date_out, 20, date_out);
};
Room::Room() {}
Room::~Room(){
	delete room_type, uid, date_in, date_out;
}
void Room::Reservation() {
	//회원만 예약할 수 있음.
	//체크인할 수 있는 최소 시간을 여기서 정함
	system("cls"); 
	x = X, y = 12; //50,12
	m->gotoxy(x, y);
	cout << "### 객실 예약 ###";
	y++; m->gotoxy(x - 20, y - 7);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 20, y - 7);

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
	system("cls");
	x = X, y = 12;
	m->gotoxy(x, y);
	cout << "### 객실 보기 ###";
	y++; m->gotoxy(x - 20, y - 10);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 20, y - 10);
}; //객실 보기
//Owner, guest 이건 둘다 볼수있게 하구 오너모드는 ㄴ더 자세히 객실 현황까지 볼 수 있도록 만들자
//guest는 이거보고 예약하는걸루.

void Room::addroom() {
	system("cls");
	Room::DBconnecter();
	x = X, y = 12;
}; //객실 추가
//Owner

void Room::deleteroom() {

}; //객실 삭제/ 없어도되지않을가싶은 메뉴

void Room::roomservice() {
	//스파게티,치킨,피자,샐러드,빵,술,음료수등등
	int spagetti = 15000, chicken = 23000, pizza = 20000, salad = 14000, wine = 150000,
		bear = 12000, water = 2500;



}; //룸서비스
//Guest

void Room::InsertRoom() {
	Room::DBconnecter();
}

int Room::DBconnecter() {
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, "localhost", "root", "mirim2", "chotel", 3306, NULL, 0);
	if (connection == NULL) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	mysql_query(connection, "set session character_set_connection=euckr");
	mysql_query(connection, "set session character_set_results=euckr");
	mysql_query(connection, "set session character_set_client=euckr");
	return 0;
}

void Room::SetRoom() {
	int i;
	for (i = 0; i < 5; i++){
	sprintf_s(Query, 256, "INSERT INTO ROOM VALUES(%d,%d,NULL,NULL,0,'base');",
		i+101, 0);
	stat = mysql_query(connection, Query);
	}

	for (i = 0; i < 5; i++) {
		sprintf_s(Query, 256, "INSERT INTO ROOM VALUES(%d,%d,NULL,NULL,0,'vip');",
			i + 201, 0);
		stat = mysql_query(connection, Query);
	}

	if (stat != 0) 
		cout << "error: " << mysql_error(&mysql);
	else cout << "success!!" << endl;
}

void Room::deleteAllR() {
	sprintf_s(Query, 256, "delete from room;"); 
	stat = mysql_query(connection, Query);
	if (stat != 0) cout << "error: " << mysql_error(&mysql);
	else cout << "room success!!" << endl;
}