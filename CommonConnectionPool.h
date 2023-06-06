#pragma once
#include <string>
#include <queue>
#include<mutex>
#include<atomic>
#include<thread>
#include<memory>
#include<condition_variable>
#include<functional>
#include<iostream>
using namespace std;
#include "Connection.h"

/*
ʵ�����ӳ�ģ�鹦��
*/
class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	//���ⲿ�ṩ�ṹ,�����ӳ��л�ȡһ�����õĿ�������    
	shared_ptr<Connection> getConnection();
private:
	ConnectionPool();//����#1���캯��˽�л�

	//�������ļ��м���������
	bool loadConfigFile();

	//�����ڶ������߳��У�ר�Ÿ�������������
	void produceConnectionTask();

	//ɨ�賬��maxIdleTimeʱ��Ŀ������ӣ����ж��ڵ����ӻ���
	void scannerConnectionTask();

	string _ip;//MySQL��IP��ַ
	unsigned short _port;//MySQL�Ķ˿ں� 3306
	string _username;//MySQL�ĵ�¼�û���
	string _password;//MySQL�ĵ�¼����
	string _dbname;//�������ݿ�����
	int _initSize;//���ӳصĳ�ʼ������
	int _maxSize;//���ӳص����������
	int _maxIdleTime;//���ӳص�������ʱ��
	int _connectionTimeout;//���ӳػ�ȡ���ӵĳ���ʱ��

	queue<Connection*> _connectionQue;//�洢MySQL�����Ӷ���
	mutex _queueMutex;//ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt;//��¼�������������е�����
	condition_variable cv;//���������������������������̺߳������̵߳�ͨ��


};