#include "XORList.h"
/*
**结贴！本可以用模板，由于电脑g++除了点问题，直接用整形代替了
**内存管理还是用new 和delete比较好
*/
int main(int argc, char const *argv[])
{
	XORList *x = (XORList*)malloc(sizeof(XORList));

	for (int i = 0; i < 10; ++i)
	{
		x->insert_data(i);
	}

	for (int i = 10; i < 20; ++i)
	{
		x->push_back(i);
	}

	x->print_datas();

	// x->deleteDataAtIndex(20);

	x->print_datas();

	x->deleteAllNodes();
	free(x);
	x = NULL; 
	return 0;
}