//written by kuangjianzhong EE-58
//time:4 ms 	memory:3132 KiB
#include<iostream>
#include<vector>
using namespace std;

int main()
{ int n,m,temp,Just_move,Hanoi;
  Just_move=Hanoi=0;
  cin>>n;
  cin>>m;
  for(int i=0;i<n;i++)
  { cin>>temp;
  	if(i==0) Hanoi= ((temp<<1) - 1)%m;
	else 
		if(temp==1) Hanoi=((Just_move<<1) + 1)%m;
		else Hanoi= ((Just_move<<1) + Hanoi+ 2*temp)%m;
    if(i==0) Just_move=temp%m;	
	else Just_move= ((Just_move<<1) + temp)%m;
  }
  cout<<Hanoi;
}
