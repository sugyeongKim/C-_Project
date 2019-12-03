#include "Member.h"
#include "Menu.h"

Menu* menu = new Menu();

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
	cout << "회원 아이디를 입력해주세요: "; cin >> mthis.id;
	y++; menu->gotoxy(x - 10, y);
	cout << "이름을 입력해주세요: "; cin >> mthis.name;
	y++; menu->gotoxy(x - 10, y);
	cout << "나이를 입력해주세요: "; cin >> mthis.age;
	y++; menu->gotoxy(x - 10, y);
	cout << "성별을 입력해주세요: "; cin >> mthis.gender;
	y++; menu->gotoxy(x - 10, y);
	cout << "전화번호를 입력해주세요: "; cin >> mthis.phone;
	y++; menu->gotoxy(x - 10, y);
	cout << "회원가입 완료 되셨습니다";
	y++; menu->gotoxy(x - 10, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	mthis.point = 10;
	mthis.check = true;
	mthis.cnt = 1;
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

void Member::SetMember(member member) {
	mem.push_back(member);
	for (auto& ptr3 : mem)
		cout << ptr3;
}//벡터에 멤버넣기



ostream& operator <<(ostream& os, const member& member){
	os << "아이디: " << member.id << "이름: " << member.name << endl << "나이: " << member.age << endl <<
		"전화번호: " << member.phone << endl << "성별: " << member.gender << endl << "포인트: " << member.point << endl
		<< "이용횟수: " << member.cnt;
	return os;
}
