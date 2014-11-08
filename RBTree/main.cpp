 #include "RBTree.h"

 int main(int argc, char const *argv[])
 {
 	RBTree *s = (RBTree*)malloc(sizeof(RBTree));
	
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