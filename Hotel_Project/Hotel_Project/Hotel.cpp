#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

//���߿� ȭ�� ������Ű��
//ī�信�� ����. �Խ�Ʈ��� �� �����.
using namespace std;

#define X 50
#define Y 18

struct Member {
	string m_id;		//ȸ�� ���̵�
	string m_name;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	string m_phone;	//ȸ�� ��ȭ��ȣ
	string m_gender;	//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	int cnt;		//�̿�Ƚ��
};

struct Room {
	int room_num; //ȣ��
	int room_use; //���������� �ƴ���
	char* user; //����� �̸�
	char* date_in; //üũ�� ��¥
	char* date_out; //üũ�ƿ� ��¥
	Member** base; //ȸ���� ����? ��...?
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

	int Owner_Menu() {
		system("cls");
		gotoxy(x, y);
		cout << "### Owner Mode ###";
		y++; gotoxy(x-20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x+2, y);
		cout << "<1> ���� ����";
		y+=2; gotoxy(x+2, y);
		cout << "<2> ���� ��Ȳ";
		y+=2; gotoxy(x+2, y);
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

	int Guest_Menu() {
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

	int Room_Set() {
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
	void Room_Status() {
		system("cls");
		gotoxy(x, y);
		cout << "### ���� ��Ȳ ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; 
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");

	}
	void Member_Set() {
		system("cls");
		gotoxy(x, y);
		cout << "### ȸ�� ���� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void joinMember() {
		system("cls");
		gotoxy(x, y);
		cout << "### ȸ�� ���� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x - 20, y);
		cout << "�̸��� �Է����ּ���: "; cin >> m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "���̸� �Է����ּ���: "; cin >> m.age;
		y++; gotoxy(x - 20, y);
		cout << "������ �Է����ּ���: "; cin >> m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "ȸ������ �Ϸ� �Ǽ̽��ϴ�";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
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
		cout << "### ȸ�� ���� ���� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x - 20, y);
		cout << "<1> �̸�: " << m.m_name;
		y++; gotoxy(x - 20, y);
		cout << "<2> ����: " << m.age;
		y++; gotoxy(x - 20, y);
		cout << "<3> ����: " << m.m_gender;
		y++; gotoxy(x - 20, y);
		cout << "<4> ��ȭ��ȣ: " << m.m_phone;
		y++; gotoxy(x - 20, y);
		cout << "<5> �ڷΰ��� ";
		y++; y++; gotoxy(x - 20, y);
		cout << "������ �׸��� ����ּ���: ";
		cin >> choice;
		y++; y++; gotoxy(x - 20, y);
		switch (choice)	{
			case 1: 
				cout << "������ �̸��� �Է��ϼ���: ";
				cin >> m.m_name; break;
			case 2:
				cout << "������ ���̸� �Է��ϼ���: ";
				cin >> m.age; break;
			case 3:
				cout << "������ ������ �Է��ϼ���: ";
				cin >> m.m_gender; break;
			case 4:
				cout << "������ ��ȭ��ȣ�� �Է��ϼ���: ";
				cin >> m.m_phone; break;
			case 5:
				cout << "�ڷΰ���";
				x = X; y = 5;
				return 1;
		}
		y++; y++; gotoxy(x - 20, y);
		cout << "���� �Ϸ�^^";
		y++; y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
		return 0;
	}

	void deleteMember() {
		string name, tel;
		system("cls");
		gotoxy(x, y);
		cout << "### ȸ�� Ż�� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x - 20, y);
		cout << "Ż�� ���Ͻø� �̸��� ��ȭ��ȣ�� �Է����ּ���";
		y++; gotoxy(x - 20, y);
		cout << "�̸�: ";
		cin >> name;
		y++; gotoxy(x - 20, y);
		cout << "��ȭ��ȣ: ";
		cin >> tel;

		if (m.m_name == name && m.m_phone == tel){
			y++; gotoxy(x - 20, y);
			cout << "Ż��ó���Ǿ����ϴ�~~^^";
		}
		else {
			y++; gotoxy(x - 20, y);
			cout << "������ ������ ȸ���� �������� �ʽ��ϴ�~~^^";
		}

		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void ReserveRoom() {
		system("cls");
		gotoxy(x, y);
		cout << "### �����ϱ� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y += 2; gotoxy(x + 2, y);
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_add() {
		system("cls");
		gotoxy(x, y);
		cout << "### ���� �߰� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void Room_delete() {
		system("cls");
		gotoxy(x, y);
		cout << "### ���� ���� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckIn() {
		system("cls");
		gotoxy(x, y);
		cout << "### üũ �� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}

	void CheckOut() {
		system("cls");
		gotoxy(x, y);
		cout << "### üũ�ƿ� ###";
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������";
		y++;
		y++;
		y++;
		y++; gotoxy(x - 20, y);
		cout << "������������������������������������������������������������������������������������������������������������������" << endl;
		y += 2; gotoxy(x + 2, y);
		x = X; y = 5;
		system("PAUSE");
	}
};
