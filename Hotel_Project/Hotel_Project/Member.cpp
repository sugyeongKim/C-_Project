#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
Menu* menu;

Member::Member(char* id, char* password, char* name, int age, char* phone, char* gender,
	int point, int check, int cnt, int total_amount) {
	this->age = age;
	this->point = point;
	this->check = check;
	this->cnt = cnt;
	this->total_amount = total_amount;

	mid = new char[20];
	mpw = new char[20];
	mname = new char[20];
	mphone = new char[20];
	mgender = new char[10];

	strcpy_s(this->mid, 20, id);
	strcpy_s(this->mpw, 20, password);
	strcpy_s(this->mname, 20, name);
	strcpy_s(this->mphone, 20, phone);
	strcpy_s(this->mgender, 10, gender);
}

Member::Member(){}
Member::~Member() {
	delete mid, mpw, mname, mphone, mgender;
}

int Member::DeleteMember() {
	char uid[20]; 
	char* finder;
	system("cls");
	
	x = X; y = 5;
	menu->gotoxy(x, y);
	cout << "### ȸ�� Ż�� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y);
	cout << "Ż���� ȸ���� ���̵� �Է����ּ���: "; cin >> uid;
	finder = uid;
	y++; menu->gotoxy(x - 20, y);

	Member::DBconnecter();

	sprintf_s(Query, 256, "delete from room where id = '%s'", finder);
	stat = mysql_query(connection, Query);

	sprintf_s(Query, 256, "delete from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "�ش��ϴ� ���̵��� ȸ���� �����ϴ�";
		system("PAUSE");
		return 1;
	}
	else {
		cout << "���������� Ż�� �Ǿ����ϴ�";
		system("PAUSE");
		return 0; 
	}
}//Guest

int Member::JoinMember() {
	//Member* m = new Member();
	Member::DBconnecter();
	char id[20], pass[20], name[20], gender[20], phone[20];
	char* i=NULL, *pw=NULL , *n = NULL, *g = NULL, *p = NULL;
	int age,point,cnt;
	bool check;
	x = X; y = 5;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### ȸ�� ���� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 10, y);
	cout << "ȸ�� ���̵� �Է����ּ���: "; cin >> id; i = id;//getchar();
	y++; menu->gotoxy(x - 10, y);


	cout << "��й�ȣ�� �Է����ּ���: "; cin >> pass;  pw = pass;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "�̸��� �Է����ּ���: "; cin >>  name; n = name;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "���̸� �Է����ּ���: "; cin >> age; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "������ �Է����ּ���: "; cin >> gender;  g = gender;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> phone; p = phone; //getchar();
	y += 2; menu->gotoxy(x + 2, y);

	//x = X; y = 5;
	point = 10; // ���Ժ��ʽ� 10��
	check = 0; //���� �̿������� �ƴ���~
	cnt = 0; //���Ƚ��
	total_amount = 0;
	m = new Member(i, pw, n, age, p, g, point, check, cnt, total_amount);

	Member::SetMember(m);

	y+=2; menu->gotoxy(x - 10, y);
	cout << "ȸ������ �Ϸ� �Ǽ̽��ϴ�";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	system("PAUSE");

	return 0;
}//ȸ������
//Guest

int Member::ModifyMember() {
	Member::DBconnecter();
	int choice,chk;
	char user[20], componet[20];// , find[20];
	char* finder=NULL, *find=NULL;
	system("cls");
	x = X; y = 5;
	menu->gotoxy(x, y); 
	cout << "### ȸ�� ���� ���� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y);
	cout << "������ ������ ȸ�� ���̵� �Է�: "; cin >> user;
		finder = user;
	y++; menu->gotoxy(x - 20, y);

	
	sprintf_s(Query, 256, "select id from member;");
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[0], finder); //������ 0
		if (chk == 0) 
			break;
	}
	if (chk == 1) {
		cout << "�ش��ϴ� ���̵� �����ϴ�";
		system("PAUSE");
		return 1;
	}
	cout << "��й�ȣ�� �Է����ּ���: ";
	cin >> user; 
	find = user; //��й�ȣ

	y++; menu->gotoxy(x - 20, y);
	sprintf_s(Query, 256, "select * from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[1], find); //������ 0
		if (chk == 0)
			break;
	}
	if (chk == 1) {
		cout << "��й�ȣ�� ���� �ʽ��ϴ�";
		system("PAUSE");
		return 1;
	}
		

	system("cls");
	x = X; y = 5;
	menu->gotoxy(x-1, y);
	y++; cout << "### ȸ�� ���� ���� ###";
	menu->gotoxy(x - 32, y);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	y++; 	menu->gotoxy(x - 32, y);

	sprintf_s(Query, 256, "select * from member where id = '%s' and password='%s'", finder, find);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	///Row = mysql_fetch_row(Result);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Row = mysql_fetch_row(Result);
	//while ((Row = mysql_fetch_row(Result)) != NULL) {
	printf("%9s %9s    %3d  %13s    %5s   %4d     %3d   %7d", Row[0], Row[2], atoi(Row[3]), Row[4], Row[5], atoi(Row[6]), atoi(Row[8]), atoi(Row[9]));
		y++; 	menu->gotoxy(x - 33, y);
		cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
		y++; 	menu->gotoxy(x - 32, y);
	//}


	y++; 	menu->gotoxy(x - 30, y);
	cout << "������ ����";
	y++;	menu->gotoxy(x - 30, y);
	cout << "<1> Name, <2> Age, <3> Tel, <4> Gender, <5> exit";
	y++;	menu->gotoxy(x - 30, y);
	cout << ">> "; cin >> choice;
	y++;	menu->gotoxy(x - 30, y);

	switch (choice) {
	case 1:
		cout << "������ �̸��� �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set name = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 2:
		cout << "������ ���̸� �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set age = %d where id = '%s'", atoi(componet), finder);
		mysql_query(connection, Query);
		break;
	case 3:
		cout << "������ ��ȭ��ȣ�� �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set tel = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 4:
		cout << "������ ������ �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set gender = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 5:
		cout << "�ڷΰ���";
		x = X; y = 5;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "���� �Ϸ�^^";
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x - 30, y);
	x = X, y = 12;
	system("PAUSE");
	return 1;
}//ȸ����������
//Guest*/

void Member::ShowMember() {
	system("cls");
	Member::DBconnecter();
	x = X, y = 12;
	sprintf_s(Query, 256, "select * from member order by cnt desc"); //����� Ƚ���� ���� ������� ���
	mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);

	menu->gotoxy(x +3, y-6);
	y++; cout << "### ȸ�� ���� ###";
	
	menu->gotoxy(x - 33, y-6);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	y++; 	menu->gotoxy(x - 32, y - 6);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 33, y - 6);
	cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	y++; 	menu->gotoxy(x-32, y - 6);
	
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		printf("%9s %9s    %3d  %13s    %5s   %4d     %3d   %7d", Row[0], Row[2], atoi(Row[3]), Row[4], Row[5], atoi(Row[6]), atoi(Row[8]), atoi(Row[9]));
		y++; 	menu->gotoxy(x - 33, y -6);
		cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
		y++; 	menu->gotoxy(x - 32, y -6);
	}
	mysql_free_result(Result);
	mysql_close(connection);
	x = X, y = 12;
	system("PAUSE");
}//ȸ�������ֱ�
//Owner



int Member::checkMember(char* i) {
	Member::DBconnecter();
	//cout << "$$$";
	sprintf_s(Query, 256, "select * from member where id = '%s'", i);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	cout << Row[6] << "," << Row[8];
	sprintf_s(Query, 256, "update member set point = %d, chk = 1, cnt = %d", atoi(Row[6]) + 50, atoi(Row[8])+1);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	Result = mysql_store_result(connection);
	Row = mysql_fetch_row(Result);

	mysql_free_result(Result);
	mysql_close(connection);
	
	return 0;
}
int Member::SetMember(Member* m) {
	//Member::DBconnecter();
	sprintf_s(Query, 256,"INSERT INTO MEMBER VALUES('%s','%s', '%s' ,%d,'%s','%s',%d,%d,%d,%d);",
				m->mid, m->mpw, m->mname, m->age, m->mphone, m->mgender,m->point, m->check,m->cnt, m->total_amount);

	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else cout << "success!!" << endl;

	return 0;
}//���Ϳ� ����ֱ�

void Member::deleteAllM() {
	sprintf_s(Query, 256, "delete from member;");
	stat = mysql_query(connection, Query);
	if (stat != 0) cout << "error: " << mysql_error(&mysql);
	else cout << "member success!!" << endl;
}

int Member::DBconnecter() {
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


/*ostream& operator <<(ostream& os, const member& member){
	os << "���̵�: " << member.id << "�̸�: " << member.name << endl << "����: " << member.age << endl <<
		"��ȭ��ȣ: " << member.phone << endl << "����: " << member.gender << endl << "����Ʈ: " << member.point << endl
		<< "�̿�Ƚ��: " << member.cnt;
	return os;
}*/
