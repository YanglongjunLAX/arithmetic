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
	//替换节点
	void _transplant(Node *u,Node *v);
	//查找数据 == data的节点
	Node *_tree_search(Node *node,T data);
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
	//查找节点
	Node *tree_search(T data);	
};

searchTree::searchTree()
{

}

Node *
searchTree::_tree_search(Node *node,T data)
{
	if (!node || node->data == data)
	{
		return node;
	}
	if (data < node->data)
	{
		return _tree_search(node->left,data);
	}
	else
	{
		return _tree_search(node->right,data);
	}
}

Node *
searchTree::tree_search(T data)
{
	return _tree_search(m_root,data);
}

void
searchTree::_destoryAllNodes(Node *node)
{
	if (node)
	{
		_destoryAllNodes(node->left);
		_destoryAllNodes(node->right);
		printf("freeNode %d\n",node->data);
		free(node);
		node = NULL;
	}
}

void
searchTree::_transplant(Node *u,Node *v)
{
	//如果u是根节点
	if (!u->parent)
	{
		m_root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if (v)
	{
		v->parent = u->parent;
	}

	//删除节点==
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
	printf("\n");
}

void
searchTree::pre_order()
{
	_pre_order(m_root);
	printf("\n");
}

void
searchTree::post_order()
{
	_post_order(m_root);
	printf("\n");
}

void
searchTree::_pre_order(Node *node)
{
	if (node)
	{
		printf("%d  ",node->data);
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
		printf("%d  ",node->data);
	}	
}

void
searchTree::_middle_order(Node *node)
{
	if (node)
	{
		_middle_order(node->left);
		printf("%d  ",node->data);
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
	//查找节点
	Node *node = tree_search(data);
	
	if (!node)
	{
		printf("没有找到数据为%d的节点\n",data);
		return;
	}

	if (!node->left)
	{
		_transplant(node,node->right);
	}
	else if (!node->right)
	{
		_transplant(node,node->left);
	}
	else
	{
		Node *y = _min_Mun(node->right);
		if (y->parent != node)
		{
			_transplant(y,y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		_transplant(node,y);
		y->left = node->left;
		y->left->parent = y;
	}

	free(node);
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node = NULL;
}

///
int main(int argc, char const *argv[])
{
	searchTree *s = (searchTree*)malloc(sizeof(searchTree));
	
	int a[10] = {2,8,1,4,0,3,7,10,9,12};
	for (int i = 0; i < 10; ++i)
	{
		s->insertData(a[i]);
	}

	int x = 3;

	s->deleteData(x);

	s->insertData(-1);

	s->pre_order();
	s->middle_order();
	s->post_order();

	s->destoryAllNode();
	free(s);

	return 0;
}