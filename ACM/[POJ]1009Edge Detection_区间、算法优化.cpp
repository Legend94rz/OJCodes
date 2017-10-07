/*
效率稍微有些慢。对于discuss里的一组数据TLE。
但是能过。
主要慢在漂浮法上：如果有1000个区间，每个区间会计算出5个局部结果，漂浮法求解时会花5000^2的时间
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class desc
{
public:
	int s,t;
	int px;
	desc(int data,int st,int len)
	{
		s=st;
		t = s+len-1;
		px=data;
	}
	int len()
	{
		return t-s+1;
	}
};
vector<desc> a;
vector<desc> ans;
int n,x,y,start;
int cmp(const desc& A, const desc& B)
{
	return A.px>B.px;
}
int cmp_st(const desc& A,const desc& B)
{
	return A.s<B.s;
}
void Float(int st, int ed, int val, int I)
{
	for (int i = I; i >= 0; i--)
	{
		if (st<ans[i].s)
		{
			Float(st, min(ed, ans[i].s - 1), val, I - 1);
			st = ans[i].s + 1;
		}
		if (ed>ans[i].t)
		{
			Float(max(st, ans[i].t + 1), ed, val, I - 1);
			ed = ans[i].t - 1;
		}
		if (st >= ans[i].s && ed <= ans[i].t)
			return;
	}
	if (ed >= st)
	{
		ans.push_back(desc(val, st, ed - st + 1));
	}
}

int main()
{
	//freopen("a.txt","w",stdout);
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)break;
		a.clear();ans.clear();
		start=1;
		for(;;)
		{
			scanf("%d%d",&x,&y);
			if(x==y && x==0)break;
			a.push_back(desc(x,start,y));
			start+=y;
		}
		vector<desc> tmp;
		int L = start-1;
		for (size_t i = 0; i < a.size(); i++)
		{

			//区间i上部
			int j=i-1;
			while(j>=0 && a[j].t>=a[i].s-1-n && a[j].t<=a[i].s-1)
			{
				if(a[j].t==a[i].s-1 && a[i].s%n!=1)
				{
					tmp.push_back(desc(abs(a[i].px-a[j].px),a[i].s,1));
				}
				int left = max(a[i].s, a[j].s+n-(a[j].s%n != 1));
				int right = min(a[i].t, a[j].t+n+(a[j].t%n != 0));
				if(right-left>=0)
					tmp.push_back(desc(abs(a[i].px-a[j].px),left,right-left+1));
				j--;
			}
			//中部0
			tmp.push_back(desc(0,a[i].s,a[i].len()));
			//区间i下部
			j=i+1;
			while(j<a.size() && a[j].s>=a[i].t+1 && a[j].s<=a[i].t+n+1)
			{
				if(a[j].s==a[i].t+1 && a[i].t%n!=0)
				{
					tmp.push_back(desc(abs(a[j].px-a[i].px), a[i].t, 1));
				}
				int left = max(a[i].s,a[j].s-n-(a[j].s%n!=1));
				int right = min(a[i].t,a[j].t-n+(a[j].t%n!=0));
				if(right-left>=0)
					tmp.push_back(desc( abs(a[j].px-a[i].px), left, right-left+1 ));
				j++;
			}
		}
		//合并
		sort(tmp.begin(), tmp.end(), cmp);
		for (int i = 0; i<tmp.size(); i++)
			Float(tmp[i].s, tmp[i].t, tmp[i].px, ans.size() - 1);
		//输出
		sort(ans.begin(), ans.end(), cmp_st);
		printf("%d\n",n);
		for (int i = 0; i<ans.size();)
		{
			int j = i + 1;
			while (j<ans.size() && ans[j].s == ans[j - 1].t + 1 && ans[j].px == ans[j - 1].px)
				j++;
			printf("%d %d\n",ans[i].px, ans[j - 1].t - ans[i].s + 1);
			i = j;
		}
		printf("0 0\n");
	}
	printf("0\n");
	//fclose(stdout);
}