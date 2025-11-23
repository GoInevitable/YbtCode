/** 
 * @author  Jane Smith
 * @file    Y1130.cpp
 * @date    2025-11-星期天
 * @version 1.0
 * @problem 1131：基因相关性
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int w[30];
string s, s2;
int main()
{
    cin >> s;
    for(int i=0;i<s.size();i++){
        w[s[i]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        if(w[s[i]-'a']==1){
            cout<<s[i];
            return 0;
        }
    }
    cout<<"no";
    return 0;
}