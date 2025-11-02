#include<cstdio>
#include<cstring>
using namespace std;
int n,i,j,ll,len,ans;
char s[11000];
main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	ll=1;
	for(i=1;i<=len;i++)
	{
		for(j=ll;j<=i;j++)
			if(s[j]!=s[len-i+j-ll+1])
				break;
		if(j>i)
		{
			ll=i+1;
			if(i*2<=len)
				ans=ans+2;
			else
				ans++;
		}
		if(ll*2-1>len)
			break;
	}
	if(ans==1)
		printf("NO");
	else
		printf("YES\n%d",ans);
}

