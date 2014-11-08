#include "RBTree.h"
/**
**红黑树实现
*/

RBTree::RBTree()
{

}

Node *
RBTree::_tree_search(Node *node,T data)
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
RBTree::tree_search(T data)
{
	return _tree_search(m_root,data);
}

void
RBTree::_destoryAllNodes(Node *node)
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
RBTree::_transplant(Node *u,Node *v)
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
RBTree::destoryAllNode()
{
	_destoryAllNodes(m_root);
}

Node*
RBTree::_min_Mun(Node *node)
{
	while(node->left)
	{
		node = node->left;
	}
	return node;
}

void
RBTree::insertData(T data)
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
RBTree::middle_order()
{
	_middle_order(m_root);
	printf("\n");
}

void
RBTree::pre_order()
{
	_pre_order(m_root);
	printf("\n");
}

void
RBTree::post_order()
{
	_post_order(m_root);
	printf("\n");
}

void
RBTree::_pre_order(Node *node)
{
	if (node)
	{
		printf("%d  ",node->data);
		_middle_order(node->left);
		_middle_order(node->right);
	}
}

void
RBTree::_post_order(Node *node)
{
if (node)
	{
		_middle_order(node->left);
		_middle_order(node->right);
		printf("%d  ",node->data);
	}	
}

void
RBTree::_middle_order(Node *node)
{
	if (node)
	{
		_middle_order(node->left);
		printf("%d  ",node->data);
		_middle_order(node->right);
	}
}

Node*
RBTree::createNode(T data)
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
RBTree::deleteData(T data)
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
