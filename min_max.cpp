#include <stdio.h>
#define max(x,y) (x)>(y)?(x):(y)

void fintmin_max(int *array,int size)
{
	//最大数，最小数
	int min,max;
	int i = 1;//循环下标
	if (size%2)
		{
			min = max = array[0];
		}
	else
		{
			min = array[0];
			max = array[1];
			i = 2;
		}
	while(i < size)
	{
		int _max = max(array[i],array[i+1]);
		int _min = array[i];
		if (_min == _max)
		{
			_min = array[i+1];
		}
		if (_min < min)
		{
			min = _min;
		}
		if (_max > max)
		{
			max = _max;
		}
		i +=2;
	}
	printf("min == %d max == %d\n",min,max);	
}

int main(int argc, char const *argv[])
{
	int a[10] = {2,7,1,9,4,1,4,78,9,100};
	fintmin_max(a,10);
	return 0;
}