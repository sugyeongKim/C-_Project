#include "Member.h"
#include "Menu.h"

void Member::DeleteMember(member pthis) {
}

void Member::JoinMember() {
	Menu* menu = new Menu();
	system("cls");
	menu->gotoxy(x, y);
	cout << "### ȸ�� ���� ###";
	y++; menu->gotoxy(x - 10, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y);
	cout << "�̸��� �Է����ּ���: "; cin >> mthis.name;
	y++; menu->gotoxy(x - 20, y);
	cout << "���̸� �Է����ּ���: "; cin >> mthis.age;
	y++; menu->gotoxy(x - 20, y);
	cout << "������ �Է����ּ���: "; cin >> mthis.gender;
	y++; menu->gotoxy(x - 20, y);
	cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> mthis.phone;
	y++; menu->gotoxy(x - 20, y);
	cout << "ȸ������ �Ϸ� �Ǽ̽��ϴ�";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	mthis.point = 10;
	mthis.check = true;
	mthis.cnt = 1;
	Member::SetMember(mthis);

	system("PAUSE");
}//ȸ������

void Member::ModifyMember(member pthis) {

}//ȸ����������

void Member::ShowMember() {

}//ȸ�������ֱ�

void Member::SearchMember() {

}//ȸ���˻��ϱ�

void Member::SetMember(member member) {
	mem.push_back(member);
	for (auto& ptr3 : mem)
		cout << ptr3;

}//���Ϳ� ����ֱ�



ostream& operator <<(ostream& os, const member& member){
	os << "�̸�: " << member.name << endl << "����: " << member.age << endl <<
		"��ȭ��ȣ: " << member.phone << endl << "����: " << member.gender;
	return os;
}
