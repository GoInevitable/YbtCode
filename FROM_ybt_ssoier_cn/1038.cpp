#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    if(x==0||n-(y/x+(y%x!=0))<0){
		cout<<0;
		return 0;
    }else if (y % x == 0)
    {
        cout << n - (y / x);
    }
    else
    {
        cout << n - (y / x) - 1;
    }
    return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=1038 1038：苹果和虫子
//https://www.luogu.com.cn/problem/P5709 P5709 【深基2.习6】Apples Prologue / 苹果和虫子