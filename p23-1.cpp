//written by zhangyunqi-EE-51
//��ͳ����������һǰһ������ָ��
//time:504 ms 	memory:13312 KiB
#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
#pragma warning(disable:4703)
using namespace std;
template <class ElemType>
class Node
{
public:
	ElemType data;
	Node<ElemType>* next;
};
template<class ElemType>
class Linklist
{  
public:
	Linklist() {head = NULL;}
	Node<ElemType>* head;
	//int length;
};
int main()
{ 
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  Linklist<int>* p=new Linklist<int>;
  Node<int>* pos;
  Node<int>* last;
  Node<int>* d=new Node<int>;
  last=pos=p->head = d;
  d->data=1;
  pos=d;
    for(int i=2;i<m+1;++i)
  {
	  
	  Node<int>* a=new Node<int>;
      a->data=i;
	  pos->next=a;
	  last=pos;
	  pos=a;
	 
  }
  pos->next=p->head;//�γ�һ����������
  for(int i=m+1;i<n+1;++i)
  {
    Node<int>* a=new Node<int>;
			a->data=i;
	  for(int j=0;j<k;++j)//ÿ��last����pos֮ǰ
	    {  //b=pos;
		last=pos;
			pos=pos->next;
	  }	
 	  if((pos->data)&1)
	  {  

		  last->next=a;
		 a->next=pos;
	  }
	  else
	  {  

		 			a->next=pos->next;
			pos->next=a;
		
	  }	  
			
  }
  int count=0;
  last=pos;
     pos=pos->next;	
  for(int i=0;i<n-m;++i)
  { 
   for(int j=0;j<k-1;++j)
    {last=pos;
     pos=pos->next;	
	}
	Node<int>* b;
	b=pos;
	//printf("m %d",b->data);
	last->next=b->next;
	delete b;
	b=NULL;
	pos=last->next;
  }
  int i=0;
    for(;i<m-4;i=i+4)//�������ֻ�ǵ������������ѣ�����������Ҳ����
  {   
	  if(pos->data<=m)
		  count++;
	  pos=pos->next;
	  	  if(pos->data<=m)
		  count++;
	  pos=pos->next;
	  	  if(pos->data<=m)
		  count++;
	  pos=pos->next;
	  	  if(pos->data<=m)
		  count++;
	  pos=pos->next;

  }
	for(;i<m;++i)
	{
	  if(pos->data<=m)
		  count++;
	  pos=pos->next;
	}
	 printf("%d\n",count);
	 Node<int>* l;
	  i=0;
	 for(i=0;i<m-5;i=i+4)
	 {  
		 l=pos;
		 pos=pos->next;
		 delete l;
		 l=pos;
		 pos=pos->next;
		 delete l;
		 		 l=pos;
		 pos=pos->next;
		 delete l;
		 		 l=pos;
		 pos=pos->next;
		 delete l;
	 }
	 for(;i<m-1;++i)
	 {
	 		 l=pos;
		 pos=pos->next;
		 delete l;
	 }
	 delete pos;
	 p=NULL;
	 pos=last=NULL;
  }
