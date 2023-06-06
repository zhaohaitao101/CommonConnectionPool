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
实现链接池模块功能
*/
class ConnectionPool
{
public:
	//获取连接池对象实例
	static ConnectionPool* getConnectionPool();
	//给外部提供结构,从连接池中获取一个可用的空闲连接    
	shared_ptr<Connection> getConnection();
private:
	ConnectionPool();//单例#1构造函数私有化

	//从配置文件中加载配置项
	bool loadConfigFile();

	//运行在独立的线程中，专门负责生产新连接
	void produceConnectionTask();

	//扫描超过maxIdleTime时间的空闲连接，进行对于的连接回收
	void scannerConnectionTask();

	string _ip;//MySQL的IP地址
	unsigned short _port;//MySQL的端口号 3306
	string _username;//MySQL的登录用户名
	string _password;//MySQL的登录密码
	string _dbname;//链接数据库名称
	int _initSize;//连接池的初始链接量
	int _maxSize;//连接池的最大连接量
	int _maxIdleTime;//连接池的最大空闲时间
	int _connectionTimeout;//连接池获取链接的超过时间

	queue<Connection*> _connectionQue;//存储MySQL的连接队列
	mutex _queueMutex;//维护连接队列的线程安全互斥锁
	atomic_int _connectionCnt;//记录连接所创建队列的数量
	condition_variable cv;//设置条件变量，用于连接生产线程和消费线程的通信


};