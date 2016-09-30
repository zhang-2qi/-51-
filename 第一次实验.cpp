#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

bool fenjie(int i,int* m,int* length)
{   
	//int flag=1;
	int n=0;
	int q=2;
	int pre=0;
	while(i!=1)
	{  
		if(i%q==0)
		{   //q++;
			if(pre==q)
				return 0;
			pre=q;
		    i=i/q;
			m[n]=q;
			n++;
			q--;
			
		}
		q++;
	}
	*length=n;
	return 1;
}

int main()
{  
	int* a=new int[1000001];
	int ii=0;
	for(;ii<99997;ii++)
	{  a[ii]=0;
	 a[ii+1]=0;
	 a[ii+2]=0;
	 a[ii+3]=0;
	}
	for(;ii<100001;ii++)
		a[ii]=0;
	//a[2]=1;

	for(int i=2;i<1000001;++i)
	{  if(a[i]==0)
	{
		int j=2;
		int b;
		b=j*i;
while(b<1000001)
{  
	a[b]=1;
	++j;
	b=j*i;
	}
	}
	}
//	printf("lalallaa");
	int n;
	scanf("%d",&n);
	int p1[100],p2[100];
	p2[0]=561;
	int count=1;
	if(n<561)
		printf("0\n");
	else if(n<601)
		printf("1\n561\n");
	else
	{  int count1=0;
	int length=0;
		for(int i=1105;i<n;i++)
		{  count1=0;
		length=0;
			if(i%2==0)
		  continue;
		bool m1=fenjie(i,p1,&length);
		if(!m1)
		continue;
		if(length==1)
			continue;
		int flag=1;
		for(int h=0;h<length;h++)
		{   if(a[p1[h]]==0)
		  { 
		    if((i-1)%(p1[h]-1)==0)
		      ;
			else
			{	flag=0;
			    break;
			}
			count1++;
		}
		}
			if(!flag||count1<3)
				continue;
			
           p2[count]=i;
		   count++;
		}
		printf("%d\n",count);
		for(int i=0;i<count;i++)
			printf("%d ",p2[i]);
		printf("\n");
}
}