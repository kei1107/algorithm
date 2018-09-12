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
 <url:https://beta.atcoder.jp/contests/abc106/tasks/abc106_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 Sの1..K文字まで全て1であれば1、そうでなければ一番最初に現れる1以外の値
 ================================================================
 */


ll solveC(){
    ll res = 0;
    string S; cin >> S; ll K; cin >> K;
    res = 1;
    ll onecnt = 0;
    for(int i = 0; S.length();i++){
        if(S[i] == '1'){
            onecnt++;
        }else{
            res = S[i] - '0';
            break;
        }
    }
    if(onecnt >= K) return 1;
    else return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solveC() << endl;
    return 0;
}