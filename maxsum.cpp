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
	cout<<"���������鳤��:"<<endl;
	cin>>n;
	cout<<"����������"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"����ֶκ�Ϊ:"<<endl;
	cout<<maxsum(n,a); 
  return 0;
}
