#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a>
問題文============================================================
 文字列 S が与えられます。
 
 高橋君はこの文字列の好きな位置に好きなだけ文字 A を挿入することができます。
 
 S を AKIHABARA に変えることはできるでしょうか？
=================================================================

解説=============================================================
あらかじめ、あり得る状態の文字列の集合を用意しておき、
 入力文字がその集合に含まれるか確認すれば良い
================================================================
*/
set<string> s;

void init(string akiba){
    s.insert(akiba);
    for(int i = 0; i < (int)akiba.size();i++){
        if(akiba[i] == 'A'){
            init(akiba.substr(0,i) + akiba.substr(i+1));
        }
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    init("AKIHABARA");
    if(s.find(S) != s.end()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
