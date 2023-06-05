#pragma once
#include <mysql.h>

#include <string>
using namespace std;
/*
ʵ��MySQL���ݿ����ɾ�Ĳ�
*/
class Connection 
{
public:
	//��ʼ�����ݿ�����
	Connection();
	
	//�ͷ����ݿ�������Դ
	~Connection();
	
	//�������ݿ�
	bool connect(string ip, 
		unsigned short port,
		string user, 
		string password, 
		string dbname);
	
	//���²��� insert��delete��update
	bool update(string sql);
	
	//��ѯ���� select
	MYSQL_RES* query(string sql);
	
private:
	MYSQL *_conn;//��ʾ��MySQL server��һ������
};