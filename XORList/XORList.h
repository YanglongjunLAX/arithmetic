#ifndef _XORLIST_H
#define _XORLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int T;

class Node
{
public:
	Node();
	~Node();
	
	T data;
	Node *xorP;//前驱和后继的or结果
};

class XORList
{
private:
	Node *m_head;//开头
	Node *m_end;//结尾
	long m_length;
	Node* _xorPoint(Node *p,Node *q);
	Node* _createNode(T data);
	//删除节点
	void _freeAllNodes();
public:
	XORList(){m_length = 0;}
	~XORList(){_freeAllNodes();}
	void deleteAllNodes(){_freeAllNodes();}
	int getLength(){return m_length;}
	void test();
	//头插法
	bool insert_data(T data);
	//尾部插入
	bool push_back(T data);
	//打印函数 --从头到尾打印
	void print_datas();
	//删除第i个节点
	void deleteDataAtIndex(long index);
};

#endif