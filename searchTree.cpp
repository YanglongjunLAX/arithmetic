#include <stdio.h>
#include <iostream>
using namespace std;

//v2，增加父节点

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

class searchTree
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
public:
	searchTree();
	~searchTree()
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
};

searchTree::searchTree()
{

}

void
searchTree::_destoryAllNodes(Node *node)
{
	if (node)
	{
		_destoryAllNodes(node->left);
		_destoryAllNodes(node->right);
		free(node);
		node = NULL;
		printf("freeNode\n");
	}
}

void
searchTree::destoryAllNode()
{
	_destoryAllNodes(m_root);
}

Node*
searchTree::_min_Mun(Node *node)
{
	while(node->left)
	{
		node = node->left;
	}
	return node;
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
			p->parent = q;
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
		node->parent = NULL;
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

//删除，有待完成
void
searchTree::deleteData(T data)
{
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
	
	s->destoryAllNode();
	free(s);

	return 0;
}