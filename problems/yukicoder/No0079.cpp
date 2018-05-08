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
 <url:https://yukicoder.me/problems/no/79>
 問題文============================================================
 競技プログラミングの出題サイト yurucoder では問題ごとにレベルが設定されています。
 
 問題のレベルはユーザーからアンケートを取り以下のルールで決められます。
 N人のユーザーは問題のレベルをそれぞれ Li として評価する。 (1≤i≤N)
 多数決を取り、最もユーザーからの回答が多いレベルをその問題のレベルとする。
 最も多い回答を得たものが複数ある場合は、よりレベルの高い方を採用する。
 
 このルールに従い、ユーザーから得た評価から問題のレベルを求めてください。
 =================================================================
 解説=============================================================
 
 個数かぞえあげるだけ
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> L(N); for(auto& in:L) cin >> in;
    sort(L.begin(),L.end());
    ll M = -1;
    for(int i = 1; i <= 6L;i++){
        if(M <= count(L.begin(),L.end(),i)){
            M = count(L.begin(),L.end(),i);
            res = i;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
