#include <iostream>
using namespace std;
int a[200][200]; 
int v[200][200];			   
int max(int a,int b)
{if(a>=b)
return a;
return b;
}
int main()
{int N,K;
int maxx;
cin>>N;
K=N;
int i=0,p;
while(N--)
  {for(p=0;p<=i;p++)
      {cin>>a[p][i];
      }
  i++;    	//���� 
  }
  
  i=0;
  N=K;
  v[0][0]=a[0][0];
  for(i=1;i<=K-1;i++)
  {for(p=0;p<=i;p++)	
      {
      if(p==0)
      {v[p][i]=v[0][i-1]+a[p][i];}	
      if(p==i)
      {v[p][i]=v[i-1][i-1]+a[p][i];			//����ֱ����dpֵ 
    }										
    if(p>0&&p<i)
      {v[p][i]=max(v[p-1][i-1],v[p][i-1])+a[p][i];	//�м�ȡ��һ�����ֵ 
    }}
  }
  
   N=K;
  i=0;
  maxx=v[0][K-1];
 for(i=0;i<=K-2;i++)
{if(maxx<=v[i+1][K-1])
maxx=v[i+1][K-1];
}
 cout<<maxx;
  return 0;
}
