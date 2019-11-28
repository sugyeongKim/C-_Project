#ifndef Member_H
#define Member_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct member {
	string id;	//ȸ�� ���̵�
	string name;	//ȸ�� �̸�
	int age;		//ȸ�� ����
	string phone;	//ȸ�� ��ȭ��ȣ
	string gender;//ȸ�� ����
	int point;		//ȸ���� ����Ʈ
	bool check;		//true�� ȸ��, false�� Ż��
	int cnt;		//�̿�Ƚ��

	friend ostream& operator <<(ostream& os, const member& member);

};


class Member {
private:
	member mthis;
	vector<member> mem;
public:
	int x = 50, y = 18, key;
	void ModifyMember(member pthis); //ȸ����������
	void JoinMember(); //ȸ������?
	void DeleteMember(member pthis); //ȸ��Ż��?
	void ShowMember();//��� �����ֱ�
	void SearchMember(); //ȸ���˻�
	void SetMember(member member); //���Ϳ� ����ֱ�?
};
#endif // Member_H
