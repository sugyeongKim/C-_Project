#include "Member.h"
#include "Menu.h"

Menu* menu = new Menu();

void Member::DeleteMember(member pthis) {

}//Guest

void Member::JoinMember() {
	x = X+1, y = 5;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### ȸ�� ���� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 10, y);
	cout << "ȸ�� ���̵� �Է����ּ���: "; cin >> mthis.id;
	y++; menu->gotoxy(x - 10, y);
	cout << "�̸��� �Է����ּ���: "; cin >> mthis.name;
	y++; menu->gotoxy(x - 10, y);
	cout << "���̸� �Է����ּ���: "; cin >> mthis.age;
	y++; menu->gotoxy(x - 10, y);
	cout << "������ �Է����ּ���: "; cin >> mthis.gender;
	y++; menu->gotoxy(x - 10, y);
	cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> mthis.phone;
	y++; menu->gotoxy(x - 10, y);
	cout << "ȸ������ �Ϸ� �Ǽ̽��ϴ�";
	y++; menu->gotoxy(x - 10, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	mthis.point = 10;
	mthis.check = true;
	mthis.cnt = 1;
	Member::SetMember(mthis);

	system("PAUSE");
}//ȸ������
//Guest

int Member::ModifyMember() {
	int choice,i,num;
	string uid;
	system("cls");
	menu->gotoxy(x, y);
	cout << "### ȸ�� ���� ���� ###";
	y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; menu->gotoxy(x - 20, y);
	cout << "������ �����Ͻ� ȸ���� ���̵� �Է����ּ���: "; cin >> uid;
	
	for (i = 0; i < mem.size(); i++) 
		if (uid.compare(mem[i].id)==0) {
			num = i;
			break;
		}


	y++; menu->gotoxy(x - 20, y);
	cout << "<1> �̸�: " << mem[num].name;
	y++; menu->gotoxy(x - 20, y);
	cout << "<2> ����: " << mem[num].age;
	y++; menu->gotoxy(x - 20, y);
	cout << "<3> ����: " << mem[num].gender;
	y++; menu->gotoxy(x - 20, y);
	cout << "<4> ��ȭ��ȣ: " << mem[num].phone;
	y++; menu->gotoxy(x - 20, y);
	cout << "<5> �ڷΰ��� ";
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "������ �׸��� ����ּ���: ";
	cin >> choice;
	y++; y++; menu->gotoxy(x - 20, y);
	switch (choice) {
	case 1:
		cout << "������ �̸��� �Է��ϼ���: ";
		cin >> mem[num].name; break;
	case 2:
		cout << "������ ���̸� �Է��ϼ���: ";
		cin >> mem[num].age; break;
	case 3:
		cout << "������ ������ �Է��ϼ���: ";
		cin >> mem[num].gender; break;
	case 4:
		cout << "������ ��ȭ��ȣ�� �Է��ϼ���: ";
		cin >> mem[num].phone; break;
	case 5:
		cout << "�ڷΰ���";
		x = X; y = 5;
		return 1;
	}
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "���� �Ϸ�^^";
	y++; y++; menu->gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; menu->gotoxy(x + 2, y);
	x = X; y = 5;
	system("PAUSE");
	return 0;
}//ȸ����������
//Guest
 



void Member::ShowMember() {

}//ȸ�������ֱ�
//Owner

void Member::SearchMember() {

}//ȸ���˻��ϱ� �굵 ������ ���� �����
//Owner

void Member::SetMember(member member) {
	mem.push_back(member);
	for (auto& ptr3 : mem)
		cout << ptr3;
}//���Ϳ� ����ֱ�



ostream& operator <<(ostream& os, const member& member){
	os << "���̵�: " << member.id << "�̸�: " << member.name << endl << "����: " << member.age << endl <<
		"��ȭ��ȣ: " << member.phone << endl << "����: " << member.gender << endl << "����Ʈ: " << member.point << endl
		<< "�̿�Ƚ��: " << member.cnt;
	return os;
}
