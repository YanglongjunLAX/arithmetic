#include "XORList.h"

int main(int argc, char const *argv[])
{
	XORList *x = (XORList*)malloc(sizeof(XORList));

	x->test();

	for (int i = 0; i < 10; ++i)
	{
		x->insert_data(i);
	}

	x->print_datas();

	free(x);
	x = NULL; 
	return 0;
}