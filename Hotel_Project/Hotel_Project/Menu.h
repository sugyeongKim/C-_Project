#pragma once

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Room.h"
#include "Member.h"
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

const int X = 50;
const int Y = 18;


class Menu : public Member, public Room{
public:
	int x = X, y = Y, key;
	void gotoxy(int m_x, int m_y);
	int KeyPress();
	int Start();
	void Hotel_draw(int m_x, int m_y);
	void menu_draw(int m_x, int m_y);
	void ownerShow();
	int Owner_Menu();
	int Guest_Menu();
	int Room_Set();
	void guestShow();

};



#endif