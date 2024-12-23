#include<iostream>
#include<vector>
using namespace std;
int main() 
{
int a[100000];
int d[100000];
int i=0;
int n,j;
int len,len1;//len为总计最长产生的LIS 
cout<<"输入序列长度"<<endl; 
cin>>n;
cout<<"输入数据"<<endl; 
while(i!=n)
{cin>>a[i];
i++;
}
d[0]=1;//d[n]为第n+1个数和之前所有子序能组成的最长的LIS 若组成不了则为1 

for(i=1;i<=n-1;i++)
{d[i]=1;    //如果该位置和之前不能组成IS 那么就为1 
	for(j=0;j<=i-1;j++)
		{if(a[i]>=a[j])	//能够和之前的子序列连上 
			 {if(d[j]+1>d[i])	
		 	d[i]=d[j]+1;	//如果能组成更长的子序列则更新 
			 }
		if(d[i]>len)
		len=d[i];	//求d数组中的最大值 
		 } 
	
}
cout<<"最长递增子序列"<<len<<endl;	
return 0;
}
