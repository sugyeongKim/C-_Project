#include "Member.h"
#include "Menu.h"

void Member::DeleteMember(member pthis) {
}

void Member::JoinMember() {
	Menu* menu = new Menu();
	system("cls");
	menu->gotoxy(x, y);
	cout << "### 회원 가입 ###";
	y++; menu->gotoxy(x - 10, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; menu->gotoxy(x - 20, y);
	cout << "이름을 입력해주세요: "; cin >> mthis.name;
	y++; menu->gotoxy(x - 20, y);
	cout << "나이를 입력해주세요: "; cin >> mthis.age;
	y++; menu->gotoxy(x - 20, y);
	cout << "성별을 입력해주세요: "; cin >> mthis.gender;
	y++; menu->gotoxy(x - 20, y);
	cout << "전화번호를 입력해주세요: "; cin >> mthis.phone;
	y++; menu->gotoxy(x - 20, y);
	cout << "회원가입 완료 되셨습니다";
	y++; menu->gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	mthis.point = 10;
	mthis.check = true;
	mthis.cnt = 1;
	Member::SetMember(mthis);

	system("PAUSE");
}//회원가입

void Member::ModifyMember(member pthis) {

}//회원정보수정

void Member::ShowMember() {

}//회원보여주기

void Member::SearchMember() {

}//회원검색하기

void Member::SetMember(member member) {
	mem.push_back(member);
	for (auto& ptr3 : mem)
		cout << ptr3;

}//벡터에 멤버넣기



ostream& operator <<(ostream& os, const member& member){
	os << "이름: " << member.name << endl << "나이: " << member.age << endl <<
		"전화번호: " << member.phone << endl << "성별: " << member.gender;
	return os;
}
