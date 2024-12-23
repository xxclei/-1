#include<iostream>
using namespace std;
int a[100][100];
int b[100][100];
int tempsizex[100];
int tempsizey[100];
int k=0;
int count=0;
void typein(int a[100][100],int m,int n)
{for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		cin>>a[i][j];
}							// ‰»ÎµÿÕº 



void search(int a[100][100],int beginx,int beginy,int endx,int endy)
{	
	
	if(a[beginx][beginy]==1||b[beginx][beginy]==2)
	{
	return;}
	tempsizex[k]=beginx; // 
	tempsizey[k]=beginy;
	count++;
	k++;
	cout<<beginx-1<<" "<<beginy-1<<endl;
	if(beginx==endx&&beginy==endy)
	{for(int o=0;o<=k;o++)
	//cout<<tempsizex[o] -1<<" "<<tempsizey[o]<<endl;
//	cout<<endl<<endl;
//	k--;
	return;
		}
	
	b[beginx][beginy]=2;
	search(a,beginx-1,beginy,endx,endy);
	search(a,beginx+1,beginy,endx,endy);
	search(a,beginx,beginy-1,endx,endy);
	search(a,beginx,beginy+1,endx,endy);
	
}
int main()
{
int m;
int beginx,beginy,endx,endy;
int n;
int i,j;
cin>>m;
cin>>n;
typein(a,m,n);
cin>>beginx;
cin>>beginy;
cin>>endx;
cin>>endy;
for(i=0;i<=99;i++)
{a[0][i]=1;
a[i][0]=1;
}
for(i=0;i<=n+1;i++)
{a[m+1][i]=1;
}
for(i=0;i<=m+1;i++)
{a[i][n+1]=1;
}
k=0;
search(a,beginx+1,beginy+1,endx+1,endy+1);
cout<<count;
	
	
	
	
	
	
	
	
}
