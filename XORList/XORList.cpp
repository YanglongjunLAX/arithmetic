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
	/*
	**头插法注释
	*/
	Node *p=m_head,*pre=NULL,*q;
	q=_xorPoint(pre,p->xorP);//找到第一个结点后面的结点
	p->xorP=_xorPoint(node,q);//设置第一个结点的^指针
	node->xorP=_xorPoint(NULL,p);//设置插入结点的^指针
	m_head = node;//设置头部
	//增加长度
	++m_length;//增加长度
	return true;
}

/*
**打印链表中的值 打印用m_head 和 m_end做标记
**当然也可以用长度做结束标记
*/
void 
XORList::print_datas()
{
	Node *p,*pre=NULL,*q=NULL;
	p = m_head;
	while(p!=m_end)
	{
		printf("  %d",p->data);
		q=_xorPoint(pre,p->xorP);
		pre=p;
		p=q;
	}
	printf("  %d",p->data);
	printf("\n");
}



