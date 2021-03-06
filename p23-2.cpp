//written by zhaoshaojing-EE-51
//用了连续的node节点数组，这个怎么说呢...
//还有命名了一个next的node*真是魔性啊
//time:292 ms 	memory:7940 KiB
#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct node
{
public:
	int num;
	node *next;
}node;
int main()
{
	int N, M, k, i, j;
	node *cur, *last, *next, *p, *head;
	scanf("%d%d%d", &N, &M, &k);
	head = p = new node[N];
	last = cur = next = p;
	cur->next = cur;
	cur->num = 1;
	if (M > 1)
	{
		for (i = 2;i <= M;++i)
		{
			p->next = p + 1;//因为是连续数组所以说可以这样
			p = p->next;
			p->next = cur;
			p->num = i;
		}
		last = p;
		next = cur->next;
	}
	for (i = M + 1;i <= N;++i)
	{
		for (j = k;j > 1;--j)
		{
			last = cur;
			cur = next;
			next = next->next;
		}
		if (cur->num & 1)//位运算
		{
			last->next = ++p;
			last->next->next = cur;
			last->next->num = i;
			last = cur;
			cur = next;
			next = next->next;
		}
		else
		{
			last = cur;
			cur->next = ++p;
			cur->next->next = next;
			cur = cur->next;
			cur->num = i;
		}
	}
	for (i = N - M;i > 0;--i)
	{
		for (j = k;j > 1;--j)
		{
			last = cur;
			cur = next;
			next = next->next;
		}
		last->next = next;
		cur = next;
		next = next->next;
	}
	for (i = M, j = 0;i > 0;--i)
	{
		if (cur->num <= M)++j;
		cur = next;
		next = next->next;
	}
	printf("%d", j);
	delete[]head;
}