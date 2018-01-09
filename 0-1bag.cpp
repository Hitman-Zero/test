#include<iostream>
using namespace std;
#define max1 100
int min(int a,int b)
{
	if(a>=b)return b;
	else return a;
}
int max(int a,int b)
{
	if(a>=b)return a;
	else return b;
}
void bag(int *v,int *w,int c,int n,int m[][max1])
{
	int jmax=min(w[n]-1,c);
	for(int j=0;j<=jmax;j++) m[n][j]=0;
	for(int j=w[n];j<=c;j++) m[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		jmax=min(w[i]-1,c);
		for(int j=0;j<=jmax;j++)
		m[i][j]=m[i+1][j];
		for(int j=w[i];j<=c;j++)
		m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}
	m[1][c]=m[2][c];
	if(c>=w[1])
	m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}
void traceback(int m[][max1],int *w,int c,int n,int *x)
{
	for(int i=1;i<n;i++)
	if(m[i][c]==m[i+1][c])
	x[i]=0;
	else 
	{
		x[i]=1;
		c-=w[i];
	}
	x[n]=(m[n][c])?1:0;
}
int main()
{
	int v[max1];
	int w[max1];
	int c;
	int n;
	int m[max1][max1];
	int x[max1];
	cout<<"输入物品种类:"<<endl;
	cin>>n;
	cout<<"输入重量数组:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	cout<<"请输入价值数组:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cout<<"请输入背包容量:"<<endl;
	cin>>c;
	bag(v,w,c,n,m);
	traceback(m,w,c,n,x);
	cout<<"结果如下:"<<endl;
	for(int i=1;i<=n;i++)
	cout<<x[i];
	
	return 0;
}
