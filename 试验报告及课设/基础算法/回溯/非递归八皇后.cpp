#include<iostream>
#include<math.h>
using namespace std;
int a[20];
int number=0;
int k=1;
int n;
int output(int n);
int check(int k);
int queen(int m);


int main()
{
	for(int j=1;j<=20;j++)
	{
	a[j]=0;
	}
a[1]=0;
cin>>n;
queen(n);
return 0;
}


int check(int k)
{
	int p;					//����Ƿ�������̰ڷ�Ҫ�� 
	{for(p=1;p<=k-1;p++)
		if(a[k]==a[p]||abs(a[p]-a[k])==abs(p-k)){
		return 0;
	}
	}							
return 1;
}

int output(int n)
{
for(int i=1;i<=n;i++)
{cout<<a[i];

}cout<<endl;			//ѡ��һ�־���� 
return 1;}





int queen(int n)
{

while(k>0)
{

a[k]++;		//���õ�һ������ 
while(check(k)==0&&a[k]<=n)	//Υ���涨����һλ�ÿɷ�������֮�� 
{
a[k]++;
}	//ͨ����������е���һ��ֵ 

if(a[k]<=n)//�����һ���ܹ������� 
{	
	
	if(k==n)
	{
	number++;
	cout<<number<<endl; //����������� 
	output(n);}
	else
	{k++;   //����ѡȡ��һ������ 
	a[k]=0; 
	}
}
else    //�������κ��з��ã����»ص���һ�м�������ԭ��������1��ʼ�� 
k--;
}
return 0;





}



 








