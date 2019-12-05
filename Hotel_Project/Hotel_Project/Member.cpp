#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
Menu* menu;

Member::Member(char* id, char* name, int age, char* phone, char* gender,
	int point, int check, int cnt, int total_amount) {
	this->age = age;
	this->point = point;
	this->check = check;
	this->cnt = cnt;
	this->total_amount = total_amount;

	mid = new char[20];
	mname = new char[20];
	mphone = new char[20];
	mgender = new char[10];

	strcpy_s(this->mid, 20, id);
	strcpy_s(this->mname, 20, name);
	strcpy_s(this->mphone, 20, phone);
	strcpy_s(this->mgender, 10, gender);
}

Member::Member(){}
Member::~Member() {
	delete mid, mname, mphone, mgender;
}
int Member::DeleteMember() {
	int choice, i, num;
	char uid[20], componet[20];// , find[20];
	char* finder;
	system("cls");
	menu->gotoxy(x, y - 7);
	cout << "### ȸ�� Ż�� ###";
	y++; menu->gotoxy(x - 20, y - 10);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y - 10);
	cout << "Ż���� ȸ���� ���̵� �Է����ּ���: "; cin >> uid;
	finder = uid;

	Member::DBconnecter();
	sprintf_s(Query, 256, "delete from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "�ش��ϴ� ���̵��� ȸ���� �����ϴ�";
		system("PAUSE");
		return 1;
	}
	else return 0;
}//Guest

void Member::JoinMember() {
	//Member* m = new Member();
	char id[20], name[20], gender[20], phone[20];
	char* i=NULL, *n = NULL, *g = NULL, *p = NULL;
	int age,point,cnt;
	bool check;
	x = X+1, y = 5;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### ȸ�� ���� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 10, y);
	cout << "ȸ�� ���̵� �Է����ּ���: "; cin >> id; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "�̸��� �Է����ּ���: "; cin >>  name; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "���̸� �Է����ּ���: "; cin >> age; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "������ �Է����ּ���: "; cin >> gender; //getchar();
	y++; menu->gotoxy(x - 10, y);
	cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> phone; //getchar();
	y+=2; menu->gotoxy(x - 10, y);
	cout << "ȸ������ �Ϸ� �Ǽ̽��ϴ�";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	point = 10;
	check = 0;
	cnt = 0;
	total_amount = 10000;
	i = id; g = gender;
	n = name; p = phone;
	m = new Member(i, n, age, p, g, point, check, cnt, total_amount);
	
	Member::SetMember(m);

	system("PAUSE");
}//ȸ������
//Guest

int Member::ModifyMember() {
	int choice,i,num;
	char uid[20], componet[20];// , find[20];
	char* finder;
	system("cls");
	menu->gotoxy(x, y-10); 
	cout << "### ȸ�� ���� ���� ###";
	y++; menu->gotoxy(x - 20, y- 10);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y- 10);
	cout << "������ �����Ͻ� ȸ���� ���̵� �Է����ּ���: "; cin >> uid;
		finder = uid;
	

	Member::DBconnecter();
	sprintf_s(Query, 256, "select * from member where id = '%s'", finder);
	stat = mysql_query(connection, Query);
	
	if (stat != 0) { 
		cout << "�ش��ϴ� ���̵��� ȸ���� �����ϴ�";
		system("PAUSE"); 
		return 1; 
	}

	system("cls");
	menu->gotoxy(x, y - 10);
	y++; cout << "### ȸ�� ���� ���� ###";
	menu->gotoxy(x - 32, y - 10);
	cout << "+-----------------------------------------------------------------------------------+";
	y++; 	menu->gotoxy(x - 32, y - 10);
	cout << "    ID        NAME     AGE        TEL       GENDER   POINT   CHK    CNT  Total_Amount   ";
	y++; 	menu->gotoxy(x - 33, y - 10);
	cout << "+-----------------------------------------------------------------------------------+";
	y++; 	menu->gotoxy(x - 32, y - 10);
	
	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);

	while ((Row = mysql_fetch_row(Result)) != NULL) {
		printf("%9s %9s    %3d  %13s    %5s   %3d    %3d    %3d    %3d", Row[0], Row[1], atoi(Row[2]), Row[3], Row[4], atoi(Row[5]), atoi(Row[6]), atoi(Row[7]), atoi(Row[8]));
		y++; 	menu->gotoxy(x - 33, y - 10);
		cout << "+-----------------------------------------------------------------------------------+";
		y++; 	menu->gotoxy(x - 32, y - 10);
	}


	y++; 	menu->gotoxy(x - 30, y - 10);
	cout << "������ ����";
	y++;	menu->gotoxy(x - 30, y - 10);
	cout << "<1> Name, <2> Age, <3> Tel, <4> Gender, <5> exit";
	y++;	menu->gotoxy(x - 30, y - 10);
	cout << ">> "; cin >> choice;
	y++;	menu->gotoxy(x - 30, y - 10);

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
		sprintf_s(Query, 256, "update member set age = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 3:
		cout << "������ ������ �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set gender = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query);
		break;
	case 4:
		cout << "������ ��ȭ��ȣ�� �Է��ϼ���: ";
		cin >> componet;
		sprintf_s(Query, 256, "update member set tel = '%s' where id = '%s'", componet, finder);
		mysql_query(connection, Query); 
		break;
	case 5:
		cout << "�ڷΰ���";
		x = X, y = 12;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 30, y - 7);
	cout << "���� �Ϸ�^^";
	y++; y++; menu->gotoxy(x - 30, y - 7);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x - 30, y-7);
	x = X, y = 12;
	system("PAUSE");
	return 1;
}//ȸ����������
//Guest*/

//void Member::ModifyDB(char* component) {}

void Member::ShowMember() {
	system("cls");
	Member::DBconnecter();
	x = X, y = 12;
	sprintf_s(Query, 256, "select * from member");
	mysql_query(connection, Query);
	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);

	menu->gotoxy(x - 33, y-10);
	cout << "+-----------------------------------------------------------------------------------+";
	y++; 	menu->gotoxy(x - 32, y - 10);
	cout << "    ID        NAME     AGE        TEL       GENDER   POINT   CHK    CNT  Total_Amount   ";
	y++; 	menu->gotoxy(x - 33, y - 10);
	cout << "+-----------------------------------------------------------------------------------+";
	y++; 	menu->gotoxy(x-32, y - 10);
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		printf("%9s %9s    %3d  %13s    %5s   %3d    %3d    %3d    %3d", Row[0], Row[1], atoi(Row[2]), Row[3], Row[4], atoi(Row[5]), atoi(Row[6]), atoi(Row[7]), atoi(Row[8]));
		y++; 	menu->gotoxy(x - 33, y -10);
		cout << "+-----------------------------------------------------------------------------------+";
		y++; 	menu->gotoxy(x - 32, y -10);
	}
	x = X, y = 12;
	system("PAUSE");
}//ȸ�������ֱ�
//Owner


void Member::SearchMember() {

}//ȸ���˻��ϱ� �굵 ������ ���� �����
//Owner

int Member::SetMember(Member* m) {
	//mem.push_back(member);
	//for (auto& ptr3 : mem)
	//	cout << ptr3;
	//cout << "*****" << endl;
	//Member::DBconnecter();
	//cout << "%%%%%%" << endl;
	//char Query[256]; //�������� �����ߴ�
	sprintf_s(Query, 256,"INSERT INTO MEMBER VALUES('%s','%s',%d,'%s','%s',%d,%d,%d,%d);",
				m->mid, m->mname, m->age, m->mphone, m->mgender,m->point, m->check,m->cnt, m->total_amount);

	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	else cout << "success!!" << endl;

	strcpy(Query, "select * from member");
	mysql_query(connection, Query);

	Result = mysql_store_result(connection); 
	fields = mysql_num_fields(Result);//��
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		for (int i = 0; i < fields; i++) {
		}
			
	}
	return 0;
}//���Ϳ� ����ֱ�

void Member::deleteAllM() {
	sprintf_s(Query, 256, "delete from member;");
	stat = mysql_query(connection, Query);
	if (stat != 0) cout << "error: " << mysql_error(&mysql);
	else cout << "meber success!!" << endl;
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
