//written by zhangyunqi
//time:204 ms 	memory:6260 KiB 
#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

class Tnode
{
 public:
	 int key1;
	 int key2;
	 int flag;
	 Tnode*  Lnode;
	 Tnode*  Rnode;
	 Tnode(int a,int b){key1=a;key2=b;Lnode=Rnode=NULL;}
	 Tnode() {Lnode=NULL;Rnode=NULL;}
};
Tnode* head;
class Node
{  
public:
	Tnode* now;
	Node * next;
	Node(Tnode *e,Node* a)
	{  now=e;next=a;}
};


class mystack //用模拟栈的方式来省时间
{
private:
	Node* top;
	int length;
public:
	void push(Tnode *e);
	bool pop(Tnode **e);
	void gettop(Tnode *e);
	bool isempty();
	mystack()
	{ top=NULL;length=0;}
};

void mystack::push(Tnode *e)
{   
	Node * a=new Node(e,top);
	top=a;
	length++;

}

bool  mystack::pop(Tnode **e)
{   
	if(length==0)
		return false;
	*e=top->now;
	Node* top2=top;
	top=top->next;
	delete top2;
	length--;
	return true;
}
void mystack::gettop(Tnode *e)
{   
	e=top->now;
}

bool mystack::isempty()
{    
	if(length==0)
		return 0;
	return 1;
}

bool charu(int key1,int key2)  //插入节点
{
	Tnode* a =new Tnode;
	Tnode* p2;
	a->key1=key1;
	a->key2=key2;

	if(head==NULL)
	{  
		head = a;
		return 1;
	}
	Tnode* p1=head;
	p1->flag=1;
	while(1)
	{  
		if(p1->flag==1)
	{
		if(key1<p1->key1)
		{   
			if(p1->Lnode!=NULL)
			{	p1=p1->Lnode;
			   // p1->flag=0;
			}
			else  
				{
				  p1->Lnode=a;
				  a->flag=0; 
			      break;
				}
		}
		else
		{ 
		   if(p1->Rnode!=NULL)
			  {  
				  p1=p1->Rnode;
				// p1->flag=0;
		   }
		   else
			  { p1->Rnode=a;
		   a->flag=0;
				break;
		   }
		}
	}
	else
	{
		if(key2<p1->key2)
		{   
			if(p1->Lnode!=NULL)
			{	p1=p1->Lnode;
			   // p1->flag=1;
			}
			else  
				{
				  p1->Lnode=a;
				  a->flag=1; 
			      break;
				}
		}
		else
		{ 
		   if(p1->Rnode!=NULL)
			 {  p1=p1->Rnode;
		     //  p1->flag=1;
		   }
		   else
			  { p1->Rnode=a;
		   a->flag=1;
				break;
		   }
		}
	}}
	return 1;
}
void zhongxu(int low1,int high1,int low2,int high2)  //搜索节点
{
	Tnode* p=head;
	mystack a;
   int count=0;
   int flag=1;
   bool m;
   int low,high;
   low=low1<low2?low1:low2;
   high=high1<high2?high2:high1;
   while(1)
   {
	   flag=0;
   while(p!=NULL)
   { if(p->flag==1)
   {
	   if(p->key1<=high1&&p->key1>=low1)
	   {  
		   if(p->key2<=high2&&p->key2>=low2)  //把度为2且符合要求的节点存起来
			   count++;
		   a.push(p);
		   p=p->Lnode;
	   }
	   else if(p->key1<=low1)
		p=p->Rnode;
	   else 
		   p=p->Lnode;
   }
   else
   {
	   	   if(p->key2<=high2&&p->key2>=low2)
	   {  
		   if(p->key1<=high1&&p->key1>=low1)   //把度为2且符合要求的节点存起来
			   count++;
		   a.push(p);
		   p=p->Lnode;
	   }
	   else if(p->key2<low2) 
		p=p->Rnode;
	   else 
		   p=p->Lnode;
   }
   }
   m=a.pop(&p);
   if(!m)
	   break;
   p=p->Rnode;
   }
   printf("%d\n",count);
}

int main()
{  
	int k,zz,key1,key2,m,n;
	int low1,low2,high1,high2;

	scanf("%d%d",&m,&n);
	k=n+m;
	for(;k>0;k--)
	{ 
	   scanf("%d",&zz);
	   if(!zz)
	   {  
		  scanf("%d%d",&key1,&key2);
		  charu(key1,key2);
		  continue;
	   }
	 scanf("%d%d%d%d",&low1,&high1,&low2,&high2);
	 zhongxu(low1,high1,low2,high2);
	}
}