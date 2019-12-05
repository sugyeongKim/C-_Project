#include <WinSock2.h>
#include <iostream>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

using namespace std;

int main() {
	cout << "MySQL client Version: " << mysql_get_client_info() << endl;
	MYSQL mysql; //mysql 정보를 담는 구조체
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // 쿼리 결과 담는 구조체 포인터
	MYSQL_ROW Row; //쿼리 성공시 결과의 행 정보 담는 구조체
	int stat; // 쿼리 요청 후 결과
	int fields; // 

	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, "localhost", "root", "mirim2", "chotel", 3306, NULL, 0);
	if (connection == NULL){
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}
	cout << "success" << endl;

	mysql_query(connection, "set session character_set_connection=euckr");
	mysql_query(connection, "set session character_set_results=euckr");
	mysql_query(connection, "set session character_set_client=euckr");

	const char* Query = "SELECT * FROM STAFF";
	stat = mysql_query(connection, Query);

	if (stat != 0) {
		cout << "error: " << mysql_error(&mysql);
		return 1;
	}

	Result = mysql_store_result(connection);
	fields = mysql_num_fields(Result);
	while ((Row = mysql_fetch_row(Result)) != NULL) {
		for (int i = 0; i < fields; i++)
			cout << Row[i]<< ",";
		cout << endl;
	}

	mysql_free_result(Result);
	mysql_close(connection);
	return 0;
}