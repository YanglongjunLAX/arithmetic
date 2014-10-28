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
public:
	XORList(){m_length = 0;}
	~XORList();
	int getLength(){return m_length;}
	void test();
	bool insert_data(T data);
	void print_datas();
};

#endif