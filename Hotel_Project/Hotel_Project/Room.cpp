#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
Menu* m;
Member* mem = new Member();

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

int Room::Reservation() {
	//회원만 예약할 수 있음.
	//체크인할 수 있는 최소 시간을 여기서 정함
	int num,n;
	char id[20]; char* i;
	system("cls");
	ShowRoom();
	x = X, y = 18;
	m->gotoxy(x, y);
	m->gotoxy(x - 20, y);
	cout << "예약할 방 번호를 입력해주세요>> "; cin >> num;
	y++; m->gotoxy(x - 20, y);
	cout << "예약자 ID: "; cin >> id; 
	i = id;
	

	//만약 회원중에 같은 id가 있으면 사용횟수와 포인트가 증가하지만 없을경우 그냥 비회원으로 처리됨. 비회원은 사용횟수, 포인트따위 없다ㅎㅎ
	y++; m->gotoxy(x - 20, y);

	Room::DBconnecter();
	sprintf_s(Query, 256, "select * from room where room_num = %d ", num);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "존재하지 않는 호실입니다.";
		system("PAUSE");
		return 1;
	}

	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);
	y++; m->gotoxy(x - 20, y);
	
	if (atoi(Row[1]) == 1) {
		cout << "이미 예약된 호실입니다";
		system("PAUSE");
		return 1;
	}
	if (strcmp(Row[5], "base") == 0) {
		cout << "선택하신 " << Row[0] << "호실은 일반룸입니다";
		y++; m->gotoxy(x - 20, y);

		sprintf_s(Query, 256, "select * from type where room_type = 'base'");
		stat = mysql_query(connection, Query);
		Result = mysql_store_result(connection);
		r = mysql_fetch_row(Result);

		cout << "<1> 하루 숙박 = " << r[1]; y++; m->gotoxy(x - 20, y);
		cout << "<2> 이틀 숙박 = " << r[2]; y++; m->gotoxy(x - 20, y);
		cout << "<3> 장기 숙박 = " << r[3]; y++; m->gotoxy(x - 20, y);

	}
	else {
		cout << "선택하신 " << Row[0] << "호실은 VIP룸입니다";
		y++; m->gotoxy(x - 20, y);

		sprintf_s(Query, 256, "select * from type where room_type = 'vip'");
		stat = mysql_query(connection, Query);
		Result = mysql_store_result(connection);
		r= mysql_fetch_row(Result);

		cout << "<1> 하루 숙박 = " << r[1]; y++; m->gotoxy(x - 20, y);
		cout << "<2> 이틀 숙박 = " << r[2]; y++; m->gotoxy(x - 20, y);
		cout << "<3> 장기 숙박 = " << r[3]; y++; m->gotoxy(x - 20, y);

	}
	m->gotoxy(x - 20, y);
	cout <<">> "; cin >> n; 
	//예약한 멤버 DB 업데이트
	sprintf_s(Query, 256, "select * from member where id = '%s'", i);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	sprintf_s(Query, 256, "update member set point = %d, chk = 1, cnt = %d, total_amount= %d where id='%s'", (atoi(Row[6]) + 50), atoi(Row[8]) + 1, atoi(r[n]), i);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}

	sprintf_s(Q, 256, "select * from room where room_num = %d ", num);
	stat = mysql_query(connection, Q);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	//예약된 방 DB 업데이트!
	sprintf_s(Query, 256, "update room set room_use = 1, user_id = '%s', in_date = current_timestamp, money = %d where room_num = %d",i, atoi(r[n]), atoi(Row[0]));
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else {
	y++; m->gotoxy(x - 20, y);
	cout << "체크인 되었습니다~ " << endl;

	system("PAUSE");
	return 0;
}

}; //방 예약하기
//Guest


int Room::CheckOut() {
	//퇴실은 A.M.11시까지
	//마지막에 총 금액도 표시해주기
	Room::DBconnecter();
	system("cls");
	char id[20]; char* i;
	x = X, y = 5; //50,5
	m->gotoxy(x, y);
	cout << "### 퇴실 ###";
	y++; m->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 20, y);
	cout << "아이디를 입력해주세요>> "; cin >> id;
	i = id;
	sprintf_s(Query, 256, "update member set chk = 0 where id='%s'", i);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	return 0;
	
}; //퇴실
//Guest


int Room::RoomStatus() {
	ShowRoom();
	Room::DBconnecter();
	int num;
	y++; m->gotoxy(x - 20, y);
	cout << "방 번호>> "; cin >> num;

	y++; m->gotoxy(x - 20, y);

	sprintf_s(Query, 256, "select * from room where room_num = %d", num);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	if (atoi(Row[1]) == 0 && atoi(Row[0]) < 199)
		cout << "일반룸 " << Row[0] << "호실 => 미사용" << endl;
	else if (atoi(Row[1]) == 0 && atoi(Row[0]) > 200)
		cout << "vip룸 " << Row[0] << "호실 => 미사용" << endl;
	else if (atoi(Row[1]) == 1 && strcmp(Row[5], "base")){
		cout << "일반룸 " << Row[0] << "호실 => " << Row[2] << "님 사용중";
		y++; m->gotoxy(x - 20, y);
		cout << "현재 금액 : " << Row[4];
		y++; m->gotoxy(x - 20, y);
	}
	else {
		cout << "vip룸 " << Row[0] << "호실 => " << Row[2] << "님 사용중";
		y++; m->gotoxy(x - 20, y);
		cout << "현재 금액 : " << Row[4];
		y++; m->gotoxy(x - 20, y);
	}
	system("PAUSE");
	return 0;
}

void Room::ShowRoom() {
	system("cls");
	int i = 0;
	DBconnecter();
	x = X, y = 5;
	m->gotoxy(x+3, y);
	cout << "### 객실 ###";
	y++; m->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	sprintf_s(Query, 256, "select * from room order by room_type");
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	x = X-2, y=7;

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		if (strcmp(Row[5],"base") == 0) {
			m->gotoxy(x, y++);
			if(atoi(Row[1]) == 0)
				cout << Row[0] << " - □";
			else 
				cout << Row[0] << " - ■";
		}
		else if (strcmp(Row[5], "vip") == 0) {
			if (i == 0) {
				x = X+12;
				y = 7;
				i++;
			}
			m->gotoxy(x, y++);
			if (atoi(Row[1]) == 0)
				cout << Row[0] << " - □";
			else
				cout << Row[0] << " - ■";
		}
	}
	x = X;m->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 20, y);
	//system("PAUSE");
}; //객실 보기
//Owner, guest 이건 둘다 볼수있게 하구 오너모드는 ㄴ더 자세히 객실 현황까지 볼 수 있도록 만들자
//guest는 이거보고 예약하는걸루.

int Room::addroom() {
	system("cls");
	char* t = NULL, b[] = "base", v[] = "vip";
	int cnt, choice;
	//Room::DBconnecter();
	x = X, y = 5;
	m->gotoxy(x, y);
	cout << "### 객실 가격 ###";
	y++; m->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 20, y);
	cout << "<1> 일반룸 , <2> VIP룸";
	y++; m->gotoxy(x - 20, y);
	cout << "가격을 변경할 객실을 선택하세요 ";
	cout << ">>"; cin >> choice;

	switch (choice)
	{
	case 1: t = b;
		break;
	case 2: t = v;
		break;
	}
	cnt = InsertRoom(t);
	if (cnt == 1) return 0;
	else return 1;

}; //객실 갯수 추가
//Owner


int Room::roomservice() {
	//지금 예약중인 방을 불러와서,, 
	//스파게티,치킨,피자,샐러드,빵,술,음료수등등
	int spagetti = 15000, chicken = 23000, pizza = 20000, salad = 14000, wine = 150000,
		bear = 12000, water = 2500, rnum = 0, num = 0, money;
	system("cls");
	ShowRoom();
	x = X, y = 18;
	m->gotoxy(x, y);
	m->gotoxy(x - 20, y);
	cout << "룸서비스를 시킬 방을 고르세요>> "; cin >> rnum;
	y++; m->gotoxy(x - 20, y);

	Room::DBconnecter();
	sprintf_s(Query, 256, "select room_use from room where room_num = %d ", rnum);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	if (atoi(Row[0]) == 0) {
		cout << "미사용중인 호실입니다." << endl;
		system("PAUSE");
		return 1;
	}

	system("cls");
	x = X, y = 5; //50,5
	m->gotoxy(x, y);
	cout << "### 룸서비스 ###";
	y++; m->gotoxy(x - 30, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 30, y);
	cout << "스파게티";  m->gotoxy(x - 20, y);
	cout << "<1> 까르보나라 (20000원) <2> 로제(19000원) <3> 알리오올리오(20000원)";
	y++; y++; m->gotoxy(x - 30, y);
	cout << "치킨"; m->gotoxy(x - 20, y);
	cout << "<4> BHC황금올리브 (21000원) <5> 해바라기핫후라이드 (21000원)";
	y++; y++; m->gotoxy(x - 30, y);
	cout << "음료";  m->gotoxy(x - 20, y);
	cout << "<6> 와인 (12000원) <7> 콜라 (12000원) <8> 환타 (10000원)";	
	y++; m->gotoxy(x - 30, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; m->gotoxy(x - 30, y);
	cout << ">> "; cin >> num;
	y++; m->gotoxy(x - 30, y);

	switch (num)
	{
	case 1: money = 20000;  break;
	case 2:money = 19000; break;
	case 3:money = 20000; break;  
	case 4:money = 21000; break;
	case 5:money = 21000; break;
	case 6:money = 12000; break;
	case 7:money = 12000; break;
	case 8:money = 10000; break;
		break;
	}

	InsertRoomService(money, rnum);
	return 0;
}; //룸서비스
//Guest
//5
int Room::InsertRoomService(int money, int room_num) {
	Room::DBconnecter();
	sprintf_s(Query, 256, "select * from room where room_num = %d ", room_num);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);


	sprintf_s(Query, 256, "update room set money = %d where room_num = %d", atoi(Row[4])+money, room_num);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else {
		sprintf_s(Query, 256, "update member set total_amount = %d where id = '%s'", atoi(Row[4]) + money, Row[2]);
		stat = mysql_query(connection, Query);
		if (stat != 0) {
			cout << "error: " << mysql_error(&mysql);
			return 1;
		}
		else{
		cout << "룸서비스가 제공되었습니다~" << endl;
		system("PAUSE");
		}
	}
	return 0;
}
int Room::InsertRoom(char* type) { 
	Room::DBconnecter();
	int one, two, three;
	//체크인?
	sprintf_s(Query, 256, "select * from type where room_type = '%s' ", type);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	y++; m->gotoxy(x - 20, y);
	cout << "하루 = " << Row[1] << " => "; cin >> one;	y++; m->gotoxy(x - 20, y);
	cout << "이틀 = " << Row[2] << " => "; cin >> two;	y++; m->gotoxy(x - 20, y);
	cout << "장기 = " << Row[3] << " => "; cin >> three;	y++; m->gotoxy(x - 20, y);

	sprintf_s(Query, 256, "update type set one=%d, two=%d, more=%d where room_type = '%s' ", one,two,three, type);
	stat = mysql_query(connection, Query); 
	if (connection == NULL) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else {
		cout << "변경되었습니다" << endl;
		system("PAUSE");
		return 0;
	}

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
	for (i = 0; i < 10; i++){
	sprintf_s(Query, 256, "INSERT INTO ROOM VALUES(%d,%d,NULL,NULL,0,'base');",
		i+101, 0);
	stat = mysql_query(connection, Query);
	}

	for (i = 0; i < 10; i++) {
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