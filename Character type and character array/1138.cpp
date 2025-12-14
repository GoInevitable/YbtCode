/**
 * @author  Jane Smith
 * @file    1138.cpp
 * @date    2025-12-星期五
 * @version 1.0
 * @problem 将字符串中的小写字母转换成大写字母
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
char s[101];
int main()
{
    cin.getline(s,100);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            putchar(s[i] -= 32);
            //printf("%c",s[i] -= 32);
        }else{
            putchar(s[i]);
            //printf("%c",s[i]);
        }
    }
    return 0;
}
