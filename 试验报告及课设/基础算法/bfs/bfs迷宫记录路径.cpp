#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char way[500];
int icount=0;
int map[100][100];
int mark[100][100];

void putin(int map[100][100],int n,int m)
{int i;
int j;
for(i=1;i<=m;i++)
	{
	for(j=1;j<=n;j++)
	scanf("%1d",&map[i][j]);}		//输入地图 
	return;
}

int findway(int mark[100][100],int n,int m)
{
if(n==1&&m==1)						//存储路径并输出 
return 1;
if(mark[m][n]==10)
{way[icount]='D';
icount++; 
return findway(mark,n,m-1);
}
if(mark[m][n]==11)
{way[icount]='L';
icount++; 
return findway(mark,n+1,m);
}
if(mark[m][n]==12)
{way[icount]='R';
icount++; 
return findway(mark,n-1,m);
}
if(mark[m][n]==13)
{way[icount]='U';
icount++; 
return findway(mark,n,m+1);	
}

}
void putout(int map[100][100],int n,int m)
{int i;
int j;
for(i=1;i<=m;i++)
	{
	for(j=1;j<=n;j++)
	cout<<mark[i][j]<<" ";
	cout<<endl;
}
		return;
}

void bfs(int map[100][100],int mark[100][100],int n,int m,int i,int j)
{
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};	//方向向量 
queue<pair<int,int>>q;	//用队列实现bfs的最外层 
mark[1][1]=1;		
q.push({1,1});
while(!q.empty())
{

if(q.front().first==m&&q.front().second==n)
{//cout<<mark[m][n]-1<<endl;
mark[0][0]=1;
break;
}
for(int i=0;i<=3;i++)
	{
		if(map[q.front().first+dy[i]][q.front().second+dx[i]]==0&&mark[q.front().first+dy[i]][q.front().second+dx[i]]==0)
		{mark[q.front().first+dy[i]][q.front().second+dx[i]]=i+10;
		q.push({q.front().first+dy[i],q.front().second+dx[i]});	//利用方向向量的下标在数组里记录路径 
		}
	}									//通过队列依次寻找路径 
//	cout<<q.front().first<<q.front().second<<endl;
	q.pop();	
}	
		
}

int main()
{
int n,m,i,j;
cin>>m;
cin>>n;

putin(map,n,m);

memset(mark,0,sizeof(mark)); 

for(i=0;i<=n;i++)
mark[0][i]=1;	
for(i=0;i<=n;i++)
mark[m+1][i]=1;	
for(i=0;i<=m;i++)
mark[i][0]=1;	
for(i=0;i<=m;i++)
mark[i][n+1]=1;	//将地图外侧封锁 
bfs(map,mark,n,m,1,1);
//putout(map,n,m)	;
findway(mark,n,m);
reverse(way,way+strlen(way));
puts(way);
	
return 0;
	
	
}
