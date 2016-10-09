//written by 张洪源-EE-51
//time:628 ms 	memory:4128 KiB
#include<iostream>
#pragma warning(disable:4996)
#include<cstdio>
using namespace std;
bool h(int n,bool* q)    // 判断是不是卡迈克尔数
{
	
	int i,m,a,b,j=0;
	bool k=0;
	a=m=n;
	if (n%2==0) return 0;
	if (!q[n]) return 0;
	else{
	for(i=3;i<=m;i+=2)
	{if(a%i==0&&a!=1&&q[n])
	{b=a/i;
	j++;
	if(b%i==0||(n-1)%(i-1)!=0)
		return 0;
	else {k=1;m=m/i;}
	     a=b;}
	}
	}
	if(j<=2)return 0;
	return k;
}
int main()
{  
	//用素数筛找到所有素数
	bool* a=new bool[1000001];
	int ii=0;
	for(;ii<99997;ii++)
	{  a[ii]=0;
	 a[ii+1]=0;
	 a[ii+2]=0;
	 a[ii+3]=0;
	}
	for(;ii<100001;ii++)
		a[ii]=0;
	for(int i=2;i<1000001;++i)
	{  if(a[i]==0)
	{

		int b=0;
		b=i+i;
while(b<1000001)
{  
	a[b]=1;
	b=b+i;
	}
	}
	}
	int b[100];
	int n;
	scanf("%d",&n);
	if(n<561)
		printf("0\n");
	else
	{   int count=1;
		b[0]=561;
		for(int i=562;i<n;i++)
		{   
			if(h(i,a))
			{  b[count]=i;
				count++;
			}
		}
	 printf("%d\n",count);
		for(int i=0;i<count;i++)
			printf("%d ",b[i]);
	}
}
