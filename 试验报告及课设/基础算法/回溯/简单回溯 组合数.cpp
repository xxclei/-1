#include<iostream>
using namespace std;
int a[100];
int ts[100];
int k;
int contain(int a[100],int n,int m,int t)
{
	
if(k+n-m+1<t)	
return 0;	//如果剩余的不够组成一组组合数则结束 


if(k==t)
{for(int i=0;i<=t-1;i++)
cout<<ts[i]<<" ";
cout<<endl;
return 1;
}			//数组满了则输出 



ts[k++]=a[m];	//选择数字 
contain(a,n,m+1,t);
k--;
contain(a,n,m+1,t);	
return 0;	
	
}
int main()
{
int n,t;
int i;
cout<<"输入总共有几个数"<<endl; 
cin>>n;
cout<<"输入要选几个数"<<endl;
cin>>t;
cout<<"输入数字"<<endl;
for(i=1;i<=n;i++)
cin>>a[i];	
k=0;
contain(a,n,1,t);
	
	
	
	
	
return 0;
}
