#include "XORList.h"

void
XORList::test()
{
	printf("helloworld\n");
}

/*
**两个指针做xor运算
*/
Node*
XORList::_xorPoint(Node *p,Node *q)
{
	 unsigned long x,y,z;
	 x=(unsigned long)p;
	 y=(unsigned long)q;
	 z=x^y;
	 return (Node *)z;
}

/*
**删除 从开头删除
*/
void 
XORList::_freeAllNodes()
{
	while(m_length > 0)
	{
		deleteDataAtIndex(1);
	}
}

/*
**创建一个结点
*/
Node* 
XORList::_createNode(T data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (node)
	{
		node->data = data;
		node->xorP = NULL;	
	}
	else
	{
		node = NULL;
	}
	return node;
}

/*
**插入数据  头插入
*/
bool 
XORList::insert_data(T data)
{
	Node *node = _createNode(data);
	if (!node)
	{
		return false;
	}
	//只有一个元素
	if (m_length == 0)
	{
		if (node)
		{
			m_head = node;
			m_end  = node;	
		}
	}
	else
	{
		/*
		**头插法注释
		*/
		Node *p=m_head,*pre=NULL,*q;
		q=_xorPoint(pre,p->xorP);//找到第一个结点后面的结点
		p->xorP=_xorPoint(node,q);//设置第一个结点的^指针
		node->xorP=_xorPoint(NULL,p);//设置插入结点的^指针
		m_head = node;//设置头部
		//增加长度
	}
	++m_length;//增加长度
	return true;
}

//尾部插入
bool 
XORList::push_back(T data)
{
	//长度为0
	if (m_length == 0)
	{
		return insert_data(data);
	}
	//创建新的节点
	Node *node = _createNode(data);
	if (!node)
	{
		return false;
	}

	// Node *p,*pre=NULL,*q=NULL;
	// p = m_head;
	// while((p!=m_end) && (p != NULL))
	// {
	// 	q=_xorPoint(pre,p->xorP);
	// 	pre=p;
	// 	p=q;
	// }

	Node *p = m_end;
	Node *pre = p->xorP;
	p->xorP = _xorPoint(pre,node);
	node->xorP = _xorPoint(p,NULL);
	m_end = node;
	++m_length;

	return true;
}

/*
**删除第index个节点
**从1开始算起
*/
void 
XORList::deleteDataAtIndex(long index)
{
	if (index < 1 || index > m_length)
	{
		printf("没有对应的节点\n");
		return;
	}

	if (m_length == 1)
	{
		free(m_head);
		m_head = m_end = NULL;

		m_length = 0;
		return;
	}

	int count = 1;

	Node *p,*pre=NULL,*q=NULL;
	p = m_head;
	while(p && (count < index))
	{
		q=_xorPoint(pre,p->xorP);
		pre=p;
		p=q;
		++count;
	}
	//找到当前节点的后一个节点
	Node *next = _xorPoint(pre,p->xorP); 
	//后一个节点的后一个节点
	Node *nnext = NULL;
	if (index != m_length)
	{
		nnext = _xorPoint(p,next->xorP);
	}
	Node *ppre = NULL;
	if (index > 1)
	{
		ppre = _xorPoint(p,pre->xorP);
	}
	//删除第一个节点
	if (index == 1)
	{
		next->xorP = _xorPoint(NULL,nnext);
		m_head = next;
	}
	else if (index == m_length)
	{
		pre->xorP = _xorPoint(NULL,ppre);
		m_end = pre;
	}
	else
	{
		//前一个节点的前一个节点
		pre->xorP = _xorPoint(ppre,next);
		next->xorP = _xorPoint(pre,nnext);
	}
	//长度减小
	--m_length;

	// p->xorP = NULL;
	free(p);
	p = NULL;
}

/*
**打印链表中的值 打印用m_head 和 m_end做标记
**当然也可以用长度做结束标记
*/
void 
XORList::print_datas()
{
	printf("长度为：%ld\n", m_length);
	Node *p,*pre=NULL,*q=NULL;
	p = m_head;

	while(p)
	{
		printf("%d  ",p->data);
		q=_xorPoint(pre,p->xorP);
		pre=p;
		p=q;
	}
	printf("\n");
}



