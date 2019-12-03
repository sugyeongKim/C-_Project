#include "Member.h"
#include "Menu.h"

Menu* menu;

Member::Member(string id, string name, int age, string phone, string gender, int point, bool check, int cnt, int total_amount) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->phone = phone;
	this->gender = gender;
	this->point = point;
	this->check = check;
	this->cnt = cnt;
	this->total_amount = total_amount;
}
void Member::DeleteMember(member pthis) {

}//Guest

void Member::JoinMember() {
	x = X+1, y = 5;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### 회원 가입 ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; menu->gotoxy(x - 10, y);
	cout << "회원 아이디를 입력해주세요: "; cin >> id;
	y++; menu->gotoxy(x - 10, y);
	cout << "이름을 입력해주세요: "; cin >> name;
	y++; menu->gotoxy(x - 10, y);
	cout << "나이를 입력해주세요: "; cin >> age;
	y++; menu->gotoxy(x - 10, y);
	cout << "성별을 입력해주세요: "; cin >> gender;
	y++; menu->gotoxy(x - 10, y);
	cout << "전화번호를 입력해주세요: "; cin >> phone;
	y++; menu->gotoxy(x - 10, y);
	cout << "회원가입 완료 되셨습니다";
	y++; menu->gotoxy(x - 10, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	point = 10;
	check = true;
	cnt = 1;
	Member::SetMember(mthis);

	system("PAUSE");
}//회원가입
//Guest

int Member::ModifyMember() {
	int choice,i,num;
	string uid;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### 회원 정보 수정 ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; menu->gotoxy(x - 20, y);
	cout << "정보를 수정하실 회원의 아이디를 입력해주세요: "; cin >> uid;
	
	for (i = 0; i < mem.size(); i++) 
		if (uid.compare(mem[i].id)==0) {
			num = i;
			break;
		}


	y++; menu->gotoxy(x - 20, y);
	cout << "<1> 이름: " << mem[num].name;
	y++; menu->gotoxy(x - 20, y);
	cout << "<2> 나이: " << mem[num].age;
	y++; menu->gotoxy(x - 20, y);
	cout << "<3> 성별: " << mem[num].gender;
	y++; menu->gotoxy(x - 20, y);
	cout << "<4> 전화번호: " << mem[num].phone;
	y++; menu->gotoxy(x - 20, y);
	cout << "<5> 뒤로가기 ";
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "수정할 항목을 골라주세요: ";
	cin >> choice;
	y++; y++; menu->gotoxy(x - 20, y);
	switch (choice) {
	case 1:
		cout << "변경할 이름을 입력하세요: ";
		cin >> mem[num].name; break;
	case 2:
		cout << "변경할 나이를 입력하세요: ";
		cin >> mem[num].age; break;
	case 3:
		cout << "변경할 성별을 입력하세요: ";
		cin >> mem[num].gender; break;
	case 4:
		cout << "변경할 전화번호를 입력하세요: ";
		cin >> mem[num].phone; break;
	case 5:
		cout << "뒤로가기";
		x = X; y = 5;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "변경 완료^^";
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	system("PAUSE");
	return 0;
}//회원정보수정
//Guest
 



void Member::ShowMember() {

}//회원보여주기
//Owner

void Member::SearchMember() {

}//회원검색하기 얘도 넣을까 말까 고민중
//Owner

int Member::SetMember(member member) {
	//mem.push_back(member);
	//for (auto& ptr3 : mem)
	//	cout << ptr3;

	const char* Query = "INSERT INTO MEMBER VALUES(";
	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		//return 1;
	}

	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		for (int i = 0; i < fields; i++)
			cout << Row[i] << ",";
		cout << endl;
	}
	


}//벡터에 멤버넣기

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

ostream& operator <<(ostream& os, const member& member){
	os << "아이디: " << member.id << "이름: " << member.name << endl << "나이: " << member.age << endl <<
		"전화번호: " << member.phone << endl << "성별: " << member.gender << endl << "포인트: " << member.point << endl
		<< "이용횟수: " << member.cnt;
	return os;
}
