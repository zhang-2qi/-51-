//written by lizhaozhu
//time:988 ms 	memory:5476 KiB
#include<iostream>
using namespace std;
struct TNode{
	int key[2];
	TNode *left,*right;
};
void Insert(TNode **p,int key[2],int level)
	{   TNode* p1;
		//TNode* p2=p1;
		if(*p==NULL)
		{p1=new TNode;p1->key[0]=key[0];p1->key[1]=key[1];p1->left=NULL;p1->right=NULL;*p=p1;}
        else if(key[level]<(*p)->key[level])
            Insert(&((*p)->left), key,1-level);
        else
            Insert(&((*p)->right),key,1-level);
}
void Range(int low[2],int high[2],TNode **p,int level,int &t)
	{TNode* p1=*p;
		if(p1)
	    {
			if((low[0]<=p1->key[0])&&(p1->key[0]<=high[0])&&(low[1]<=p1->key[1])&&(p1->key[1]<=high[1])) 
		{t=t+1; }
		 if(low[level]<=p1->key[level]) Range(low, high, &(p1->left), 1-level, t);
         if(high[level]>=p1->key[level]) Range(low, high, &(p1->right), 1-level, t);
	     }
	}
int main()
{int m,n,p1,k;
 int low[2],high[2],key[2];
 int t;
 k=0;
 cin>>m>>n;
 TNode *root=NULL;
 int *result=new int[n];
 for(int i=1;i<=(m+n);i++)
 {cin>>p1;
 if(p1==0){cin>>key[0]>>key[1];Insert(&root,key,0);}
 if(p1==1){cin>>low[0]>>high[0]>>low[1]>>high[1];t=0;Range(low,high,&root,0,t);result[k]=t;k=k+1;}
 }
 for(int i=0;i<n;i++){cout<<result[i]<<endl;}
 return 0;
}