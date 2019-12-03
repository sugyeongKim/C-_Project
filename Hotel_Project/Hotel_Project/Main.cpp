#include "Member.h"
#include "Menu.h"
#include "Room.h"

int main() {
	Menu h;
	Member m;
	m.setting();
	int key;
	while ((key = h.Start()) != 3) {
		//h.Start();
		switch (key) {
		case 1:
			h.ownerShow(); break;
		case 2:
			h.guestShow(); break;
		case 3: return 0;
		}
	}
}