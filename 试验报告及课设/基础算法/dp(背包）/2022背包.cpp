#include<iostream>
#include<cmath>
#include<limits.h>
int a[101][3000];				//�� 2022 ��ֳɲ�ͬ�������ĺͣ���������ֳɼ�����
using namespace std;

int max(int a,int b)
{if(a>=b)
return a;
else 
return b;		//�Ƚϴ�ֵ���� 
}


int ss(int i)
{int p;
for(p=2;p<=sqrt(i);p++)
{if(i%p==0)
return 0;
}
return 1;	//�ж��������� 
}


int main()
{	int i,p,m;

int weight[10000];	//�洢��Ʒ��ֵ������(Ҳ��������) 
	int t=1;
	for(i=2;i<=2022;i++)
	{if(ss(i)==1)
		{weight[t]=i;		//������������ ��ֵȫ��1; 
		t++;
		}
	}



for(p=1;p<=3000;p++)
a[0][p]=-999;		//����������(������Ϊ 

a[0][0]=0;
for(i=1;i<=100;i++)
	for(p=1;p<=2022;p++)	
	{if(p>=weight[i])
		a[i][p]=max(a[i-1][p-weight[i]]+1,a[i-1][p]);
	else
		a[i][p]=a[i-1][p];}
		
m=a[1][2022];
for(i=2;i<=50;i++)
m=max(m,a[i][2022]);//ȡ����ֵ 

cout<<m;	
return 0;
}
