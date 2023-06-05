#pragma once
#include <mysql.h>

/*
实现MySQL数据库的增删改查
*/
class Connection 
{
public:
private:
	MYSQL *_conn;//表示和MySQL server的一条链接
};