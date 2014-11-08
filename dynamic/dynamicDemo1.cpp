#include <stdio.h>
/*
*钢条切割问题：
*问题描述
假设公司出售一段长度为i英寸的钢条的价格为Pi（i = 1, 2, ...单位：美元），下面给出了价格表样例：
长度i     1     2     3     4     5      6     7     8     9     10
价格Pi    1     5     8     9     10     17    17    20    24    30
切割钢条的问题是这样的：给定一段长度为n英寸的钢条和一个价格表Pi，求切割方案，使得销售收益Rn最大。
*/
//假定价格一开始已经给出了，用全局的写死

#define max(x,y) (x)>(y)?(x):(y)

int price[10] = {1,5,8,9,10,17,17,20,24,30};

//参数n为长度
/*
**一般的递归问题
*/
int
getMaxGain(int n)//自顶向下
{
	if (0 == n)
	{
		return 0;
	}
	//最小的标量
	int _max = 0;
	for (int i = 1; i <= n; ++i)
	{
		// printf("i ==== %d\n", price[i-1]);
		_max = max(_max,price[i-1] + getMaxGain(n-i));
	}
	return _max;
}

//动态规划版本
/*
**保留每一次计算出来的结果，需要的时候从保留的结果里面查
*/
int
dy_getMaxGain(int n)//自顶向下求解
{
	//假设我们求的长度总是小于10，方便用数组，否则动态开辟数组
	static int cache[10] = {0};
	if (cache[n] > 0)
	{
		return cache[n];
	}
	if (0 == n)
	{
		return 0;
	}
	printf("%d\n", n);
	//最小的标量
	int _max = 0;
	for (int i = 1; i <= n; ++i)
	{
		_max = max(_max,price[i-1] + getMaxGain(n-i));
		cache[i] = _max;
	}
	return _max;
}

int
dy_buttomToUp(int n)
{
	static int cc[11] = {0};
	if (n == 0)
	{
		return 0;
	}
	int _max = 0;
	for (int i = 1; i <= n; ++i)
	{
		_max = 0;
		for (int j = 1; j <= i; ++j)
		{
			_max = max(_max,price[j-1]+cc[i-j]);
		}
		cc[i] = _max;
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ",cc[i]);
	}
	printf("\n");
	return cc[n];
}

int main(int argc, char const *argv[])
{
	//test
	printf("noDY=%d\n",getMaxGain(7));
	printf("_dy=%d\n", dy_getMaxGain(6));
	printf("^^^^^^^^%d\n",dy_buttomToUp(7));
	return 0;
}