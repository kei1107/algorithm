#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/126>
 問題文============================================================
 =================================================================
 解説=============================================================
 場合分け
 
 まず、S = 1であったり、初めからボタンを押せばAがくるような場合は、
 ボタン押してそのまま地下に行った方が良い
 
 そうで無いとき、すなわち、最初にボタンを押すとBがくるような場合は
 
 次の２パターンの行き方がある
 ・Bに乗って1階にいき、地下にいく
 ・Aが地下にいないとき、Bに乗ってAの階へいき、Aに乗って地下にいく
 
 
 逆のこれだけのパターンしかないので書けば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll A,B,S; cin >> A >> B >> S;
    if(abs(S-A) <= abs(S-B) || S==1){
        res = abs(S-A) + S;
    }else{
        res = abs(S-B) + min((S-1) + abs(A-1)+1,abs(A-S)+A + (A==0?INF:0));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
