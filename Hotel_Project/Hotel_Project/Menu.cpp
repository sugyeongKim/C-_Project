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
	cout << "━━━━━━━━━━━━━━━━━━";
	gotoxy(m_x, m_y); //x=50,y=18
	cout << "| <1> Owner mode |";
	m_y++; gotoxy(m_x, m_y); //y=19
	cout << "| <2> Guest mode |";
	m_y++; gotoxy(m_x, m_y);
	cout << "| <3> Exit       |";
	m_y++; gotoxy(m_x, m_y);
	cout << "━━━━━━━━━━━━━━━━━━" << endl;
	m_y++; gotoxy(m_x + 7, m_y);
	cout << ">> ";
}

int Menu::Owner_Menu() {
	system("cls");
	gotoxy(x, y);
	cout << "### Owner Mode ###";
	y++; gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; gotoxy(x + 2, y);
	cout << "<1> 객실 가격";
	y += 2; gotoxy(x + 2, y);
	cout << "<2> 객실 현황";
	y += 2; gotoxy(x + 2, y);
	cout << "<3> 회원 목록";
	y += 2; gotoxy(x + 2, y);
	cout << "<4> 메인으로";
	y++; gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
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
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; gotoxy(x + 2, y);
	cout << "<1> 회원 가입";
	y += 2; gotoxy(x + 2, y);
	cout << "<2> 회원 정보 수정";
	y += 2; gotoxy(x + 2, y);
	cout << "<3> 회원 탈퇴";
	y += 2; gotoxy(x + 2, y);
	cout << "<4> 예약";
	y += 2; gotoxy(x + 2, y);
	cout << "<5> 룸서비스";
	y += 2; gotoxy(x + 2, y);
	cout << "<6> 체크아웃";
	y += 2; gotoxy(x + 2, y);
	cout << "<7> 메인으로";
	y++; gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; gotoxy(x + 2, y);
	cout << ">> ";
	x = X; y = 5;
	return KeyPress();
}

void Menu::ownerShow() {
	while ((key = Owner_Menu()) != 4) {
		switch (key) {
			case 1:Room::addroom(); break; //룸 추가하기
			case 2: Room::RoomStatus(); break; //룸 현황 보기    ok
			case 3: Member::ShowMember(); break; //회원 정보 보기 (수정같은건 못함 그냥 확인용) ok
			case 4: break;
		}
	}
}

void Menu::guestShow() {
	while ((key = Guest_Menu()) != 7) {
		switch (key) {  
		case 1:Member::JoinMember(); break; // 회원가입  ok
		case 2: 
			while (Member::ModifyMember() != 1); break; //회원 정보 수정 ok
		case 3:Member::DeleteMember(); break;  //회원 탈퇴  ok
		case 4:Room::Reservation(); break; //예약&체크인 하기
		case 5:Room::roomservice(); break; //룸서비스 신청하기
		case 6:Room::CheckOut(); break; //체크아웃하기
		case 7: break;
		}
	}
}

/*int Menu::Room_Set() {
	system("cls");
	gotoxy(x, y);
	cout << "### 객실 관리 ###";
	y++; gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	y++; gotoxy(x + 2, y);
	cout << "<1> 객실 추가";
	y += 2; gotoxy(x + 2, y);
	cout << "<2> 객실 삭제";
	y += 2; gotoxy(x + 2, y);
	cout << "<3> 이전으로";
	y++; gotoxy(x - 20, y);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	y += 2; gotoxy(x + 2, y);
	cout << ">> ";
	x = X; y = 5;
	return KeyPress();
	}*/