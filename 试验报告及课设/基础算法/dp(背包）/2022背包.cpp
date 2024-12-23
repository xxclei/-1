#include<iostream>
#include<cmath>
#include<limits.h>
int a[101][3000];				//将 2022 拆分成不同的质数的和，请问最多拆分成几个？
using namespace std;

int max(int a,int b)
{if(a>=b)
return a;
else 
return b;		//比较大值函数 
}


int ss(int i)
{int p;
for(p=2;p<=sqrt(i);p++)
{if(i%p==0)
return 0;
}
return 1;	//判断素数函数 
}


int main()
{	int i,p,m;

int weight[10000];	//存储物品数值的数组(也就是质数) 
	int t=1;
	for(i=2;i<=2022;i++)
	{if(ss(i)==1)
		{weight[t]=i;		//重量就是数字 价值全是1; 
		t++;
		}
	}



for(p=1;p<=3000;p++)
a[0][p]=-999;		//满背包问题(把重量为 

a[0][0]=0;
for(i=1;i<=100;i++)
	for(p=1;p<=2022;p++)	
	{if(p>=weight[i])
		a[i][p]=max(a[i-1][p-weight[i]]+1,a[i-1][p]);
	else
		a[i][p]=a[i-1][p];}
		
m=a[1][2022];
for(i=2;i<=50;i++)
m=max(m,a[i][2022]);//取最大价值 

cout<<m;	
return 0;
}
