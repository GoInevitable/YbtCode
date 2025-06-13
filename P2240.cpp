#include<bits/stdc++.h>
using namespace std;
int n;//有n堆金币
double t,v[101],w[101],a[101],ans;//t:背包容量 v：价值 w:重量 a:性价比 ans:答案
int main()
{
	cin>>n>>t;//读入
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
		a[i]=v[i]/w[i];//求性价比
	}
	for(int i=1;i<=n;i++)//冒泡排序
	{
		for(int j=1;j<n;j++) 
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(v[j],v[j+1]);
				swap(w[j],w[j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(t-w[i]>-0.000001)//浮点数不能相等
		{
			t-=w[i];
			ans+=v[i];
		}
		else
		{
			ans+=t*a[i];//把金币分割
			break;//跳出循环
		}
 	}
 	printf("%.2lf",ans);//保留两位小数输出
 	return 0;//完美结束
}