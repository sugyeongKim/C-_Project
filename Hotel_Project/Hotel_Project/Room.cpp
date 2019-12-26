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
	//ȸ���� ������ �� ����.
	//üũ���� �� �ִ� �ּ� �ð��� ���⼭ ����
	int num,n;
	char id[20]; char* i;
	system("cls");
	ShowRoom();
	x = X, y = 18;
	m->gotoxy(x, y);
	m->gotoxy(x - 20, y);
	cout << "������ �� ��ȣ�� �Է����ּ���>> "; cin >> num;
	y++; m->gotoxy(x - 20, y);
	cout << "������ ID: "; cin >> id; 
	i = id;
	

	//���� ȸ���߿� ���� id�� ������ ���Ƚ���� ����Ʈ�� ���������� ������� �׳� ��ȸ������ ó����. ��ȸ���� ���Ƚ��, ����Ʈ���� ���٤���
	y++; m->gotoxy(x - 20, y);

	Room::DBconnecter();
	sprintf_s(Query, 256, "select * from room where room_num = %d ", num);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "�������� �ʴ� ȣ���Դϴ�.";
		system("PAUSE");
		return 1;
	}

	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);
	y++; m->gotoxy(x - 20, y);
	
	if (atoi(Row[1]) == 1) {
		cout << "�̹� ����� ȣ���Դϴ�";
		system("PAUSE");
		return 1;
	}
	if (strcmp(Row[5], "base") == 0) {
		cout << "�����Ͻ� " << Row[0] << "ȣ���� �Ϲݷ��Դϴ�";
		y++; m->gotoxy(x - 20, y);

		sprintf_s(Query, 256, "select * from type where room_type = 'base'");
		stat = mysql_query(connection, Query);
		Result = mysql_store_result(connection);
		r = mysql_fetch_row(Result);

		cout << "<1> �Ϸ� ���� = " << r[1]; y++; m->gotoxy(x - 20, y);
		cout << "<2> ��Ʋ ���� = " << r[2]; y++; m->gotoxy(x - 20, y);
		cout << "<3> ��� ���� = " << r[3]; y++; m->gotoxy(x - 20, y);

	}
	else {
		cout << "�����Ͻ� " << Row[0] << "ȣ���� VIP���Դϴ�";
		y++; m->gotoxy(x - 20, y);

		sprintf_s(Query, 256, "select * from type where room_type = 'vip'");
		stat = mysql_query(connection, Query);
		Result = mysql_store_result(connection);
		r= mysql_fetch_row(Result);

		cout << "<1> �Ϸ� ���� = " << r[1]; y++; m->gotoxy(x - 20, y);
		cout << "<2> ��Ʋ ���� = " << r[2]; y++; m->gotoxy(x - 20, y);
		cout << "<3> ��� ���� = " << r[3]; y++; m->gotoxy(x - 20, y);

	}
	m->gotoxy(x - 20, y);
	cout <<">> "; cin >> n; 
	//������ ��� DB ������Ʈ
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

	//����� �� DB ������Ʈ!
	sprintf_s(Query, 256, "update room set room_use = 1, user_id = '%s', in_date = current_timestamp, money = %d where room_num = %d",i, atoi(r[n]), atoi(Row[0]));
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else {
	y++; m->gotoxy(x - 20, y);
	cout << "üũ�� �Ǿ����ϴ�~ " << endl;

	system("PAUSE");
	return 0;
}

}; //�� �����ϱ�
//Guest


int Room::CheckOut() {
	//����� A.M.11�ñ���
	//�������� �� �ݾ׵� ǥ�����ֱ�
	Room::DBconnecter();
	system("cls");
	char id[20]; char* i;
	x = X, y = 5; //50,5
	m->gotoxy(x, y);
	cout << "### ��� ###";
	y++; m->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; m->gotoxy(x - 20, y);
	cout << "���̵� �Է����ּ���>> "; cin >> id;
	i = id;
	sprintf_s(Query, 256, "update member set chk = 0 where id='%s'", i);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	return 0;
	
}; //���
//Guest


int Room::RoomStatus() {
	ShowRoom();
	Room::DBconnecter();
	int num;
	y++; m->gotoxy(x - 20, y);
	cout << "�� ��ȣ>> "; cin >> num;

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
		cout << "�Ϲݷ� " << Row[0] << "ȣ�� => �̻��" << endl;
	else if (atoi(Row[1]) == 0 && atoi(Row[0]) > 200)
		cout << "vip�� " << Row[0] << "ȣ�� => �̻��" << endl;
	else if (atoi(Row[1]) == 1 && strcmp(Row[5], "base")){
		cout << "�Ϲݷ� " << Row[0] << "ȣ�� => " << Row[2] << "�� �����";
		y++; m->gotoxy(x - 20, y);
		cout << "���� �ݾ� : " << Row[4];
		y++; m->gotoxy(x - 20, y);
	}
	else {
		cout << "vip�� " << Row[0] << "ȣ�� => " << Row[2] << "�� �����";
		y++; m->gotoxy(x - 20, y);
		cout << "���� �ݾ� : " << Row[4];
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
	cout << "### ���� ###";
	y++; m->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";

	sprintf_s(Query, 256, "select * from room order by room_type");
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	x = X-2, y=7;

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		if (strcmp(Row[5],"base") == 0) {
			m->gotoxy(x, y++);
			if(atoi(Row[1]) == 0)
				cout << Row[0] << " - ��";
			else 
				cout << Row[0] << " - ��";
		}
		else if (strcmp(Row[5], "vip") == 0) {
			if (i == 0) {
				x = X+12;
				y = 7;
				i++;
			}
			m->gotoxy(x, y++);
			if (atoi(Row[1]) == 0)
				cout << Row[0] << " - ��";
			else
				cout << Row[0] << " - ��";
		}
	}
	x = X;m->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; m->gotoxy(x - 20, y);
	//system("PAUSE");
}; //���� ����
//Owner, guest �̰� �Ѵ� �����ְ� �ϱ� ���ʸ��� ���� �ڼ��� ���� ��Ȳ���� �� �� �ֵ��� ������
//guest�� �̰ź��� �����ϴ°ɷ�.

int Room::addroom() {
	system("cls");
	char* t = NULL, b[] = "base", v[] = "vip";
	int cnt, choice;
	//Room::DBconnecter();
	x = X, y = 5;
	m->gotoxy(x, y);
	cout << "### ���� ���� ###";
	y++; m->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; m->gotoxy(x - 20, y);
	cout << "<1> �Ϲݷ� , <2> VIP��";
	y++; m->gotoxy(x - 20, y);
	cout << "������ ������ ������ �����ϼ��� ";
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

}; //���� ���� �߰�
//Owner


int Room::roomservice() {
	//���� �������� ���� �ҷ��ͼ�,, 
	//���İ�Ƽ,ġŲ,����,������,��,��,��������
	int spagetti = 15000, chicken = 23000, pizza = 20000, salad = 14000, wine = 150000,
		bear = 12000, water = 2500, rnum = 0, num = 0, money;
	system("cls");
	ShowRoom();
	x = X, y = 18;
	m->gotoxy(x, y);
	m->gotoxy(x - 20, y);
	cout << "�뼭�񽺸� ��ų ���� ������>> "; cin >> rnum;
	y++; m->gotoxy(x - 20, y);

	Room::DBconnecter();
	sprintf_s(Query, 256, "select room_use from room where room_num = %d ", rnum);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	if (atoi(Row[0]) == 0) {
		cout << "�̻������ ȣ���Դϴ�." << endl;
		system("PAUSE");
		return 1;
	}

	system("cls");
	x = X, y = 5; //50,5
	m->gotoxy(x, y);
	cout << "### �뼭�� ###";
	y++; m->gotoxy(x - 30, y);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������";
	y++; m->gotoxy(x - 30, y);
	cout << "���İ�Ƽ";  m->gotoxy(x - 20, y);
	cout << "<1> ������� (20000��) <2> ����(19000��) <3> �˸����ø���(20000��)";
	y++; y++; m->gotoxy(x - 30, y);
	cout << "ġŲ"; m->gotoxy(x - 20, y);
	cout << "<4> BHCȲ�ݿø��� (21000��) <5> �عٶ�����Ķ��̵� (21000��)";
	y++; y++; m->gotoxy(x - 30, y);
	cout << "����";  m->gotoxy(x - 20, y);
	cout << "<6> ���� (12000��) <7> �ݶ� (12000��) <8> ȯŸ (10000��)";	
	y++; m->gotoxy(x - 30, y);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������";
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
}; //�뼭��
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
		cout << "�뼭�񽺰� �����Ǿ����ϴ�~" << endl;
		system("PAUSE");
		}
	}
	return 0;
}
int Room::InsertRoom(char* type) { 
	Room::DBconnecter();
	int one, two, three;
	//üũ��?
	sprintf_s(Query, 256, "select * from type where room_type = '%s' ", type);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	y++; m->gotoxy(x - 20, y);
	cout << "�Ϸ� = " << Row[1] << " => "; cin >> one;	y++; m->gotoxy(x - 20, y);
	cout << "��Ʋ = " << Row[2] << " => "; cin >> two;	y++; m->gotoxy(x - 20, y);
	cout << "��� = " << Row[3] << " => "; cin >> three;	y++; m->gotoxy(x - 20, y);

	sprintf_s(Query, 256, "update type set one=%d, two=%d, more=%d where room_type = '%s' ", one,two,three, type);
	stat = mysql_query(connection, Query); 
	if (connection == NULL) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else {
		cout << "����Ǿ����ϴ�" << endl;
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