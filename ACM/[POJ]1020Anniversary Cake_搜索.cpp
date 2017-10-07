#include <iostream>
#include <cstdlib>
using namespace std;
int n,m;
int S;
int a[11],c[41];
bool check(int x,int y,int w)
{
	if(x+w-1<S && y+w-1<S)
	{
		for(int i=x;i<x+w;i++)
		{
			//这一句如果写成if(c[i]+w>S)会超时，虽然结果一样，但效率天壤之别.
			//原因是否是cache？
			if(c[i]>y)
				return false;
		}
		return true;
	}
	return false;
}
bool dfs(int k)
{
	if(k>=m)
	{
		return true;
	}
	int p=0;
	for(int i=0;i<S;i++)
	{
		if(c[i]<c[p])
			p=i;
	}
	for(int i=0;i<11;i++)
	{
		if(a[i]>0 && check(p,c[p],i))
		{
			a[i]--;
			for(int j=p;j<p+i;j++)
			{
				c[j]+=i;
			}
			if(dfs(k+1))return true;
			a[i]++;
			for(int j=p;j<p+i;j++)
			{
				c[j]-=i;
			}
		}
	}
	return false;
}
int main()
{
	int totalArea;
	cin>>n;
	while(n--)
	{
		cin>>S;
		cin>>m;
		totalArea=0;
		int t;
		memset(a, 0, sizeof(a)); 
		memset(c, 0, sizeof(c));
		for (int i = 0; i < m; i++)
		{
			cin>>t;totalArea+=t*t;
			a[t]++;
		}
		if(totalArea!=S*S)
		{
			cout<<"HUTUTU!"<<endl;
			continue;
		}
		if(!dfs(0))
			cout << "HUTUTU!" << endl;
		else
			cout << "KHOOOOB!" << endl;
	}
}
