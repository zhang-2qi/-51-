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