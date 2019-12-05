#ifndef Member_H
#define Member_H
#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;

struct member {
	char* id;	//회원 아이디
	char* name;	//회원 이름
	int age;		//회원 나이
	char* phone;	//회원 전화번호
	char* gender;//회원 성별
	int point;		//회원의 포인트
	bool check;		//true면 회원, false면 탈퇴
	int cnt;		//이용횟수
	int total_amount; //총 금액
	
	//friend ostream& operator <<(ostream& os, const member& member);
};


class Member {
private:
	member mthis;
	//vector<member> mem;
	char* mid;	//회원 아이디
	char* mname;	//회원 이름
	int age;		//회원 나이
	char* mphone;	//회원 전화번호
	char* mgender;//회원 성별
	int point;		//회원의 포인트
	int check;		//true면 회원, false면 탈퇴
	int cnt;		//이용횟수
	int total_amount; //총 금액

public:
	Member *m;
	Member();
	~Member();
	Member(char* id, char* name, int age, char* phone,
		char* gender, int point, int check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //회원정보수정
	void JoinMember(); //회원가입?
	int DeleteMember(); //회원탈퇴?
	void ShowMember();//멤버 보여주기
	void SearchMember(); //회원검색
	void PrintMember(); //회원 출력
	int DBconnecter();
	int SetMember(Member* m); //벡터에 멤버넣기?
	void deleteAllM();
	//void ModifyDB(char* component);


	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 열 정보?
	char Query[256];

};
#endif // Member_H
