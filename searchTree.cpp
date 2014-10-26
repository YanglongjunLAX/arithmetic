#include <stdio.h>
#include <iostream>
using namespace std;

typedef int T;

class Node
{
public:
	Node(){}
	~Node(){}
	T data;
	Node *left;
	Node *right;
};

class searchTree
{
private:
	Node *m_root;

	Node* createNode(T data);
	void _middle_order(Node *node);
	void _pre_order(Node *node);
	void _post_order(Node *node);
public:
	searchTree();
	~searchTree()
	{
		//销毁
	}
	//插入
	void insertData(T data);
	//中序遍历
	void middle_order();
	//先序遍历
	void pre_order();
	//后序遍历
	void post_order();	
};

searchTree::searchTree()
{

}

void
searchTree::insertData(T data)
{
	//根节点为空
	if (!m_root)
	{
		m_root = createNode(data);
	}
	else
	{
		//查找应该插入的位置
		Node *r = m_root;
		Node *p = r;
		Node *q = p;
		while(p)
		{
			q = p;
			if (data <= p->data)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		p = createNode(data);
		if (p)
		{
			if (q->data < data)
			{
				q->right = p;
			}
			else
			{
				q->left = p;
			}
		}
	}
}

void
searchTree::middle_order()
{
	_middle_order(m_root);
}

void
searchTree::pre_order()
{
	_pre_order(m_root);
}

void
searchTree::post_order()
{
	_post_order(m_root);
}

void
searchTree::_pre_order(Node *node)
{
	if (node)
	{
		printf("%d\n",node->data);
		_middle_order(node->left);
		_middle_order(node->right);
	}
}

void
searchTree::_post_order(Node *node)
{
if (node)
	{
		_middle_order(node->left);
		_middle_order(node->right);
		printf("%d\n",node->data);
	}	
}

void
searchTree::_middle_order(Node *node)
{
	if (node)
	{
		_middle_order(node->left);
		printf("%d\n",node->data);
		_middle_order(node->right);
	}
}

Node*
searchTree::createNode(T data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if (node)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = data;
	} 
	else
	{
		printf("节点申请失败\n");
		node = NULL;
	}
	return node;
}

///
int main(int argc, char const *argv[])
{
	searchTree *s = (searchTree*)malloc(sizeof(searchTree));
	
	int a[10] = {2,8,1,4,0,4,7,8,9,12};
	for (int i = 0; i < 10; ++i)
	{
		s->insertData(a[i]);
	}
	
	return 0;
}