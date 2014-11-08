#ifndef _RBTREE_H
#define _RBTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int T;

class Node
{
public:
	Node(){}
	~Node(){}
	T data;

	Node *parent;
	Node *left;
	Node *right;
};

class RBTree
{
private:
	Node *m_root;

	Node* createNode(T data);
	void _middle_order(Node *node);
	void _pre_order(Node *node);
	void _post_order(Node *node);
	//最小的节点
	Node* _min_Mun(Node *node);
	//查找节点
	// Node* _find_node(T t);
	void _destoryAllNodes(Node *node);
	//替换节点
	void _transplant(Node *u,Node *v);
	//查找数据 == data的节点
	Node *_tree_search(Node *node,T data);
public:
	RBTree();
	~RBTree()
	{
		printf("析构函数调用\n");
		_destoryAllNodes(m_root);
	}
	//插入
	void insertData(T data);
	//中序遍历
	void middle_order();
	//先序遍历
	void pre_order();
	//后序遍历
	void post_order();
	//删除节点 数据为data的节点
	void deleteData(T data);
	void destoryAllNode();
	//查找节点
	Node *tree_search(T data);	
};
#endif