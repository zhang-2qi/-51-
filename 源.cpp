/*
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
int fenjie(int* a,int n,int *p)
{
	memset(a,0,100);
	int i=2;
	int j=0;
	while(n!=1)
	{  if(n%i==0)
	{  a[j]=i;
	j++;
	n=n/i;
	p[i]=0;
	i--;}
	i++;
	}
	return j;
}
int fenjie(int* a,int n)
{
	memset(a,0,100);
	int i=2;
	int j=0;
	while(n!=1)
	{  if(n%i==0)
	{  a[j]=i;
	j++;
	n=n/i;
	i--;
	}
	i++;
	}
	return j;
}
int main()
{   
	int n;
	int po=0;
	int count=1;
	int flag=0;
	int flag2=1;
	scanf("%d",&n);
	int *p=new int[n];
	 int a[100];
	 int opp[100];
	 opp[0]=561;
	 int prime[168]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
109, 113, 127, 131, 137, 139, 149, 151 ,157, 163 ,167, 173 ,179, 181 ,191, 193, 197, 199, 211 ,223,
227, 229, 233, 239, 241, 251, 257, 263, 269, 271 ,277 ,281 ,283, 293, 307, 311, 313, 317, 331 ,337,
347, 349, 353, 359, 367, 373, 379, 383, 389, 397 ,401 ,409 ,419, 421, 431 ,433, 439, 443, 449 ,457,
461, 463, 467, 479, 487, 491, 499, 503, 509, 521 ,523 ,541 ,547, 557, 563 ,569, 571, 577, 587 ,593,
599, 601, 607, 613, 617, 619, 631, 641, 643, 647 ,653 ,659 ,661 ,673, 677 ,683 ,691, 701, 709 ,719,
727, 733, 739, 743, 751, 757, 761, 769, 773, 787 ,797 ,809, 811 ,821, 823 ,827 ,829, 839, 853 ,857,
859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937 ,941, 947 ,953, 967 ,971 ,977, 983 ,991 ,997};
	 int isprime[1000];
	 memset(isprime,0,1000);
	for(int t=0;t<168;t++)
		isprime[prime[t]]=1;
	if(n<561)
		printf("0\n");
	else if(n<=600)
		printf("1\n561\n");
	else
	{  int *q=new int[n];
		for(int i=700;i<=n;i++)
		{   
	 if(i%2==0)
		 continue;
	 	 	for(int ti=0;ti<n;ti++)
		p[ti]=1;
		int m1=fenjie(a,i,p);
		if(m1==1)
			continue;
		int count1=0;
		for(int ppl=0;ppl<m1;ppl++)
			if(isprime[a[ppl]]==1)
				count1++;
		if(count1<=3)
			continue;
		 flag=0;
		 flag2=1;
	
		for(int ii=0;ii<n;ii++)
			q[ii]=-1;
			for(int j=2;j<i;j++)
		{
			flag=0;
		   int b[100];
		   int m2=fenjie(b,j);
		for(int ll=0;ll<m2;ll++)
		{ if(p[b[ll]]==0)
		  { flag=1;
		  break;
		}
		}
		   if(!flag)
		   {
			 int uu=1;
			 if(m2==0)
			 { m2++;
			   b[0]=j;
			 } 
			   for(int k=0;k<m2;k++)
		   {   if(q[b[k]]==-1)
			   {  int tem=b[k]%i;
			    int tem2=tem;
				int tem3=1;
				int ppp;
				ppp=0;  
				   for(ppp=0;ppp<i-4;ppp+=2)
			      { tem=tem2*tem;
				   tem3=tem2*tem3;
				   tem%=i;
				   tem3%=i;
				   }
				  // printf("aaaa %d %d\n",ppp,i-2);
				 //  --ppp;
				   for(;ppp<i-2;++ppp)
			 {   tem=tem2*tem;
				   tem%=i;
				   }
				   tem=tem3*tem;
				   tem%=i;
				   q[b[k]]=tem;
				  // pp[b[k]]
				   uu*=tem;
				   uu%=i;
			   }
		   else
			   {uu*=q[b[k]];
			   uu%=i;
			   }
		}
			   uu%=i;

			   q[j]=uu; 
			    if(uu!=1)
			   flag2=0;		

		}
		   if(flag2==0)
			   break;;
	}
			if(flag2)
		 { opp[count]=i;
			 count++;
			
			}
}
		printf("%d\n",count);
		 for(int i=0;i<count;i++)
		   printf("%d ",opp[i]);

}
}
*/
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