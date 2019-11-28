#include "Menu.h"

void Menu::gotoxy(int m_x, int m_y) {
	COORD Pos = { m_x - 1, m_y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Menu::KeyPress() {
	int key;
	cin >> key;
	return key;
}

int Menu::Start() {
	system("cls");
	x = X - 13; y = 5;
	Hotel_draw(x, y);
	x = X; y = Y;
	menu_draw(x, y);
	x = X; y = 5;
	return KeyPress();
}

void Menu::Hotel_draw(int m_x, int m_y) {
	gotoxy(m_x, m_y);
	printf("**     **  *********  ********  ********  **");
	m_y++; gotoxy(m_x, m_y);
	printf("**     **  **     **     **     **        **");
	m_y++; gotoxy(m_x, m_y);
	printf("*********  **     **     **     ********  **");
	m_y++; gotoxy(m_x, m_y);
	printf("**     **  **     **     **     **        **");
	m_y++; gotoxy(m_x, m_y);
	printf("**     **  *********     **     ********  ******");
	m_y++; gotoxy(m_x, m_y);
}

void Menu::menu_draw(int m_x, int m_y) {
	gotoxy(m_x, m_y - 1);//x=50, y=17
	cout << "������������������������������������";
	gotoxy(m_x, m_y); //x=50,y=18
	cout << "| <1> Owner mode |";
	m_y++; gotoxy(m_x, m_y); //y=19
	cout << "| <2> Guest mode |";
	m_y++; gotoxy(m_x, m_y);
	cout << "| <3> Exit       |";
	m_y++; gotoxy(m_x, m_y);
	cout << "������������������������������������" << endl;
	m_y++; gotoxy(m_x + 7, m_y);
	cout << ">> ";
}

int Menu::Owner_Menu() {
	system("cls");
	gotoxy(x, y);
	cout << "### Owner Mode ###";
	y++; gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; gotoxy(x + 2, y);
	cout << "<1> ���� ����";
	y += 2; gotoxy(x + 2, y);
	cout << "<2> ���� ��Ȳ";
	y += 2; gotoxy(x + 2, y);
	cout << "<3> ȸ�� ����";
	y += 2; gotoxy(x + 2, y);
	cout << "<4> ��������";
	y++; gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; gotoxy(x + 2, y);
	cout << ">> ";
	x = X; y = 5;
	return KeyPress();
}

int Menu::Guest_Menu() {
	system("cls");
	gotoxy(x, y);
	cout << "### Guest Mode ###";
	y++; gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������";
	y++; gotoxy(x + 2, y);
	cout << "<1> ȸ�� ����";
	y += 2; gotoxy(x + 2, y);
	cout << "<2> ȸ�� ���� ����";
	y += 2; gotoxy(x + 2, y);
	cout << "<3> ȸ�� Ż��";
	y += 2; gotoxy(x + 2, y);
	cout << "<4> ����";
	y += 2; gotoxy(x + 2, y);
	cout << "<5> üũ��";
	y += 2; gotoxy(x + 2, y);
	cout << "<6> üũ�ƿ�";
	y += 2; gotoxy(x + 2, y);
	cout << "<7> ��������";
	y++; gotoxy(x - 20, y);
	cout << "������������������������������������������������������������������������������������������������������������������" << endl;
	y += 2; gotoxy(x + 2, y);
	cout << ">> ";
	x = X; y = 5;
	return KeyPress();
}

void Menu::ownerShow() {
	while ((key = Owner_Menu()) != 4) {
		switch (key) {
		case 1:
			while ((key = Room_Set()) != 3) {
				switch (key) {
				case 1:Room::addroom(); break;
				case 2:Room::deleteroom(); break;
				case 3:break;
				}
			}
			break;
		case 2: Room::ShowRoom(); break;
		case 3: Room::Reservation(); break;
		case 4: break;
		}
	}
}

void Menu::guestShow() {
	while ((key = Guest_Menu()) != 7) {
		switch (key) {
		case 1:Member::JoinMember(); break;
		case 2:
			//while (modifyMember() != 1); break;
		//case 3:deleteMember(); break;
		//case 4:ReserveRoom(); break;
		case 5: CheckIn(); break;
		case 6: CheckOut(); break;
		case 7: break;
		}
	}
}

	int Menu::Room_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### ���� ���� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x + 2, y);
		cout << "<1> ���� �߰�";
		y += 2; gotoxy(x + 2, y);
		cout << "<2> ���� ����";
		y += 2; gotoxy(x + 2, y);
		cout << "<3> ��������";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}