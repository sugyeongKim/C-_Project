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
	cout << "### È¸¿ø Å»Åð ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; menu->gotoxy(x - 20, y);
	cout << "Å»ÅðÇÒ È¸¿øÀÇ ¾ÆÀÌµð¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> uid;
	finder = uid;
	y++; menu->gotoxy(x - 20, y);

	Member::DBconnecter();

	sprintf_s(Query, 256, "delete from room where id = '%s'", finder);
	stat = mysql_query(connection, Query);

	sprintf_s(Query, 256, "delete from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	if (stat != 0) {
		cout << "ÇØ´çÇÏ´Â ¾ÆÀÌµðÀÇ È¸¿øÀÌ ¾ø½À´Ï´Ù";
		system("PAUSE");
		return 1;
	}
	else {
		cout << "¼º°øÀûÀ¸·Î Å»Åð°¡ µÇ¾ú½À´Ï´Ù";
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
	cout << "### È¸¿ø °¡ÀÔ ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; menu->gotoxy(x - 10, y);
	cout << "È¸¿ø ¾ÆÀÌµð¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> id; i = id;//getchar();
	y++; menu->gotoxy(x - 10, y);


	cout << "ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> pass;  pw = pass;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "ÀÌ¸§À» ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >>  name; n = name;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "³ªÀÌ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> age; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "¼ºº°À» ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> gender;  g = gender;//getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> phone; p = phone; //getchar();
	y += 2; menu->gotoxy(x + 2, y);

	//x = X; y = 5;
	point = 10; // °¡ÀÔº¸³Ê½º 10Á¡
	check = 0; //ÇöÀç ÀÌ¿ëÁßÀÎÁö ¾Æ´ÑÁö~
	cnt = 0; //»ç¿ëÈ½¼ö
	total_amount = 0;
	m = new Member(i, pw, n, age, p, g, point, check, cnt, total_amount);

	Member::SetMember(m);

	y+=2; menu->gotoxy(x - 10, y);
	cout << "È¸¿ø°¡ÀÔ ¿Ï·á µÇ¼Ì½À´Ï´Ù";
	y++; menu->gotoxy(x - 20, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
	system("PAUSE");

	return 0;
}//È¸¿ø°¡ÀÔ
//Guest

int Member::ModifyMember() {
	Member::DBconnecter();
	int choice,chk;
	char user[20], componet[20];// , find[20];
	char* finder=NULL, *find=NULL;
	system("cls");
	x = X; y = 5;
	menu->gotoxy(x, y); 
	cout << "### È¸¿ø Á¤º¸ ¼öÁ¤ ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; menu->gotoxy(x - 20, y);
	cout << "Á¤º¸¸¦ ¼öÁ¤ÇÒ È¸¿ø ¾ÆÀÌµð ÀÔ·Â: "; cin >> user;
		finder = user;
	y++; menu->gotoxy(x - 20, y);

	
	sprintf_s(Query, 256, "select id from member;");
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[0], finder); //¸ÂÀ¸¸é 0
		if (chk == 0) 
			break;
	}
	if (chk == 1) {
		cout << "ÇØ´çÇÏ´Â ¾ÆÀÌµð°¡ ¾ø½À´Ï´Ù";
		system("PAUSE");
		return 1;
	}
	cout << "ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: ";
	cin >> user; 
	find = user; //ºñ¹Ð¹øÈ£

	y++; menu->gotoxy(x - 20, y);
	sprintf_s(Query, 256, "select * from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	Result = mysql_store_result(connection);

	while((Row = mysql_fetch_row(Result)) != NULL) {
		chk = strcmp(Row[1], find); //¸ÂÀ¸¸é 0
		if (chk == 0)
			break;
	}
	if (chk == 1) {
		cout << "ºñ¹Ð¹øÈ£°¡ ¸ÂÁö ¾Ê½À´Ï´ç";
		system("PAUSE");
		return 1;
	}
		

	system("cls");
	x = X; y = 5;
	menu->gotoxy(x-1, y);
	y++; cout << "### È¸¿ø Á¤º¸ ¼öÁ¤ ###";
	menu->gotoxy(x - 32, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 32, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
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
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; 	menu->gotoxy(x - 32, y);
	//}


	y++; 	menu->gotoxy(x - 30, y);
	cout << "º¯°æÇÒ Á¤º¸";
	y++;	menu->gotoxy(x - 30, y);
	cout << "<1> Name, <2> Age, <3> Tel, <4> Gender, <5> exit";
	y++;	menu->gotoxy(x - 30, y);
	cout << ">> "; cin >> choice;
	y++;	menu->gotoxy(x - 30, y);

	switch (choice) {
	case 1:
		cout << "º¯°æÇÒ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set name = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 2:
		cout << "º¯°æÇÒ ³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set age = %d where id = '%s'", atoi(componet), finder);
		mysql_query(connection, Query);
		break;
	case 3:
		cout << "º¯°æÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set tel = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 4:
		cout << "º¯°æÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set gender = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 5:
		cout << "µÚ·Î°¡±â";
		x = X; y = 5;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "º¯°æ ¿Ï·á^^";
	y++; y++; menu->gotoxy(x - 30, y);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
	y += 2; menu->gotoxy(x - 30, y);
	x = X, y = 12;
	system("PAUSE");
	return 1;
}//È¸¿øÁ¤º¸¼öÁ¤
//Guest*/

void Member::ShowMember() {
	system("cls");
	Member::DBconnecter();
	x = X, y = 12;
	sprintf_s(Query, 256, "select * from member order by cnt desc"); //»ç¿ëÇÑ È½¼ö°¡ ¸¹Àº ¼ø¼­´ë·Î Ãâ·Â
	mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);

	menu->gotoxy(x +3, y-6);
	y++; cout << "### È¸¿ø Á¤º¸ ###";
	
	menu->gotoxy(x - 33, y-6);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; 	menu->gotoxy(x - 32, y - 6);
	cout << "    ID        NAME     AGE        TEL       GENDER    POINT   CNT   Total_Amount   ";
	y++; 	menu->gotoxy(x - 33, y - 6);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	y++; 	menu->gotoxy(x-32, y - 6);
	
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		printf("%9s %9s    %3d  %13s    %5s   %4d     %3d   %7d", Row[0], Row[2], atoi(Row[3]), Row[4], Row[5], atoi(Row[6]), atoi(Row[8]), atoi(Row[9]));
		y++; 	menu->gotoxy(x - 33, y -6);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; 	menu->gotoxy(x - 32, y -6);
	}
	mysql_free_result(Result);
	mysql_close(connection);
	x = X, y = 12;
	system("PAUSE");
}//È¸¿øº¸¿©ÁÖ±â
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
}//º¤ÅÍ¿¡ ¸â¹ö³Ö±â

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
	os << "¾ÆÀÌµð: " << member.id << "ÀÌ¸§: " << member.name << endl << "³ªÀÌ: " << member.age << endl <<
		"ÀüÈ­¹øÈ£: " << member.phone << endl << "¼ºº°: " << member.gender << endl << "Æ÷ÀÎÆ®: " << member.point << endl
		<< "ÀÌ¿ëÈ½¼ö: " << member.cnt;
	return os;
}*/
