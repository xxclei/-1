#include<iostream>
using namespace std;
int a[100];
int ts[100];
int k;
int contain(int a[100],int n,int m,int t)
{
	
if(k+n-m+1<t)	
return 0;	//���ʣ��Ĳ������һ������������ 


if(k==t)
{for(int i=0;i<=t-1;i++)
cout<<ts[i]<<" ";
cout<<endl;
return 1;
}			//������������� 



ts[k++]=a[m];	//ѡ������ 
contain(a,n,m+1,t);
k--;
contain(a,n,m+1,t);	
return 0;	
	
}
int main()
{
int n,t;
int i;
cout<<"�����ܹ��м�����"<<endl; 
cin>>n;
cout<<"����Ҫѡ������"<<endl;
cin>>t;
cout<<"��������"<<endl;
for(i=1;i<=n;i++)
cin>>a[i];	
k=0;
contain(a,n,1,t);
	
	
	
	
	
return 0;
}
