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
 <url:https://yukicoder.me/problems/no/265>
 問題文============================================================
 =================================================================
 解説=============================================================
 久しぶりに構文解析 + 問題文をちゃんと読んでおらず少しバグらせた
 
 構文解析するだけの問題。
 返却時のクエリとして、見ている式の各次数の係数を返してやれば良い
 ================================================================
 */

ll N;
int d;

pll getnum(int& idx,const string& S){
    pll ret;
    ret.first = 1;
    while(S[idx]=='x'||isdigit(S[idx])){
        if(S[idx] == 'x') ret.second++;
        else ret.first = S[idx] - '0';
        idx++;
        if(idx >= N) break;
        if(S[idx]=='*'){ idx++; continue;}
        break;
    }
    return ret;
}
vector<ll> rec(int& idx,const string& S){
    vector<ll> ret(d+1,0);
    for(;idx<N;){
        if(S[idx] == '}'){ idx++; break; }
        if(S[idx] == '+'){ idx++; continue; }
        if(S[idx] == 'x' || isdigit(S[idx])){
            auto p = getnum(idx, S);
            ret[p.second] += p.first;
            continue;
        }
        if(S[idx] == 'd'){
            idx+=2;
            auto tmp = rec(idx,S);
            for(int i = 0; i < d;i++) ret[i] += (i+1)*tmp[i+1];
            continue;
        }
    }
    return ret;
}
vector<ll> solve(){
    vector<ll> res;
    cin >> N >> d;
    res.resize(d+1);
    string S; cin >> S;
    int idx = 0;
    res = rec(idx,S);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
