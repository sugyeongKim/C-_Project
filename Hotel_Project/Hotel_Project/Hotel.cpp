#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

//³ªÁß¿¡ È­¸é °íÁ¤½ÃÅ°±â
//Ä«Æä¿¡¼­ ÇÒÀÏ. °Ô½ºÆ®¸ðµå ´Ù ¸¸µé±â.
using namespace std;

#define X 50
#define Y 18

struct Member {
	string m_id;		//È¸¿ø ¾ÆÀÌµð
	string m_name;	//È¸¿ø ÀÌ¸§
	int age;		//È¸¿ø ³ªÀÌ
	string m_phone;	//È¸¿ø ÀüÈ­¹øÈ£
	string m_gender;	//È¸¿ø ¼ºº°
	int point;		//È¸¿øÀÇ Æ÷ÀÎÆ®
	int cnt;		//ÀÌ¿ëÈ½¼ö
};

struct Room {
	int room_num; //È£½Ç
	int room_use; //¿¹¾àÁßÀÎÁö ¾Æ´ÑÁö
	char* user; //»ç¿ëÀÚ ÀÌ¸§
	char* date_in; //Ã¼Å©ÀÎ ³¯Â¥
	char* date_out; //Ã¼Å©¾Æ¿ô ³¯Â¥
	Member** base; //È¸¿ø°ú ¿¬°á? ¿Ö...?
};

struct base {
	int max_member; //

};

class Hotel_Menu {
	int x, y, m_key;
	Member m;
public:
	void gotoxy(int m_x, int m_y) {
		COORD Pos = { m_x - 1, m_y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	int KeyPress() {
		int key;
		cin >> key;
		return key;
	}

	int Start() {
		system("cls");
		x = X - 10; y = 5;
		Hotel_draw(x, y);
		x = X; y = Y;
		menu_draw(x, y);
		x = X; y = 5;
		return KeyPress();
	}

	void ownerShow() {
		while ((m_key = Owner_Menu()) != 4) {
			switch (m_key) {
			case 1: 
				while((m_key = Room_Set())!=3){
					switch (m_key) {
					case 1:Room_add(); break;
					case 2:Room_delete(); break;
					case 3:break;
					}
				}
					break;
			case 2: Room_Status(); break;
			case 3: Member_Set(); break;
			case 4: break;
			}
		}
	}

	void guestShow() {
		while ((m_key = Guest_Menu()) != 7) {
			switch (m_key) {
			case 1:joinMember(); break;
			case 2:
				while (modifyMember()!=1); break;
			case 3:deleteMember(); break;
			case 4:ReserveRoom(); break;
			case 5: CheckIn(); break;
			case 6: CheckOut(); break;
			case 7: break;
			}
		}
	}

	void Hotel_draw(int m_x, int m_y) {
		gotoxy(m_x, m_y);
		printf("*     *   *******  *******  ********  *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *  *       *    *     *         *");
		m_y++; gotoxy(m_x, m_y);
		printf("*******  *       *    *     ********  *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *  *       *    *     *         *");
		m_y++; gotoxy(m_x, m_y);
		printf("*     *   *******     *     ********  ******");
		m_y++; gotoxy(m_x, m_y);
	}

	void menu_draw(int m_x, int m_y) {
		gotoxy(m_x, m_y - 1);//x=50, y=17
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		gotoxy(m_x, m_y); //x=50,y=18
		cout << "| <1> Owner mode |";
		m_y++; gotoxy(m_x, m_y); //y=19
		cout << "| <2> Guest mode |";
		m_y++; gotoxy(m_x, m_y);
		cout << "| <3> Exit       |";
		m_y++; gotoxy(m_x, m_y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		m_y++; gotoxy(m_x + 7, m_y);
		cout << ">> ";
	}

	int Owner_Menu() {
		system("cls");
		gotoxy(x, y);
		cout << "### Owner Mode ###";
		y++; gotoxy(x-20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x+2, y);
		cout << "<1> °´½Ç °ü¸®";
		y+=2; gotoxy(x+2, y);
		cout << "<2> °´½Ç ÇöÈ²";
		y+=2; gotoxy(x+2, y);
		cout << "<3> È¸¿ø °ü¸®";
		y += 2; gotoxy(x + 2, y);
		cout << "<4> ¸ÞÀÎÀ¸·Î";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}

	int Guest_Menu() {
		system("cls");
		gotoxy(x, y);
		cout << "### Guest Mode ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x + 2, y);
		cout << "<1> È¸¿ø °¡ÀÔ";
		y += 2; gotoxy(x + 2, y);
		cout << "<2> È¸¿ø Á¤º¸ ¼öÁ¤";
		y += 2; gotoxy(x + 2, y);
		cout << "<3> È¸¿ø Å»Åð";
		y += 2; gotoxy(x + 2, y);
		cout << "<4> ¿¹¾à";
		y += 2; gotoxy(x + 2, y);
		cout << "<5> Ã¼Å©ÀÎ";
		y += 2; gotoxy(x + 2, y);
		cout << "<6> Ã¼Å©¾Æ¿ô";
		y += 2; gotoxy(x + 2, y);
		cout << "<7> ¸ÞÀÎÀ¸·Î";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}

	int Room_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### °´½Ç °ü¸® ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x + 2, y);
		cout << "<1> °´½Ç Ãß°¡";
		y += 2; gotoxy(x + 2, y);
		cout << "<2> °´½Ç »èÁ¦";
		y += 2; gotoxy(x + 2, y);
		cout << "<3> ÀÌÀüÀ¸·Î";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		cout << ">> ";
		x = X; y = 5;
		return KeyPress();
	}
	void Room_Status() {
		system("cls");
		gotoxy(x, y);
		cout << "### °´½Ç ÇöÈ² ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; 
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");

	}
	void Member_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### È¸¿ø °ü¸® ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void joinMember() {
		system("cls");
		gotoxy(x, y);
		cout << "### È¸¿ø °¡ÀÔ ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x - 20, y);
		cout << "ÀÌ¸§À» ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "³ªÀÌ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> m.age;
		y++; gotoxy(x - 20, y);
		cout << "¼ºº°À» ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä: "; cin >> m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "È¸¿ø°¡ÀÔ ¿Ï·á µÇ¼Ì½À´Ï´Ù";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5; 
		system("PAUSE");
	}

	void Insert(string name, int age, string gender, string phone) {

	}

	int modifyMember() {
		int choice;
		system("cls");
		gotoxy(x, y);
		cout << "### È¸¿ø Á¤º¸ ¼öÁ¤ ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x - 20, y);
		cout << "<1> ÀÌ¸§: " << m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "<2> ³ªÀÌ: " << m.age;
		y++; gotoxy(x - 20, y);
		cout << "<3> ¼ºº°: " << m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "<4> ÀüÈ­¹øÈ£: " << m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "<5> µÚ·Î°¡±â ";
		y++; y++; gotoxy(x - 20, y);
		cout << "¼öÁ¤ÇÒ Ç×¸ñÀ» °ñ¶óÁÖ¼¼¿ä: ";
		cin >> choice;
		y++; y++; gotoxy(x - 20, y);
		switch (choice)	{
			case 1: 
				cout << "º¯°æÇÒ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ";
				cin >> m.m_name; break;
			case 2:
				cout << "º¯°æÇÒ ³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ";
				cin >> m.age; break;
			case 3:
				cout << "º¯°æÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ";
				cin >> m.m_gender; break;
			case 4:
				cout << "º¯°æÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ";
				cin >> m.m_phone; break;
			case 5:
				cout << "µÚ·Î°¡±â";
				x = X; y = 5;
				return 1;
		}
		y++; y++; gotoxy(x - 20, y);
		cout << "º¯°æ ¿Ï·á^^";
		y++; y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
		return 0;
	}

	void deleteMember() {
		string name, tel;
		system("cls");
		gotoxy(x, y);
		cout << "### È¸¿ø Å»Åð ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x - 20, y);
		cout << "Å»Åð¸¦ ¿øÇÏ½Ã¸é ÀÌ¸§°ú ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä";
		y++; gotoxy(x - 20, y);
		cout << "ÀÌ¸§: ";
		cin >> name;
		y++; gotoxy(x - 20, y);
		cout << "ÀüÈ­¹øÈ£: ";
		cin >> tel;

		if (m.m_name == name && m.m_phone == tel){
			y++; gotoxy(x - 20, y);
			cout << "Å»ÅðÃ³¸®µÇ¾ú½À´Ï´Ù~~^^";
		}
		else {
			y++; gotoxy(x - 20, y);
			cout << "µ¿ÀÏÇÑ Á¤º¸ÀÇ È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù~~^^";
		}

		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void ReserveRoom() {
		system("cls");
		gotoxy(x, y);
		cout << "### ¿¹¾àÇÏ±â ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_add() {
		system("cls");
		gotoxy(x, y);
		cout << "### °´½Ç Ãß°¡ ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_delete() {
		system("cls");
		gotoxy(x, y);
		cout << "### °´½Ç »èÁ¦ ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckIn() {
		system("cls");
		gotoxy(x, y);
		cout << "### Ã¼Å© ÀÎ ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckOut() {
		system("cls");
		gotoxy(x, y);
		cout << "### Ã¼Å©¾Æ¿ô ###";
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}
};
