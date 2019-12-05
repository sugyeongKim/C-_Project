#include <WinSock2.h>
#include <iostream>
#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

using namespace std;

int main() {
	cout << "MySQL client Version: " << mysql_get_client_info() << endl;
	MYSQL mysql; //mysql ������ ��� ����ü
	MYSQL *connection = NULL;
	MYSQL_RES *Result = NULL; // ���� ��� ��� ����ü ������
	MYSQL_ROW Row; //���� ������ ����� �� ���� ��� ����ü
	int stat; // ���� ��û �� ���
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