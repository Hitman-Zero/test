#include <iostream>
#include<cstring>
using namespace std;
#define max 100
void LCS(int i,int j,char *x,int b[][max])
{
	if(i==0||j==0) return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,x,b);
		cout<<x[i-1];
	}
	else if(b[i][j]==2)
	LCS(i-1,j,x,b);
	else LCS(i,j-1,x,b);
}
int main()
{
	int m;
	int n;
	char x[100];
	char y[100];
	cout<<"请输入两个字符串:"<<endl; 
	cin>>x>>y;
	m=strlen(x);
	n=strlen(y);
	int c[m+1][n+1];
	int b[max][max];
	int i,j;
	for(i=0;i<=m;i++) c[i][0]=0;
	for(i=0;i<=n;i++) c[0][i]=0;
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	{
		if(x[i-1]==y[j-1])
		{
		c[i][j]=c[i-1][j-1]+1;
		b[i][j]=1;
	    }
		else if(c[i-1][j]>=c[i][j-1])
		{
		c[i][j]=c[i-1][j];
		b[i][j]=2;
	    }
		else 
		{
		c[i][j]=c[i][j-1];
		b[i][j]=3;
	    }
	}
	cout<<"最长子序列为:"<<endl;
	LCS(m,n,x,b);
	return 0; 
} 



