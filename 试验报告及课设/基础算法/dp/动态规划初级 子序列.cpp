#include<iostream>
#include<vector>
using namespace std;
int main() 
{
int a[100000];
int d[100000];
int i=0;
int n,j;
int len,len1;//lenΪ�ܼ��������LIS 
cout<<"�������г���"<<endl; 
cin>>n;
cout<<"��������"<<endl; 
while(i!=n)
{cin>>a[i];
i++;
}
d[0]=1;//d[n]Ϊ��n+1������֮ǰ������������ɵ����LIS ����ɲ�����Ϊ1 

for(i=1;i<=n-1;i++)
{d[i]=1;    //�����λ�ú�֮ǰ�������IS ��ô��Ϊ1 
	for(j=0;j<=i-1;j++)
		{if(a[i]>=a[j])	//�ܹ���֮ǰ������������ 
			 {if(d[j]+1>d[i])	
		 	d[i]=d[j]+1;	//�������ɸ���������������� 
			 }
		if(d[i]>len)
		len=d[i];	//��d�����е����ֵ 
		 } 
	
}
cout<<"�����������"<<len<<endl;	
return 0;
}
