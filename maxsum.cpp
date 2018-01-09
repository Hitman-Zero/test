#include<iostream>
using namespace std;
int maxsum(int n,int *a)
{
	int sum=0,b=0;
	for(int i=0;i<n;i++)
	{
		if(b>0) b+=a[i];
		else b=a[i];
		if(b>sum)
		sum=b;
	}
	return sum;
}
int main()
{
	int n;
	int a[100];
	cout<<"请输入数组长度:"<<endl;
	cin>>n;
	cout<<"请输入数组"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"最大字段和为:"<<endl;
	cout<<maxsum(n,a); 
  return 0;
}
