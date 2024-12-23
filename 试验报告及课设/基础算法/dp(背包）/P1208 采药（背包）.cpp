#include<iostream>
using namespace std;
int clear(int *a,int *b)
{int i;
for(i=1;i<=100;i++)
a[i]=0;
b[i]=0;
return 0; 
}
int main()
{
int weight[1000];
int value[1000];
int dp[2000][200];
int T;
int m;
int M;
int i;
int j;
int max; 
while(cin>>T)
{
		for(i=1;i<=1000;i++)
		for(j=1;j<=100;j++)
		dp[i][j]=0;	
cin>>m;
M=m;
clear(weight,value);
i=1;
while(m--)
{
cin>>weight[i];
cin>>value[i];	
i++;
}
for(i=1;i<=100;i++)
dp[0][i]=0;
for(i=0;i<=1000;i++)
dp[i][0]=0;
	for(i=1;i<=T;i++)
	{	for(j=1;j<=M;j++)
		{
			if(weight[j]>i)//×°²»ÏÂ
			{dp[i][j]=dp[i][j-1];
			continue;
			}
			if(dp[i-weight[j]][j-1]+value[j]>dp[i][j-1])
				dp[i][j]= dp[i-weight[j]][j-1]+value[j];
			
			if(dp[i-weight[j]][j-1]+value[j]<=dp[i][j-1])
				dp[i][j]= dp[i][j-1];
		}
	}
cout<<dp[T][M]<<endl;
}
return 0;
}
