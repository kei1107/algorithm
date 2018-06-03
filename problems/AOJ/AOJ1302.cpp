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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1302>
 問題文============================================================
 
 N 個の物体で構成された世界がある。これらすべては, M 種類の Yes/No で答えられる特徴で区別することができる。
 あなたは, 今目の前にあるものがなんの物体であるかを調べたいのだが, 最悪の場合でもなるべく少ない質問回数で物体を判別したい。
 
 最悪の場合, 必要な質問回数を最小化せよ。ただし, 質問の答えを聞いてから次の質問を考えられることにする。

 
 =================================================================
 解説=============================================================
 
 分割統治
 
 ある桁を質問した時、 0 となる場合と 1になる場合それぞれに分けて再度考え直す。
 この時、同じ状態の質問を複数回行う可能性があるので、メモ化しておく
 ================================================================
 */

int m,n;
map<string,int> mp;
int rec(vector<string>& obj){
    if(obj.size() <= 1) return 0;
    int ret = m;
    string s; for(auto v:obj) s += v;
    if(mp.count(s)) return mp[s];
    vector<string> l,r;
    for(int i = 0; i < m;i++){
        l.clear(); r.clear();
        for(int j = 0; j < obj.size(); j++){
            if(obj[j][i] == '0') l.push_back(obj[j]);
            else r.push_back(obj[j]);
        }
        if(l.empty() || r.empty()) continue;
        ret = min(ret,1 + max(rec(l),rec(r)));
    }
    mp[s] = ret;
    return ret;
}

int solve(){
    mp.clear();
    int res = 0;
    vector<string> obj(n);
    for(auto& in:obj) cin >> in;
    res = rec(obj);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> m >> n,m|n){
        cout << solve() << endl;
    }
    return 0;
}
