#include "Menu.h"

int main() {
	Menu* h = new Menu();
	Member* m = new Member();
	Room* r = new Room();
	r->DBconnecter();
	int key;
	r->SetRoom(); 
	while ((key = h->Start()) != 3) {
		//h.Start();
		switch (key) {
		case 1:
			h->ownerShow(); break;
		case 2:
			h->guestShow(); break;
		case 3: break;
		}
	}
	r->deleteAllR(); // 만들어놓은 방 삭제
	return 0;
}