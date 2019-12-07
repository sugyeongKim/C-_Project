#ifndef Member_H
#define Member_H
#include <iostream>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")


using namespace std;


class Member {
private:
	char* mid;	//회원 아이디
	char* mpw; // 회원 비밀번호
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
	Member(char* id, char* password, char* name, int age, char* phone,
		char* gender, int point, int check, int cnt, int total_amount);
	int x = 50, y = 18, key;
	int ModifyMember(); //회원정보수정
	int JoinMember(); //회원가입?
	int DeleteMember(); //회원탈퇴?
	void ShowMember();//멤버 보여주기
	int checkMember(char* id); //회원 체크
	int DBconnecter();
	int SetMember(Member* m); //
	void deleteAllM();


	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 열 정보?
	char Query[256];

};
#endif // Member_H
