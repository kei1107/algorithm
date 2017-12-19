#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0361>
問題文============================================================
ぼくは内装職人です。今回依頼があったお客さんの家には、長方形の壁一面にパネルがぴったりと敷き詰められています。
 パネルはすべて横の長さが２ｍ、縦の長さが１ｍの長方形で、横方向にx 枚、縦方向にy 枚並んでいます。
 この壁の左上隅から右下隅まで、まっすぐ電線を張ることになりました。

 パネルの横方向と縦方向の枚数が与えられたとき、
 パネルの継ぎ目と電線の交点の数を求めるプログラムを作成せよ。
 ただし、パネルの継ぎ目の太さと電線の太さは考えないものとする。
 
=================================================================

解説=============================================================

 縦・横それぞれ独立に見たとき、縦yの時、y+1本 横は x + 1本
 縦・横で重なっている部分の数はgcd(x,y)+1個
 よって x + y + 2 - (gcd(x,y)+1) が答え
 
================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll x,y; cin >> x >> y;
    cout << x + y + 2 - (gcd(x,y) + 1) << endl;
	return 0;
}
