#include<iostream>

using namespace std;
#include"Connection.h"
#include"CommonConnectionPool.h"

int main()
{
	/*
	Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values('%s','%d','%s')",
		"zhang san", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);
	*/

	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	

	return 0;
}