#include "XORList.h"

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

	x->deleteDataAtIndex(20);

	x->print_datas();

	free(x);
	x = NULL; 
	return 0;
}