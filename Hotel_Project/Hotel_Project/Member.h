#ifndef Member_H
#define Member_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct member {
	string id;	//회원 아이디
	string name;	//회원 이름
	int age;		//회원 나이
	string phone;	//회원 전화번호
	string gender;//회원 성별
	int point;		//회원의 포인트
	bool check;		//true면 회원, false면 탈퇴
	int cnt;		//이용횟수

	friend ostream& operator <<(ostream& os, const member& member);

};


class Member {
private:
	member mthis;
	vector<member> mem;
public:
	int x = 50, y = 18, key;
	void ModifyMember(member pthis); //회원정보수정
	void JoinMember(); //회원가입?
	void DeleteMember(member pthis); //회원탈퇴?
	void ShowMember();//멤버 보여주기
	void SearchMember(); //회원검색
	void SetMember(member member); //벡터에 멤버넣기?
};
#endif // Member_H
