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
	int p;					//检查是否符合棋盘摆放要求 
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

}cout<<endl;			//选出一种就输出 
return 1;}





int queen(int n)
{

while(k>0)
{

a[k]++;		//放置第一个棋子 
while(check(k)==0&&a[k]<=n)	//违反规定但下一位置可放在棋盘之内 
{
a[k]++;
}	//通常情况进行列的下一个值 

if(a[k]<=n)//如果这一列能够放棋子 
{	
	
	if(k==n)
	{
	number++;
	cout<<number<<endl; //放满了则输出 
	output(n);}
	else
	{k++;   //否则选取下一列旗子 
	a[k]=0; 
	}
}
else    //不能在任何行放置，重新回到上一列继续按照原来行数加1开始放 
k--;
}
return 0;





}



 








