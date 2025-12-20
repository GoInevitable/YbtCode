/** 
 * @author  Jane Smith
 * @file    T1_2127.cpp
 * @date    2025-12-星期六
 * @version 1.0
 * @problem 2127：【例1.2】高精度加法
 * @license MIT
 */
#include<bits/stdc++.h>
using namespace std;
char a[101], b[101];
int a1[101], b1[101], c[101];
int main() {
	int lena, lenb, lenc = 1, x = 0;
	cin >> a >> b;
	lena = strlen(a);
	lenb = strlen(b);
	for (int i = 1; i <= lena; i++) {
		a1[i] = a[lena - i] - '0';
	}
	for (int i = 1; i <= lenb; i++) {
		b1[i] = b[lenb - i] - '0';
	}
	while (lenc <= lena || lenc <= lenb) {
		c[lenc] = a1[lenc] + b1[lenc] + x;
		x = c[lenc] / 10;
		c[lenc] %= 10;
		lenc++;
	}
	c[lenc] = x;
	while (c[lenc] == 0 && lenc > 1) {
		lenc--;
	}
	for (int i = lenc; i >= 1; i--) {
		cout<<c[i];
	}
	return 0;
}