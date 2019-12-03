#ifndef Member_H
#define Member_H

#include <iostream>
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>
#pragma comment(lib, "libmysql.lib")

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
	int total_amount; //총 금액
	friend ostream& operator <<(ostream& os, const member& member);

};


class Member {
private:
	member mthis;
	vector<member> mem;
	string id;	//회원 아이디
	string name;	//회원 이름
	int age;		//회원 나이
	string phone;	//회원 전화번호
	string gender;//회원 성별
	int point;		//회원의 포인트
	bool check;		//true면 회원, false면 탈퇴
	int cnt;		//이용횟수
	int total_amount; //총 금액
public:
	Member(string id, string name, int age, string phone, string gender, int point, bool check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //회원정보수정
	void JoinMember(); //회원가입?
	void DeleteMember(member pthis); //회원탈퇴?
	void ShowMember();//멤버 보여주기
	void SearchMember(); //회원검색
	int SetMember(member member); //벡터에 멤버넣기?
	void PrintMember(); //회원 출력
	int DBconnecter();

	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 열 정보?

};
#endif // Member_H
