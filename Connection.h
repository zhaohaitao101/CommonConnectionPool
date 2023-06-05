#pragma once
#include <mysql.h>

#include <string>
using namespace std;
/*
实现MySQL数据库的增删改查
*/
class Connection 
{
public:
	//初始化数据库链接
	Connection();
	
	//释放数据库链接资源
	~Connection();
	
	//链接数据库
	bool connect(string ip, 
		unsigned short port,
		string user, 
		string password, 
		string dbname);
	
	//更新操作 insert，delete，update
	bool update(string sql);
	
	//查询操作 select
	MYSQL_RES* query(string sql);
	
private:
	MYSQL *_conn;//表示和MySQL server的一条链接
};