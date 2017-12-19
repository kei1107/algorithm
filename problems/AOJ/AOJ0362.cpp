#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0362>
問題文============================================================
 複数台のトランポリンが、１０ｍ間隔で直線上に設置されています。
 それぞれのトランポリンについて、水平方向に跳ぶことができる最大距離が決まっています。
 左端のトランポリンから始めて、跳ぶことができる範囲にあるトランポリンに跳び移っていきます。
 これを繰り返して、まずは右端のトランポリンまで行ってから、左端のトランポリンに戻りたいと思います。
 この間、一度もトランポリンから降りずに往復することができるでしょうか。
 
 各トランポリンで水平方向に跳ぶことができる最大距離が与えられたとき、
 左端と右端の間を往復できるかを報告するプログラムを作成せよ。
 ただし、トランポリンは大きさのない点とみなす。
=================================================================

解説=============================================================

 一度到達場所は一回だけ確認すれば良いので、全ての地点を0から貪欲探索でO(N)
 また、逆向きに見てO(N)
 
================================================================
*/
ll N;
vector<ll> d;
vector<int> used;
bool dfs(int n){
    used[n] = 1;
    for(int i = 1; i <= d[n]/10;i++){
        if(n+i == N - 1) return true;
        if(used[n+i] == 1) continue;
        if(dfs(n+i)) return true;
    }
    return false;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    d.resize(N); used.resize(N);
    for(auto& in:d) cin >> in;
    fill(used.begin(),used.end(),0);
    if(!dfs(0)){
        cout << "no" << endl;
        return 0;
    }
    fill(used.begin(),used.end(),0);
    reverse(d.begin(), d.end());
    if(!dfs(0)){
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
	return 0;
}
