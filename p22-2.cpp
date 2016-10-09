#include<stdio.h>  
#include<iostream>  
#include<memory.h>  
#include<algorithm>  
#include<math.h>  
using namespace std;  
int prime[650100];  
typedef long long ll;  
//算x的n次方的
ll pow_mod(ll x,ll n,ll mod)  
{  
    ll res=1;  
    while(n)  
    {  
        if(n&1) res=res*x%mod;  
        x=x*x%mod;  
        n>>=1;  
    }  
    return res;  
}  
//使用素数筛找出所有素数存起来
void pri()  
{  
    int i,j;  
    memset(prime,0,sizeof(prime));  
    int m=(int)sqrt(650100+0.5);  
    for(i=2;i<=m;i++)  
    {  
        if(prime[i]==0)  
        {  
            for(j=i*i;j<=650100;j+=i)  
                prime[j]=1;  
        }  
    }  
  
}

ll a[500];

int main()  
{  
      pri();
      ll N,p(0);
	  scanf("%lld",&N); 
    for(ll n=561;n<=N;n++)  
    {  
  
        if(!prime[n])  
        {  
            
            continue;  
        }  
        int tag=1;  
        for(ll i=2;i<=n-1;i++)  
        {  
            if(pow_mod(i,n,n)!=i)  
            {
            	
                tag=0;  
                break;  
            }  
        }  
  
        if(tag)
		{
			a[p]=n;
			p++;
		}
          
    }
	cout<<p<<endl;
	for(ll k=0;k<p;k++)
	{
		cout<<a[k]<<endl;
	}  
    return 0;  
} 